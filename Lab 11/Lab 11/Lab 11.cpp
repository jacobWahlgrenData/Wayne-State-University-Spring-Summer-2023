//==========================================================
//
// Title:      Neon Numbers
// Course:     CSC 1101
// Lab Number: 11
// Author:     Jacob Wahlgren
// Date:       20230626
// Description:
//   Print integers in a triangle pattern
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
    // variable declaration phase
    int i; // index variable
    int j; // length setting variable
    int a; // another index variable
    int aj; // another countdown variable
    int ac; // another countdown variable
    bool flag;
    
    // initialization phase
    j = 10;
    flag = false;
    aj = 9;
    ac = 3;
    
    // welcome message
    cout << "Welcome to Neon Numbers\n-------------------------\n" << endl;
    
    for ( i = 0; i < j; i++) {
        if ( flag == false ) {
            for ( a = 0; a < 9; a++ ) {
                cout << " ";
            } // end for
            cout << i << endl;
            flag = true;
            continue;
            
        } // end if
        aj = aj - 1;
        for ( a = 0; a < aj; a++ ) {
            cout << " ";
        } // end for
        
        for ( a = 0; a < ac; a++ ) {
            cout << i;
        } // end for
        ac = ac + 2;
        cout << endl;
    } // end for
    
    // end message
    cout << "\nEnd of Neon Numbers" << endl << endl;
} // end main
// end program
