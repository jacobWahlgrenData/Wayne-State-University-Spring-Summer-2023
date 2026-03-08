//==========================================================
//
// Title:      Leave Counter Maple Marvels
// Course:     CSC 1101
// Lab Number: 07-1
// Author:     Jacob Wahlgren
// Date:       20230607
// Description:
//   Counts the number of leaves fallen over the months of September, October, and November
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

int main( void )
{
    // constant declaration phase
    string const ending = "End of Maple Marvels";
    int const COL_ONE = 40;
    int const COL_TWO = 10;
    
    // variable declaration phase
    int sept;
    int oct;
    int nov;
    int totalDrop;
    float avgDrop;
    string highDrop;
    string lowDrop;
    
    // welcoming statement
    cout << "Welcome to Maple Marvels\n--------------------------\n" << endl;
    
    // prompt user for sept, oct, and nov
    cout << "Enter the leaf drop for September: ";
    cin >> sept;
    
    cout << "Enter the leaf drop for October: ";
    cin >> oct;
    
    cout << "Enter the leaf drop for November: ";
    cin >> nov;
    
    // check if all variables are above 0
    if ( sept < 0 || oct < 0 || nov < 0) {
        cout << "Error: all leaf counts must be at least zero.\n\n";
        return printf("End of Maple Marvels\n");
    }
    
    // calculate totalDrop and avgDrop
    totalDrop = sept + oct + nov;
    
    avgDrop = totalDrop / 3.0;
    
    // display outputs
    cout
    //skip line
    << endl
    
    << fixed << setprecision(3)
    
    << setw(COL_ONE) << left << "September leaf drop:"
    << setw(COL_TWO) << right << sept << endl
    
    << setw(COL_ONE) << left << "October leaf drop:"
    << setw(COL_TWO) << right << oct << endl
    
    << setw(COL_ONE) << left << "November leaf drop:"
    << setw(COL_TWO) << right << nov << endl
    
    << setw(COL_ONE) << left << "Total drop:"
    << setw(COL_TWO) << right << totalDrop << endl
    
    << setw(COL_ONE) << left << "Average drop:"
    << setw(COL_TWO) << right << avgDrop << endl;
    
    // check validity of highDrop and lowDrop
    highDrop = "September";
    
    if ( oct > sept && oct > nov ) {
        highDrop = "October";
    }
    else if ( nov > sept && nov > oct ) {
        highDrop = "November";
    }
    
    lowDrop = "September";
    
    if ( oct < sept && oct < nov ) {
        lowDrop = "October";
    }
    else if ( nov < sept && nov < oct) {
        lowDrop = "November";
    }
    
    // output highDrop and lowDrop
    cout
    << setw(COL_ONE) << left << "Highest drop:"
    << setw(COL_TWO) << right << highDrop << endl
    
    << setw(COL_ONE) << left << "Lowest drop:"
    << setw(COL_TWO) << right << lowDrop << endl << endl;
    
    // ending comment
    cout << "End of Maple Marvels" << endl;
}
