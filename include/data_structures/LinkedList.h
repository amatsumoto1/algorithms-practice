#ifndef LINKED_LIST_H
#define LINKED_LIST_H


namespace DataStructures {

template<typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    operator std::string() const;

    int GetSize() const;
    void Add(T value);
    bool Add(T value, int location);
    bool Contains(T value) const;
    bool RemoveAt(int index);
    bool Remove(T value);
    void Set(int index, T value);
private:
    struct Node {
        public:
            Node(T value, Node* next = nullptr)
            : value_(value), next_(next) {}

            T value_;
            Node* next_;
    };

    Node* getNodeAt(int index);

    Node* head_;
    int size_;
};

template<typename T>
inline
void Add(T value, int location) {
    Node* addedNode = nullptr;
    if (location == 0) {
        addedNode = new Node(value, head_);
        head_ = addedNode;
    }
    else {
        Node* n = head_;
        for (int i = 1; i < location; i++) {
            if (n != nullptr) {
                n = n->next;
            }
        }
    }
}

}

#include "inl/LinkedList.inl";

#endif