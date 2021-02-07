#include "gtest/gtest.h"

#include "LinkedList.h"

namespace DataStructures {

TEST(LinkedListTests, Constructor) {
	LinkedList<int> list;
	ASSERT_EQ(list.GetSize(), 0);
}

}