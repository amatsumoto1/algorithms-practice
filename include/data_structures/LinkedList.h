#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace DataStructures {
template<typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    T& operator[](int index);


    int GetSize() const;
    void AddFront(T value);
    void Append(T value);
    bool Insert(T value, int location);
    bool Contains(T value) const;
    T PopFront();
    bool Remove(T value);
    bool RemoveAt(int index);
private:
    struct Node {
        public:
            Node(T value, Node* next = nullptr)
            : value_(value), next_(next) {}

            T value_;
            Node* next_;
    };

    Node* head_;
    int size_;
};

}

#include "inl/LinkedList.inl"

#endif