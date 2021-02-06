namespace DataStructures {

template<typename T>
inline 
LinkedList<T>::LinkedList()
    : head_(nullptr),
      size_(0)
{}

template<typename T>
inline
LinkedList<T>::~LinkedList() {
    while (head_ != nullptr) {
        Node* next = head->next_;
        delete head_;
        head_ = next;
    }
}

template<typename T>
inline
int LinkedList<T>::GetSize() const {
    return size_;
}

template<typename T>
inline
void LinkedList<T>::Add(T value) {
    Node* addedNode = new Node(value);
    if (head_ == nullptr) {
        head_ = addedNode;
    }
    else {
        Node* end = head_;
        while (end->next != nullptr) {
            end = end->next;
        }
        end->next = addedNode;
    }
    size_++;
}

}