//==========================================================
//
// Title:      String Containing s
// Course:     CSC 1101
// Lab Number: 18
// Author:     Jacob Wahlgren
// Date:       <date>
// Description:
//   Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
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
    char arr1[3] = {'(', '{', '['};
    char arr2[3] = {')', '}', ']'};
    string userInput;
    string other1;
    string other2;
    int index;
    
    // welcome
    cout << "Welcome to the string program\n-----------------------------\n" << endl;
    
    cout << "Please enter a string ( with characters: () {} [] in any order): ";
    cin >> userInput;
    cin.ignore();

    // skip line
    cout << endl;
    for ( int k = 0; k < userInput.size(); k++ ) {
        if ( userInput[0] == arr2[k] ) {
            cout << "False" << endl;
            return 0;
        }
    }
    
    for ( int k = 0; k < userInput.size(); k++ ) {
        if ( (userInput[k] == '(' or userInput[k] == '{' or userInput[k] == '[') ) {
            other1 = other1 + userInput[k];
        }
        else if ( userInput[k] == ')' or userInput[k] == '}' or userInput[k] == ']' ) {
            other2 = other2 + userInput[k];
        }
    }
    
    index = (int) other2.length();
    
    if ( other1.length() == index ) {
        for ( int i = 0; i < other1.length(); i++ ) {
            if ( other1[i] == arr1[0] and other2[index - 1] == arr2[0] ) {
                index = index - 1;
                continue;
                }
            else if ( other1[i] == arr1[1] and other2[index - 1] == arr2[1] ) {
                    index = index - 1;
                    continue;
                }
            else if ( other1[i] == arr1[2] and other2[index - 1] == arr2[2] ) {
                    index = index - 1;
                    continue;
                }
            else {
                    cout << "False" << endl;
                    return 0;
                }
            }
        }
    else {
        cout << "False" << endl;
        return 0;
    }
    cout << "True" << endl;
}
