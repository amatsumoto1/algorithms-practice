#include <exception>
#include <cstdlib>
#include <iostream>

namespace DataStructures {

template<typename T>
Heap<T>::Heap(bool isMax)
 : array_(nullptr),
   size_(0),
   capacity_(DEFAULT_INITIAL_CAPACITY),
   isMax_(isMax)
{
    array_ = new T[DEFAULT_INITIAL_CAPACITY];
}

template<typename T>
Heap<T>::~Heap() {
    if (array_ != nullptr) {
        delete array_;
    }
}

template<typename T>
int Heap<T>::GetSize() const {
    return size_;
}

template<typename T>
bool Heap<T>::IsMax() const {
    return isMax_;
}

template<typename T>
T Heap<T>::Peek() {
    if (size_ == 0) {
        throw std::out_of_range("Cannot peek from empty heap");
    }

    return array_[0];
}

template<typename T>
void Heap<T>::Push(T value) {
    // If the heap is at full capacity, then double the capacity.
    if (size_ == capacity_) {
        capacity_ *= 2;
        T* resized = new T[capacity_];
        memcpy(resized, array_, size_ * sizeof(T));
        delete array_;
        array_ = resized;
    }

    array_[size_] = value;
    size_++;
    BubbleUp(size_ - 1);
}

template<typename T>
T Heap<T>::Pop() {
    if (size_ == 0) {
        throw std::out_of_range("Cannot pop from empty heap");
    }

    T retVal = array_[0];

    array_[0] = array_[size_ - 1];
    size_--;
    BubbleDown(0);
    return retVal;
}

template<typename T>
void Heap<T>::BubbleUp(int index) {
    int child = index;
    int parent = (index - 1) / 2;

    while(child != 0 && ComparePriorities(child, parent)) {
        Swap(child, parent);
        child = parent;
        parent = (child - 1)/2;
    }
}

template<typename T>
void Heap<T>::BubbleDown(int index) {
    while (2 * index + 1 < size_) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int maxChild = leftChild;
        if (rightChild < size_ && ComparePriorities(rightChild, leftChild)) {
            maxChild = rightChild;
        }
        if (ComparePriorities(maxChild, index)) {
            Swap(index, maxChild);
            index = maxChild;
        }
        else {
            break;
        }
    }
}

template<typename T>
inline
void Heap<T>::Swap(int index1, int index2) {
    T temp = array_[index2];
    array_[index2] = array_[index1];
    array_[index1] = temp;
}

template<typename T>
inline
bool Heap<T>::ComparePriorities(int index1, int index2) {
    return (isMax_) ? array_[index1] > array_[index2] : array_[index1] < array_[index2];
}

}