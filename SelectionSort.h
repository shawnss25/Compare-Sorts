#ifndef SelectionSort_h
#define SelectionSort_h

#include "Swap.h"

typedef int ItemType;

template<class ItemType>
int MinIndex(ItemType values[], int startIndex, int endIndex, int &comparisons)
// Post: Returns the index of the smallest value in
//       values[startIndex]..values[endIndex].
{
    int indexOfMin = startIndex;
    for (int index = startIndex + 1; index <= endIndex; index++)
        if (values[index] < values[indexOfMin]) {
            indexOfMin = index;
            comparisons++;
        }
    return indexOfMin;
}

template<class ItemType>
void SelectionSort(ItemType values[], int numValues, int &swaps, int &comparisons)
// Post: The elements in the array values are sorted by key.
{
    int endIndex = numValues-1;
    for (int current = 0; current < endIndex; current++) {
        Swap(values[current], values[MinIndex(values, current, endIndex, comparisons)]);
        swaps++;
    }
}
#endif /* SelectionSort_h */
