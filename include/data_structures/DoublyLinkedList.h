#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace DataStructures {

// A doubly linked list.
template<typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Accesses the element at the given index. If the index is invalid, throws
    // an out_of_bounds exception.
    T& operator[](int index);
    
    int GetSize() const;
    // Adds value to the front of the list.
    void AddFront(T value);
    // Adds value to the end of the list.
    void Append(T value);
    // Inserts value at the given location. If the location is invalid,
    // return false, otherwise true.
    bool Insert(T value, int location);
    bool Contains(T value) const;
    // Removes the first element from the list and returns it. If there is no
    // element to return, throws an out_of_bounds exception.
    T PopFront();
    // Removes the last element from the list and returns it. If there is no
    // element to return, throws an out_of_bounds exception.
    T PopBack();
    // Removes the first element from the list with the given value. Returns
    // whether there was an element removed.
    bool Remove(T value);
    // Removes an element with the given index. Returns whether the index
    // to remove at was valid.
    bool RemoveAt(int index);
    // Reverses the elements of this doubly linked list.
    void Reverse();
private:
    struct Node {
        T value;
        Node* prev;
        Node* next;
        
        Node(T value) : value(value), prev(nullptr), next(nullptr) {}


    };

    Node* GetNodeAt(int index) {
        Node* current;
        if (index > size_ / 2) {
            current = head_;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
        }
        else {
            current = tail_;
            for (int i = size_ - 1; i > index; i--) {
                current = current->prev;
            }
        }

        return current;
    }

    Node* head_;
    Node* tail_;
    int size_;
};

}

#include "inl/DoublyLinkedList.inl"

#endif