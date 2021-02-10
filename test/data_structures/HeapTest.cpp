#include <gtest/gtest.h>

#include <Heap.h>

namespace DataStructures {

    TEST(HeapTest, Constructor) {
        Heap<int> heap;

        EXPECT_EQ(heap.GetSize(), 0);
        EXPECT_TRUE(heap.IsMax());
        EXPECT_THROW(heap.Peek(), std::out_of_range);
    }

    TEST(HeapTest, Push) {
        Heap<int> maxHeap;
        maxHeap.Push(20);
        EXPECT_EQ(maxHeap.Peek(), 20);
        EXPECT_EQ(maxHeap.GetSize(), 1);
        maxHeap.Push(55);
        EXPECT_EQ(maxHeap.Peek(), 55);
        EXPECT_EQ(maxHeap.GetSize(), 2);
        maxHeap.Push(-4);
        EXPECT_EQ(maxHeap.Peek(), 55);
        EXPECT_EQ(maxHeap.GetSize(), 3);

        Heap<int> minHeap(false);
        minHeap.Push(12);
        EXPECT_EQ(minHeap.Peek(), 12);
        EXPECT_EQ(minHeap.GetSize(), 1);
        minHeap.Push(-4);
        EXPECT_EQ(minHeap.Peek(), -4);
        EXPECT_EQ(minHeap.GetSize(), 2);
        minHeap.Push(20);
        EXPECT_EQ(minHeap.Peek(), -4);
        EXPECT_EQ(minHeap.GetSize(), 3);
    }

    TEST(HeapTest, Pop) {
        Heap<int> maxHeap;
        Heap<int> minHeap(false);

        EXPECT_THROW(maxHeap.Pop(), std::out_of_range);
        for (int i = 0; i <= 9; i++) {
            maxHeap.Push(9 - i);
            minHeap.Push(i);
        }

        for (int i = 0; i <= 9; i++) {
            EXPECT_EQ(maxHeap.Pop(), 9 - i);
            EXPECT_EQ(maxHeap.GetSize(), 9 - i);
            EXPECT_EQ(minHeap.Pop(), i);
            EXPECT_EQ(minHeap.GetSize(), 9 - i);
        }
    }
}