//==========================================================
//
// Title:      Ninja Coders
// Course:     CSC 1101
// Lab Number: 14
// Author:     Jacob Wahlgren
// Date:       20230710
// Description:
//   Write a C++ console application that finds the second smallest number in an array.
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

// prototypes
int getSecondSmallest(int arr[], int size);

int main()
{
    // constant declaration
    const int ARRAY_SIZE = 6;
    const int COL_ONE = 40;
    const int COL_TWO = 1;
    
    // variable declaration
    int arr[ARRAY_SIZE];
    int arrInput;
    
    // welcome message
    cout << "Welcome to Ninja Codes\n----------------------\n" << endl;
    
    cout << "Please enter the numbers..." << endl;
    
    for ( int i = 0; i < ARRAY_SIZE; i++ ) {
        cin >> arrInput;
        arr[i] = arrInput;
    }
    
    cout << setw(COL_ONE) << left << "Array:";
    
    for ( int i = 0; i < ARRAY_SIZE; i++ ) {
        cout << setw(COL_TWO) << right << arr[i] << " ";
    }
    
    // skip a line
    cout << endl;
    
    cout << setw(COL_ONE) << left << "Second smallest number:";
    cout << setw(COL_TWO) << right << "  " << getSecondSmallest(arr, ARRAY_SIZE) << endl;
    
    // ending message
    cout << "\nEnd of Ninja coder\n\n-----------------------\n";
    return 0;
}

int getSecondSmallest(int arr[], int size) {
    // variable declaration
    int minVal = arr[0];
    int minIndex;
    
    minIndex = 0;
    
    for ( int i = 0; i < size; i++ ) {
        if ( minVal > arr[i] ) {
            minVal = arr[i]; // min
            minIndex = i;
        }
    }
    
    for ( int i = 0; i < size; i++ ) {
        arr[minIndex] = '\0';
        for ( int j = 0; j < size; j++ ){
            if ( minVal == arr[j] ) {
                return minVal;
            }
        }
        ++minVal;

    }
    return minVal;
}
