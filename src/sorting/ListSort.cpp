#include "ListSort.h"

#include <algorithm>
#include <cstring>
#include <climits>

namespace Sorting {

void Swap(int* array, int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void SelectionSort(int* array, int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            Swap(array, i, minIndex);
        }
    }
}

void InsertionSort(int* array, int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j >= 1 && array[j] <= array[j - 1]) {
            Swap(array, j, j - 1);
            j--;
        }
    }
}

void BubbleSort(int* array, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                Swap(array, j, j + 1);
            }
        }
    }
}

void Merge(int* array1, int n1, int* array2, int n2, int* ret) {
    int i = 0, j = 0, pos = 0;
    while (i != n1 || j != n2) {
        if (i == n1) {
            ret[pos] = array2[j];
            j++;
        }
        else if (j == n2) {
            ret[pos] = array1[i];
            i++;
        }
        else if (array1[i] < array2[j]) {
            ret[pos] = array1[i];
            i++;
        }
        else {
            ret[pos] = array2[j];
            j++;
        }
        pos++;
    }
}


void MergeSort(int* array, int n) {
    if (n < 2) {
        return;
    }

    int* array1 = new int[n/2];
    int* array2 = new int[n - n/2];
    memcpy(array1, array, (n/2) * sizeof(int));
    memcpy(array2, array + (n/2), (n - n/2) * sizeof(int));
    MergeSort(array1, n/2);
    MergeSort(array2, n-n/2);
    Merge(array1, n/2, array2, n-n/2, array);
    if (array1 != nullptr) delete[] array1;
    if (array2 != nullptr) delete[] array2;
}

int Partition(int* array, int n) {
    int pivot = array[n - 1];
    int i = -1, j = n - 1;
    for (int j = 0; j < n - 1; j++) {
        if (array[j] < pivot) {
            i++;
            Swap(array, i, j);
        }
    }
    if (array[i + 1] > array[n - 1]) {
        Swap(array, i + 1, n - 1);
    }
    return i + 1;
}

void QuickSort(int* array, int n) {
    if (n == 0) {
        return;
    }
        
    //Partitions list so, list[0..pi - 1] < list[pi] < list[p-1,...n-1]
    int pi = Partition(array, n);
    //Recursively sort both partitions of list.
    QuickSort(array, pi);
    QuickSort(array + pi + 1, n - pi - 1);
}

void BubbleDown(int* array, int start, int end) {
    int index = start;
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;
    while (leftChild <= end) {
        int maxChild = leftChild;
        if (rightChild <= end && array[leftChild] < array[rightChild]) {
            maxChild = rightChild;
        }

        if (array[index] < array[maxChild]) {
            Swap(array, index, maxChild);
            index = maxChild;
            leftChild = 2*index + 1;
            rightChild = 2*index + 2;
        }
        else {
            return;
        }
    }
}

void Heapify(int* array, int n) {
    for (int index = n-1; index >= 0; index--) {
        BubbleDown(array, index, n-1);
    }
}

void HeapSort(int* array, int n) {
    Heapify(array, n);

    for (int i = n-1; i > 0; i--) {
        Swap(array, 0, i);
        BubbleDown(array, 0, i-1);
    }
}

}