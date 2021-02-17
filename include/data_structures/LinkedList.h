#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace DataStructures {

// Singly linked list.
template<typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();

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
    // Removes the first element from the list with the given value. Returns
    // whether there was an element removed.
    bool Remove(T value);
    // Removes an element with the given index. Returns whether the index
    // to remove at was valid.
    bool RemoveAt(int index);
    // Reverses the elements of this singly linked list.
    void Reverse();
private:
    struct Node {
        T value;
        Node* next;

        Node(T value, Node* next = nullptr) : value(value), next(next) {}
    };

    Node* head_;
    int size_;
};

}

#include "inl/LinkedList.inl"

#endif