//==========================================================
//
// Title:      Friendly Fools
// Course:     CSC 1101
// Lab Number: 13
// Author:     Jacob Wahlgren
// Date:       20230705
// Description:
//   Console application that manages a list of friends.
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

// prototypes
int menuOption( void );
int searchFriends( string array[], int arraySize, string key );
void listFriends( string array[], int arraySize );
    
int main( void )
{
   // constant declaration
   const int SENTINEL = 9;
   const int ARRSIZE = 5;
   
   // variable declaration phase
   int mOption;
   int size;
   int search;
   string found = " found at index ";
   string notFound = " NOT found.";
   string arr[ARRSIZE] = { "Jacob", "Jake", "James", "Jane", "Janis" };
   string userInput;
   
   // initialization phase
   size = sizeof(arr) / sizeof(string);
   
   cout << "Welcome to Friendly Fools\n------------------------------\n" << endl;
    
   do {
      
      mOption = menuOption();
      
      switch ( mOption ) {
         case 1:
            listFriends( arr, size);
            break;
         
         case 2:
            cout << "Enter a friend to search for: ";
            cin >> userInput;
            search = searchFriends( arr, size, userInput );
            
            switch ( search ) {
               case -1:
                  cout << "'" << userInput << "'" << notFound << endl << endl;
                  break;
                  
               default:
                  cout << "'" << userInput << "'" << found << search << "." << endl << endl;
                  break;
            }
            
         case 9:
            break;
         
         default:
            cout << "Please enter a valid option." << endl;
            break;
      }
      
   } while ( mOption != SENTINEL );
   
   cout << "End of Friendly Fools" << endl;
}
    
int menuOption( void ) {
    // const declaration and initialization
    const int COL_ONE = 4;
    const int COL_TWO = 15;
    
   // variable declaration
    int userInput;
   
    // variable initialization
    userInput = 0;
    
    cout << "Friendly Fools Menu" << endl;
    cout << setw(COL_ONE) << left << "1 -" << setw(COL_TWO) << "List friends" << endl;
    cout << setw(COL_ONE) << left << "2 -" << setw(COL_TWO) << "Search friends" << endl;
    cout << setw(COL_ONE) << left << "9 -" << setw(COL_TWO) << "Exit " << endl << endl;
    cout << setw(COL_ONE) << left << "Enter an option: ";
    
   while ( userInput < 1 ) {
       cin >> userInput;
       if ( cin.fail() || userInput < 1 ) {
          cin.clear();
          cin.ignore( 100, '\n' );
          cout << "\nPlease enter a valid option: ";
          userInput = 0;
       } else {
          continue;
          }
       }
    //skip a line
    cout << endl;
   
    return userInput;
}
    
int searchFriends( string array[], int arraySize, string key ) {
   // variable declaration
   int size;
   
   // check if arraySize is even or odd
   if ( arraySize % 2 == 0 ) {
      if ( array[arraySize] == key || array[0] == key ){
         if ( array[arraySize] == key ) {
            return arraySize;
         } else {
            return 0;
         }
      }
      size = arraySize / 2;
      
   } else if ( array[arraySize] == key || array[0] == key ) {
      if ( array[arraySize] == key ) {
         return arraySize;
      } else {
         return 0;
      }
   } else {
      arraySize = arraySize - 1;
      size = arraySize / 2;
   }
   
   while ( arraySize != 0 ) {
      for ( int i = size; i < arraySize; i++ ) {
         if ( array[i] == key || array[arraySize] == key ) {
            if ( array[i] == key ) {
               return i;
            } else {
               return arraySize;
            }
         } else if ( array[++i] == key ) {
            return i;
         } else {
            continue;
         }
      }
      arraySize = size;
      size = size / 2;
   }
   
   return -1;
}

void listFriends( string array[], int arraySize ) {
   // variable declaration
   int counted;
   
   // variable initialization
   counted = 0;
   
   // iterate through and output friends and count per friend
   for ( int i = 0; i < arraySize; i++ ) {
      cout << array[i] << endl;
      counted = counted + 1;
   }
   cout << "\nFriend count: " << counted << endl << endl;
}
