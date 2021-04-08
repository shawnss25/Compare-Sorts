#ifndef InsertionSort_h
#define InsertionSort_h

#include "Swap.h"

typedef int ItemType;

template<class ItemType>
void InsertItem(ItemType values[], int startIndex, int
                endIndex, int &swaps, int &comparisons)
// Post: values[0]..values[endIndex] are now sorted.
{
    bool finished = false;
    int current = endIndex;
    bool moreToSearch = (current != startIndex);
    
    while (moreToSearch && !finished)
    {
        comparisons++;
        if (values[current] < values[current-1])
        {
            Swap(values[current], values[current-1]);
            current--;
            moreToSearch = (current != startIndex);
            swaps++;
        }
        else
            finished = true;
    }
}

template<class ItemType>
void InsertionSort(ItemType values[], int numValues, int &swaps, int &comparisons)
// Post: The elements in the array values are sorted by key.
{
    for (int count = 0; count < numValues; count++)
        InsertItem(values, 0, count, swaps, comparisons);
}

#endif /* InsertionSort_h */
