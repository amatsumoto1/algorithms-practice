#ifndef HEAP_H
#define HEAP_H

namespace DataStructures {

template <typename T>
class Heap {
public:
    Heap(bool isMax=true);
    ~Heap();

    int GetSize() const;
    T Peek();
    void Push(T value);
    T Pop();

private:
    void BubbleUp(int index);
    void BubbleDown(int index);

    T* array_;
    int size_;
    int capacity_;
};

}

#endif