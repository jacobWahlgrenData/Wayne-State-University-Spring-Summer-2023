//==========================================================
//
// Title:      Lab01
// Course:     CSC 1101
// Lab Number: 01
// Author:     Jacob Wahlgren
// Date:       20230515
// Description:
//   Shows the byte size of datatypes on the console.
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

    cout << "Welcome to Data processor" << endl;
    cout << "------------------------------" << endl << endl;
    
    // Column Headers
    cout << "Data-type Size(bytes)                                                  Description" << endl << endl;
    // integer datatype
    cout << "int                 4                       Stores whole numbers, without decimals" << endl;
    // float datatype
    cout << "float               4   Stores fractional numbers, containing one or more decimals" << endl;
    // double datatype
    cout << "double              8   Stores fractional numbers, containing one or more decimals" << endl;
    // boolean datatype
    cout << "boolean             1                                  Stores true or false values" << endl;
    // char datatype
    cout << "char                1     Stores a single character/letter/number, or ASCII values" << endl;
    
    cout << "End of Data processor " << endl;
    
} // end main function
// end program
