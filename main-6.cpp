/*******************************************************************************
 *  Program Name: FinalProgram
 *  Created Date: 5/1/19
 *  Created By: Shawn Sewell-Snyder
 *  Purpose: To see how effecient these sorting algorithms are
 *  Acknowledgements: None
 *******************************************************************************/

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "BubbleSort.h"
#include "HeapSort.h"

const int HUNDRED_SIZE = 100; // Max size for max100 array
const int THOUSAND_SIZE = 1000; // Max size for max1000 array
const int ARRAY_START = 0; // Start arrays at index 0

using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::endl;

typedef int ItemType;

int ReloadMax100(ifstream&, ItemType*);
int ReloadMax1000(ifstream&, ItemType*);
void Print(ofstream&, int[], int);    // Prints array
void InitValues(int[]);            // Creates random array

/*******************************************************************************
 *  Function Name: main()
 *  Parameters: None
 *  Return Value: int
 *  Purpose: Test the sorting algorithms
 *******************************************************************************/
int main() {
    try {
        ifstream Max100; // The file with 100 random ints
        ifstream Max1000; // The file with 1000 random ints
        ofstream Output; // Output file which is echo printed
        ItemType max100[HUNDRED_SIZE]; // Holds ints from Max100 file
        ItemType max1000[THOUSAND_SIZE]; // Holds ints from Max1000 file
        int swaps = 0; // Counts amount of swaps
        int comparisons = 0; // Counts amount of comparisons
        int sizeOfMax100; // Keeps track of amount of ints in max100[]
        int sizeOfMax1000; // Keeps track of amount of ints in max1000[]

        Output.open("Output.txt");
        
        // Scan in random numbers from Max100 and Max1000 text files and store them into respective arrays
        sizeOfMax100 = ReloadMax100(Max100, max100);
        sizeOfMax1000 = ReloadMax1000(Max1000, max1000);
        
        // Sort and print sorted array using bubble sort
        cout << "\n---\nBubble Sort Max100\n---\n";
        Output << "\n---\nBubble Sort Max100\n---\n";
        BubbleSort(max100, sizeOfMax100, swaps, comparisons);
        Print(Output, max100, sizeOfMax100);
        cout << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        Output << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        
        // Reset comparisons and swaps
        comparisons = 0;
        swaps = 0;
        
        // Sort and print sorted array using bubble sort
        cout << "\n---\nBubble Sort Max1000\n---\n";
        Output << "\n---\nBubble Sort Max1000\n---\n";
        BubbleSort(max1000, sizeOfMax1000, swaps, comparisons);
        Print(Output, max1000, sizeOfMax1000);
        cout << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        Output << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        
        // Close files for next sort
        Max100.close();
        Max1000.close();
        
        // Reload arrays for next sort
        ReloadMax100(Max100, max100);
        ReloadMax1000(Max1000, max1000);
        
        // Sort and print sorted array using selection sort
        cout << "\n---\nSelection Sort Max100\n---\n";
        Output << "\n---\nSelection Sort Max100\n---\n";
        SelectionSort(max100, sizeOfMax100, swaps, comparisons);
        Print(Output, max100, sizeOfMax100);
        cout << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        Output << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        
        // Reset comparisons and swaps
        comparisons = 0;
        swaps = 0;
        
        // Sort and print sorted array using selection sort
        cout << "\n---\nSelection Sort Max1000\n---\n";
        Output << "\n---\nSelection Sort Max1000\n---\n";
        SelectionSort(max1000, sizeOfMax1000, swaps, comparisons);
        Print(Output, max1000, sizeOfMax1000);
        cout << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        Output << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        
        // Close files for next sort
        Max100.close();
        Max1000.close();
        
        // Reload arrays for next sort
        ReloadMax100(Max100, max100);
        ReloadMax1000(Max1000, max1000);
        
        // Sort and print sorted array using heap sort
        cout << "\n---\nHeap Sort Max100\n---\n";
        Output << "\n---\nHeap Sort Max100\n---\n";
        HeapSort(max100, sizeOfMax100, swaps, comparisons);
        Print(Output, max100, sizeOfMax100);
        cout << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        Output << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        
        // Reset comparisons and swaps
        comparisons = 0;
        swaps = 0;
        
        // Sort and print sorted array using heap sort
        cout << "\n---\nHeap Sort Max1000\n---\n";
        Output << "\n---\nHeap Sort Max1000\n---\n";
        HeapSort(max1000, sizeOfMax1000, swaps, comparisons);
        Print(Output, max1000, sizeOfMax1000);
        cout << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        Output << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        
        // Close files for next sort
        Max100.close();
        Max1000.close();
        
        // Reload arrays for next sort
        ReloadMax100(Max100, max100);
        ReloadMax1000(Max1000, max1000);
        
        // Sort and print sorted array using insertion sort
        cout << "\n---\nInsertionSort Sort Max100\n---\n";
        Output << "\n---\nInsertionSort Sort Max100\n---\n";
        InsertionSort(max100, sizeOfMax100, swaps, comparisons);
        Print(Output, max100, sizeOfMax100);
        cout << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        Output << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        
        // Reset comparisons and swaps
        comparisons = 0;
        swaps = 0;
        
        // Sort and print sorted array using insertion sort
        cout << "\n---\nInsertionSort Sort Max1000\n---\n";
        Output << "\n---\nInsertionSort Sort Max1000\n---\n";
        InsertionSort(max1000, sizeOfMax1000, swaps, comparisons);
        Print(Output, max1000, sizeOfMax1000);
        cout << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        Output << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        
        // Close files for next sort
        Max100.close();
        Max1000.close();
        
        // Reload arrays for next sort
        ReloadMax100(Max100, max100);
        ReloadMax1000(Max1000, max1000);
        
        // Sort and print sorted array using quick sort
        cout << "\n---\nQuickSort Sort Max100\n---\n";
        Output << "\n---\nQuickSort Sort Max100\n---\n";
        QuickSort(max100, ARRAY_START, sizeOfMax100 - 1, swaps, comparisons);
        Print(Output, max100, sizeOfMax100);
        cout << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        Output << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        
        // Reset comparisons and swaps
        comparisons = 0;
        swaps = 0;
        
        // Sort and print sorted array using quick sort
        cout << "\n---\nQuickSort Sort Max1000\n---\n";
        Output << "\n---\nQuickSort Sort Max1000\n---\n";
        QuickSort(max1000, ARRAY_START, sizeOfMax1000, swaps, comparisons);
        Print(Output, max1000, sizeOfMax1000);
        cout << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        Output << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        
        // Close files for next sort
        Max100.close();
        Max1000.close();
        
        // Reload arrays for next sort
        ReloadMax100(Max100, max100);
        ReloadMax1000(Max1000, max1000);
        
        // Sort and print sorted array using merge sort
        cout << "\n---\nMergeSort Sort Max100\n---\n";
        Output << "\n---\nMergeSort Sort Max100\n---\n";
        MergeSort(max100, ARRAY_START, sizeOfMax100, swaps, comparisons);
        Print(Output, max100, sizeOfMax100);
        cout << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        Output << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        
        // Reset comparisons and swaps
        comparisons = 0;
        swaps = 0;
        
        // Sort and print sorted array using merge sort
        cout << "\n---\nMergeSort Sort Max1000\n---\n";
        Output << "\n---\nMergeSort Sort Max1000\n---\n";
        MergeSort(max1000, ARRAY_START, sizeOfMax1000 - 1, swaps, comparisons);
        Print(Output, max1000, sizeOfMax1000);
        cout << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        Output << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << "\n---\n\n";
        
        // Close files
        Max100.close();
        Max1000.close();
        Output.close();
        
    } catch (std::exception &ex) { std::cerr << "\nSomething went wrong...\n"; }
    return 0;
}

/*******************************************************************************
 *  Function Name: Print
 *  Parameters: ofstream&, int[], int
 *  Return Value: void
 *  Purpose: Print items in array
 *******************************************************************************/
void Print(ofstream& outFile, int values[], int size)
{
    using namespace std;
    for (int count = 0; count < size; count= count+10) {
        outFile << values[count]  << ", " << values[count+1] << ", " << values[count+2] << ", "
        << values[count+3] << ", " << values[count+4] << ", " << values[count+5] << ", "
        << values[count+6] << ", " << values[count + 7] << ", " << values[count + 8]
        << ", " << values[count+9] << endl << endl;
    
        cout << values[count]  << ", " << values[count+1] << ", " << values[count+2] << ", "
        << values[count+3] << ", " << values[count+4] << ", " << values[count+5] << ", "
        << values[count+6] << ", " << values[count + 7] << ", " << values[count + 8]
        << ", " << values[count+9] << endl << endl;
    }
}

/*******************************************************************************
 *  Function Name: ReloadMax100
 *  Parameters: ifstream&, ItemType
 *  Return Value: int
 *  Purpose: Load in numbers from Max100 file and return amount of interegers scanned in
 *******************************************************************************/
int ReloadMax100(ifstream &Max100, ItemType max100[]) {
    Max100.open("Max100.txt");
    
    int counter = 0;
    while(Max100 >> max100[counter])
        counter++;
    return counter;
}

/*******************************************************************************
 *  Function Name: ReloadMax1000
 *  Parameters: ifstream&, ItemType
 *  Return Value: int
 *  Purpose: Load in numbers from Max1000 file and return amount of interegers scanned in
 *******************************************************************************/
int ReloadMax1000(ifstream &Max1000, ItemType max1000[]) {
    Max1000.open("Max1000.txt");
    
    int counter = 0;
    while(Max1000 >> max1000[counter])
        counter++;
    return counter;
}
