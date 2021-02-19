#include "gtest/gtest.h"

#include "ListSort.h"

namespace Sorting {

    TEST(ListSortingTests, SelectionSort) {
        int array[10] = { 0 };
        for (int i = 0; i < 10; i++) {
            array[i] = 9-i;
        }
        SelectionSort(array, 10);
        for (int i = 0; i < 10; i++) {
            EXPECT_EQ(array[i], i);
        }
    }

    TEST(ListSortingTests, InsertionSort) {
        int array[10] = { 0 };
        for (int i = 0; i < 10; i++) {
            array[i] = 9-i;
        }
        InsertionSort(array, 10);
        for (int i = 0; i < 10; i++) {
            EXPECT_EQ(array[i], i);
        }
    }

    TEST(ListSortingTests, BubbleSort) {
        int array[10] = { 0 };
        for (int i = 0; i < 10; i++) {
            array[i] = 9-i;
        }
        BubbleSort(array, 10);
        for (int i = 0; i < 10; i++) {
            EXPECT_EQ(array[i], i);
        }
    }

    TEST(ListSortingTests, MergeSort) {
        int array[10] = { 0 };
        for (int i = 0; i < 10; i++) {
            array[i] = 9-i;
        }
        MergeSort(array, 10);
        for (int i = 0; i < 10; i++) {
            EXPECT_EQ(array[i], i);
        }
    }

    TEST(ListSortingTests, QuickSort) {
        int array[10] = { 0 };
        for (int i = 0; i < 10; i++) {
            array[i] = 9-i;
        }
        QuickSort(array, 10);
        for (int i = 0; i < 10; i++) {
            EXPECT_EQ(array[i], i);
        }
    }

    TEST(ListSortingTests, HeapSort) {
        int array[10] = { 0 };
        for (int i = 0; i < 10; i++) {
            array[i] = 9-i;
        }
        HeapSort(array, 10);
        for (int i = 0; i < 10; i++) {
            EXPECT_EQ(array[i], i);
        }
    }
}