//==========================================================
//
// Title:      Part Pretenders
// Course:     CSC 1101
// Lab Number: 19
// Author:     Jacob Wahlgren
// Date:       20230726
// Description:
//   You've been hired by Part Pretenders to write a C++ console application that manages car parts.
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"
// constants
const int SENTINEL = 9;
const int ARRSIZE = 8;

//prototypes
int binarySearchParts( string parts[], int arraySize, string key );
void listParts( string parts[], int arrraySize );
void searchParts( string parts[], int arraySize );
void sortParts( string parts[], int arraySize );
int menuOption( void );

int main()
{
    string parts[ARRSIZE] = { "wheel", "steering-wheel", "door", "headlight", "transmission", "brake-lights", "air-compressor", "engine" };
    
    int option;
    
    option = 0;
    
    cout << "Welcome to Part Pretenders\n--------------------------\n" << endl;
    
    while ( option != SENTINEL ) {
        option = menuOption();
        
        if ( option == 1 ) {
            listParts( parts, ARRSIZE );
            
        } else if ( option == 2 ) {
            sortParts( parts, ARRSIZE );
            
        } else if ( option == 3 ) {
            searchParts( parts, ARRSIZE );
            
        } else if ( option == SENTINEL ) {
            continue;
        }
    }
    cout << "End of Part Pretenders" << endl;

    
}
int binarySearchParts( string parts[], int arraySize, string key )
{
    int min = 0;
    int index;
    int max = arraySize - 1;
    
    while ( min <= max ) {
        index = ( min + max ) / 2;
        
        if ( parts[index] == key ) {
            return index;
        } else if ( parts[index] < key ) {
            min = index + 1;
        } else {
            max = index - 1;
        }
    }
    return -1;
}
void listParts( string parts[], int arraySize )
{
    // skip line
    cout << endl;
    
    for ( int i = 0; i < arraySize; i++ ) {
        cout << parts[i] << endl;
    }
    // skip line
    cout << endl;
}

void searchParts( string parts[], int arraySize )
{
    string userInput;
    int search;
    
    cout << endl << "Enter a part to search for (no spaces): ";
    cin >> userInput;
    
    search = binarySearchParts( parts, ARRSIZE, userInput );
    
    if ( search != -1 ) {
        cout << "'" << userInput << "' found at index " << search << endl << endl;
    } else {
        cout << "'" << userInput << "' not found." << endl << endl;
    }
    
}
void sortParts( string parts[], int arraySize )
{
    string value;
    int s;
    
    // insertion sort
    for (int i = 1; i < arraySize; i++) {
        value = parts[i];
        s = i - 1;
        
        while (s >= 0 && parts[s] > value) {
            parts[s + 1] = parts[s];
            s = s - 1;
        }

        parts[s + 1] = value;
    }
    
    cout << endl << "Parts sorted." << endl << endl;
}

int menuOption( void )
{
    int userInput;
    
    userInput = 0;
    
    cout << "Parts Pretenders Menu" << endl;
    cout << "1 - List car parts" << endl;
    cout << "2 - Sort car parts" << endl;
    cout << "3 - Search car parts" << endl;
    cout << "9 - Exit" << endl << endl;
    cout << "Enter an option: ";
    
    while ( true ) {
        cin >> userInput;
        if ( userInput == SENTINEL ) {
            return SENTINEL;
        }
        
        if ( cin.fail() || userInput < 1 || userInput > 3 ) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter an option: ";
            continue;
        } else {
            return userInput;
        }
    }
}
