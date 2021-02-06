#include "gtest/gtest.h"

#include "LinkedList.h"

namespace DataStructures {

TEST(LinkedListTests, constructor) 
    LinkedList<int> list;

    EXPECT_EQ(list.GetSize(), 0);
)
}