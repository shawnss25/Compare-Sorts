#ifndef MergeSort_h
#define MergeSort_h

#include "Swap.h"
const int SIZE = 1000;
typedef int ItemType;

template<class ItemType>
void Merge (ItemType values[], int leftFirst, int leftLast,
            int rightFirst, int rightLast, int &swaps, int &comparisons)
// Post: values[leftFirst]..values[leftLast] and
//       values[rightFirst]..values[rightLast] have been merged.
//       values[leftFirst]..values[rightLast] is now sorted.
{
    ItemType tempArray[SIZE];
    int index = leftFirst;
    int saveFirst = leftFirst;
    
    comparisons++;
    while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
    {
        comparisons++;
        if (values[leftFirst] < values[rightFirst])
        {
            tempArray[index] = values[leftFirst];
            leftFirst++;
            swaps++;
        }
        else
        {
            tempArray[index] = values[rightFirst];
            rightFirst++;
            swaps++;
        }
        index++;
    }
    
    comparisons++;
    while (leftFirst <= leftLast)
        // Copy remaining items from left half.
        
    {
        tempArray[index] = values[leftFirst];
        leftFirst++;
        index++;
        swaps++;
    }
    
    comparisons++;
    while (rightFirst <= rightLast)
        // Copy remaining items from right half.
    {
        tempArray[index] = values[rightFirst];
        rightFirst++;
        index++;
        swaps++;
    }
    
    for (index = saveFirst; index <= rightLast; index++) {
        values[index] = tempArray[index];
        swaps++;
    }
}
template<class ItemType>
void MergeSort(ItemType values[], int first, int last, int &swaps, int &comparisons)
// Post: The elements in values are sorted by key.
{
    comparisons++;
    if (first < last)
    {
        int middle = (first + last) / 2;
        MergeSort(values, first, middle, swaps, comparisons);
        MergeSort(values, middle + 1, last, swaps, comparisons);
        Merge(values, first, middle, middle + 1, last, swaps, comparisons);
    }
}

#endif /* MergeSort_h */
