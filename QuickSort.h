#ifndef QuickSort_h
#define QuickSort_h

#include "Swap.h"

typedef int ItemType;

template <class ItemType>
void Split(ItemType values[], int first, int last, int& splitPoint, int &swaps, int &comparisons)
{
    ItemType splitVal = values[first];
    int saveFirst = first;
    bool onCorrectSide;
    
    first++;
    do
    {
        onCorrectSide = true;
        while (onCorrectSide) {         // Move first toward last.
            comparisons++;
            if (values[first] > splitVal)
                onCorrectSide = false;
            else
            {
                first++;
                onCorrectSide = (first <= last);
            }
        }
        comparisons++;
        onCorrectSide = (first <= last);
        while (onCorrectSide) {             // Move last toward first.
            if (values[last] <= splitVal)
                onCorrectSide = false;
            else
            {
                last--;
                onCorrectSide = (first <= last);
            }
        }
        comparisons++;
        if (first < last)
        {
            Swap(values[first], values[last]);
            swaps++;
            first++;
            last--;
        }
    comparisons++;
    } while (first <= last);
    
    splitPoint = last;
    Swap(values[saveFirst], values[splitPoint]);
    swaps++;
}


template<class ItemType>
void QuickSort(ItemType values[], int first, int last, int &swaps, int &comparisons)
{
    comparisons++;
    if (first < last)
    {
        int splitPoint;
        
        Split(values, first, last, splitPoint, swaps, comparisons);
        // values[first]..values[splitPoint-1] <= splitVal
        // values[splitPoint] = splitVal
        // values[splitPoint+1]..values[last] > splitVal
        
        QuickSort(values, first, splitPoint-1, swaps, comparisons);
        QuickSort(values, splitPoint+1, last, swaps, comparisons);
    }
}


#endif /* QuickSort_h */
