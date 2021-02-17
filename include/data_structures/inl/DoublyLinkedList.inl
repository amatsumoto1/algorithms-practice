#include <exception>

namespace DataStructures {

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
    : head_(nullptr),
      tail_(nullptr),
      size_(0)
{}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (head_ != nullptr) {
        Node* current = head_->next;
        delete head_;
        head_ = current;
    }
}

template<typename T>
int DoublyLinkedList<T>::GetSize() const {
    return size_;
}

template<typename T>
T& DoublyLinkedList<T>::operator[] (int index) {
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return GetNodeAt(index)->value;
}

template<typename T>
void DoublyLinkedList<T>::AddFront(T value) {
    Node* newNode = new Node(value);
    newNode->next = head_;
    if (head_ != nullptr) {
        head_->prev = newNode;
    }
    else {
        tail_ = newNode;
    }
    head_ = newNode;
    size_++;
}

template<typename T>
void DoublyLinkedList<T>::Append(T value) {
    Node* newNode = new Node(value);
    newNode->prev = tail_;
    if (tail_ != nullptr) {
        tail_->next = newNode;
    }
    else {
        head_ = newNode;
    }
    tail_ = newNode;
    size_++;
}

template<typename T>
bool DoublyLinkedList<T>::Insert(T value, int index) {
    if (index > size_ || index < 0) {
        return false;
    }

    if (index == 0) {
        AddFront(value);
    }
    else if (index == size_) {
        Append(value);
    }
    else {
        Node* current = GetNodeAt(index);
        Node* newNode = new Node(value);
        newNode->prev = current->prev;
        current->prev = newNode;
        newNode->prev->next = newNode;
        newNode->next = current;
        size_++;
    }

    return true;
}

template<typename T>
bool DoublyLinkedList<T>::Contains(T value) const {
    Node* current = head_;
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }

    return false;
}

template<typename T>
T DoublyLinkedList<T>::PopFront() {
    if (size_ == 0) {
        throw std::out_of_range("Cannot remove first item from empty list.");
    }

    Node* temp = head_;
    T retVal = head_->value;
    
    head_ = temp->next;
    if (head_ != nullptr) {
        head_->prev = nullptr;
    }
    else {
        tail_ = nullptr;
    }

    size_--;
    delete temp;
    return retVal;
}

template<typename T>
T DoublyLinkedList<T>::PopBack() {
    if (size_ == 0) {
        throw std::out_of_range("Cannot remove last item from empty list.");
    }

    Node* temp = tail_;
    T retVal = tail_->value;
    
    tail_ = temp->prev;
    if (tail_ != nullptr) {
        tail_->next = nullptr;
    }
    else {
        head_ = nullptr;
    }

    size_--;
    delete temp;
    return retVal;
}

template<typename T>
bool DoublyLinkedList<T>::Remove(T value) {
    Node* current = head_;
    while (current != nullptr) {
        if (current->value == value) {
            if (current == head_) {
                head_ = current->next;
            }
            else {
                current->prev->next = current->next;
            }

            if (current == tail_) {
                tail_ = current->prev;
            }
            else {
                current->next->prev = current->prev;
            }
            size_--;
            delete current;
            return true;
        }

        current = current->next;
    }

    return false;
}

template<typename T>
bool DoublyLinkedList<T>::RemoveAt(int index) {
    if (index >= size_ || index < 0) {
        return false;
    }

    Node* temp = GetNodeAt(index);
    
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    else {
        head_ = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    else {
        tail_ = temp->prev;
    }

    size_--;
    delete temp;
    return true;
}

template <typename T>
void DoublyLinkedList<T>::Reverse() {
    if (size_ == 0) {
        return;
    }

    Node* newTail = head_;
    Node* newHead = head_;
    Node* current = head_->next;
    while (current != nullptr) {
        Node* temp = current->next;
        current->next = newHead;
        newHead->prev = current;
        newHead = current;
        current = temp;
    }
    newHead->prev = nullptr;
    newTail->next = nullptr;
    head_ = newHead;
    tail_ = newTail;
}

}