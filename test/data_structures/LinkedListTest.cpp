#include "gtest/gtest.h"

#include "LinkedList.h"

namespace DataStructures {

TEST(LinkedListTests, Constructor) {
	LinkedList<int> list;
	ASSERT_EQ(list.GetSize(), 0);
}

TEST(LinkedListTests, AddFront) {
    LinkedList<int> list;
    list.AddFront(1);
    list.AddFront(2);
    list.AddFront(3);
    ASSERT_EQ(list.GetSize(), 3);
    EXPECT_EQ(list[0], 3);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 1);
}

TEST(LinkedListTests, Append) {
    LinkedList<int> list;
    list.Append(1);
    list.Append(2);
    list.Append(3);
    ASSERT_EQ(list.GetSize(), 3);
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 3);
}

TEST(LinkedListTests, Set) {
    LinkedList<int> list;
    list.AddFront(0);
    list.AddFront(0);
    list.AddFront(0);
    list[2] = 3;
    list[0] = -1;
    EXPECT_EQ(list[0], -1);
    EXPECT_EQ(list[1], 0);
    EXPECT_EQ(list[2], 3);
}

TEST(LinkedListTests, Insert) {
    LinkedList<int> list;
    EXPECT_FALSE(list.Insert(4, 2));
    EXPECT_TRUE(list.Insert(2, 0));
    EXPECT_TRUE(list.Insert(3, 0));
    EXPECT_TRUE(list.Insert(5, 2));
    EXPECT_TRUE(list.Insert(7, 1));
    EXPECT_FALSE(list.Insert(8, -1));
    EXPECT_EQ(list.GetSize(), 4);
    EXPECT_EQ(list[0], 3);
    EXPECT_EQ(list[1], 7);
    EXPECT_EQ(list[2], 2);
    EXPECT_EQ(list[3], 5);
}

TEST(LinkedListTests, Contains) {
    LinkedList<int> list;
    EXPECT_FALSE(list.Contains(4));
    list.AddFront(0);
    list.AddFront(1);
    EXPECT_TRUE(list.Contains(0));
    EXPECT_TRUE(list.Contains(1));
    EXPECT_FALSE(list.Contains(2));
}

TEST(LinkedListTests, PopFront) {
    LinkedList<int> list;
    list.AddFront(2);
    list.AddFront(1);
    EXPECT_EQ(list.PopFront(), 1);
    EXPECT_EQ(list.GetSize(), 1);
    EXPECT_EQ(list[0], 2);
    EXPECT_EQ(list.PopFront(), 2);
    EXPECT_EQ(list.GetSize(), 0);
}

TEST(LinkedListTests, Remove) {
    LinkedList<int> list;
    EXPECT_FALSE(list.Remove(0));
    list.AddFront(0);
    list.AddFront(1);
    list.AddFront(2);
    EXPECT_FALSE(list.Remove(4));
    EXPECT_TRUE(list.Remove(1));
    EXPECT_EQ(list.GetSize(), 2);
    EXPECT_EQ(list[0], 2);
    EXPECT_EQ(list[1], 0);
    EXPECT_TRUE(list.Remove(2));
    EXPECT_EQ(list.GetSize(), 1);
    EXPECT_EQ(list[0], 0);
}

TEST(LinkedListTests, RemoveAt) {
    LinkedList<int> list;
    EXPECT_FALSE(list.RemoveAt(0));
    list.AddFront(2);
    list.AddFront(3);
    list.AddFront(4);
    EXPECT_FALSE(list.RemoveAt(4));
    EXPECT_FALSE(list.RemoveAt(-1));
    EXPECT_TRUE(list.RemoveAt(1));
    EXPECT_EQ(list.GetSize(), 2);
    EXPECT_EQ(list[0], 4);
    EXPECT_EQ(list[1], 2);
    EXPECT_TRUE(list.RemoveAt(0));
    EXPECT_EQ(list.GetSize(), 1);
    EXPECT_EQ(list[0], 2);
}

TEST(LinkedListTests, Reverse) {
    LinkedList<int> list;
    for (int i = 0; i < 10; i++) {
        list.Append(i);
    }
    list.Reverse();
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(list[i], 9 - i);
    }
}

}