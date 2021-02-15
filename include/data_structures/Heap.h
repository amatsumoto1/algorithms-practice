#ifndef HEAP_H
#define HEAP_H

namespace DataStructures {

// Heap implementation.
template <typename T>
class Heap {
public:
    Heap(bool isMax=true);
    ~Heap();

    int GetSize() const;
    bool IsMax() const;
    T Peek();
    void Push(T value);
    T Pop();

private:
    void BubbleUp(int index);
    void BubbleDown(int index);
    void Swap(int index1, int index2);
    bool ComparePriorities(int index1, int index2);

    T* array_;
    int size_;
    int capacity_;
    int isMax_;

    static const int DEFAULT_INITIAL_CAPACITY = 10;
};

}

#include "inl/Heap.inl"

#endif