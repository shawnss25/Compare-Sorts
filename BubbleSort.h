#ifndef BubbleSort_h
#define BubbleSort_h

#include "Swap.h"
typedef int ItemType;


template<class ItemType>
void BubbleUp(ItemType values[], int startIndex, int endIndex, int &swaps, int &comparisons)
// Post: Adjacent pairs that are out of order have been
//       switched between values[startIndex]..values[endIndex]
//       beginning at values[endIndex].
{
    for (int index = endIndex; index > startIndex; index--)
        if (values[index] < values[index-1]) {
            Swap(values[index], values[index-1]);
            swaps++;
        }
    comparisons++;
}

template<class ItemType>
void BubbleSort(ItemType values[], int numValues, int &swaps, int &comparisons)
// Post: The elements in the array values are sorted by key.
{
    int current = 0;
    
    while (current < numValues - 1)
    {
        BubbleUp(values, current, numValues-1, comparisons, swaps);
        current++;
    }
}

#endif /* BubbleSort_h */
