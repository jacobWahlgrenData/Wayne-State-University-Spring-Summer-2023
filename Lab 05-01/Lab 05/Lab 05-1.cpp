//==========================================================
//
// Title:      Cash Closet USD-to-EURO converter
// Course:     CSC 1101
// Lab Number: 05-1
// Author:     Jacob Wahlgren
// Date:       20230606
// Description:
//   Convert US dollars into Euros
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
    // Constant Declaration Phase
    double const EURO_PER_USD = 0.93438; // 0.93438 EURO-PER-USD
    int const COL_ONE = 42; // column size for setw
    int const COL_TWO = 5; // column size for setw
    
    // Variable Declaration Phase
    float usDollars;
    float euros;
    
    // Welcome User
    cout << "Welcome to Cash Closet\n----------------------------\n" << endl;
    
    // Prompt User for usDollars
    cout << "Enter a value (US dollars): ";
    cin >> usDollars;
    
    // Inform User of Conversion rate per US dollar
    cout << setw(COL_ONE) << left << "\nConversion rate (per US dollar):" << setw(COL_TWO) << right << printf("  %.2f", EURO_PER_USD) << endl;
    
    // Define euros
    euros = usDollars * EURO_PER_USD;
    
    // Inform User of Euros in return
    cout << fixed << setprecision(2) << setw(COL_ONE) << left << "Euros:" << setw(COL_TWO) << right << euros << endl << endl;
    
    // end Cash Closet
    cout << "End of Cash Closet" << endl;
} // end program
