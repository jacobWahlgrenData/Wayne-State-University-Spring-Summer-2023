//==========================================================
//
// Title:      String Theory
// Course:     CSC 1101
// Lab Number: 16
// Author:     Jacob Wahlgren
// Date:       20230717
// Description:
//   Search the string and locate the first repeated character, if any, in the string.
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

int main()
{
    string userInput;
    int size;
    int index;
    bool flag;
    
    flag = true;
    index = 0;
    
    // welcome message
    cout << "Welcome to String Theory\n------------------------\n" << endl;
    
    // prompt user for string
    cout << "Please enter the string: ";
    cin >> userInput;
    
    size = userInput.length();
    
    for ( int i = 0; i < size; i++ ) {
        for ( int j = i + 1; j < size; j++ ) {
            if ( userInput[i] == userInput[j] && index == 0 ) {
                index = j;
            } else if ( userInput[i] == userInput[j] && j < index ) {
                index = j;
                }
            }
        }
    if ( index == 0 ) {
        cout << "There is no repeated character" << endl << endl;
        flag = false;
    }
    
    if ( flag ) {
        cout << "First repeated character: " << userInput[index] << endl;
        cout << "First repeated character position: " << index << endl << endl;
    }
  
    // end message
    cout << "End of String Theory" << endl;
}
