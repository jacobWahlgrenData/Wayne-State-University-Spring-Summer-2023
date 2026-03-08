//==========================================================
//
// Title:      Math Maniac
// Course:     CSC 1101
// Lab Number: 12
// Author:     Jacob Wahlgren
// Date:       20230703
// Description:
//      Calculate nth term and summation of an arithmetic series
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

int getNthTerm( int a, int d, int n );
int getSum( int a, int d, int n );

int main()
{
    // define const
    const int COL_ONE = 30;
    const int COL_TWO = 5;
    
    // add welcome message
    cout << "Welcome to Math Maniacs\n-----------------------\n";
    
    int firstTerm;
    int comDiff;
    int n;
    
    n = 0;
    
    // prompt user for firstTerm
    cout << "\nEnter first term of the arithmetic series: ";
    cin >> firstTerm;
    
    cout << "Enter common difference of the arithmetic series: ";
    cin >> comDiff;
    
    while ( n < 1 ) {
        cout << "Enter value of n: ";
        cin >> n;
    }
    
    // outputs
    cout << setw(COL_ONE) << left
    << "Series:"
    << setw(COL_TWO) << right
    << "Arithmetic" << endl
    << setw(COL_ONE) << left
    << "First term:"
    << setw(COL_TWO) << right
    << firstTerm << endl
    << setw(COL_ONE) << left
    << "Common difference:"
    << setw(COL_TWO) << right
    << comDiff << endl
    << setw(COL_ONE) << left
    << "Value of n:"
    << setw(COL_TWO) << right
    << n << endl
    << setw(COL_ONE) << left
    << "nth term:"
    << setw(COL_TWO) << right
    << getNthTerm( firstTerm, comDiff, n ) << endl
    << setw(COL_ONE) << left
    << "Summation of n terms:"
    << setw(COL_TWO) << right
    << getSum( firstTerm, comDiff, n ) << endl << endl;
    
    // end message
    cout << "End of Math Maniacs\n-------------------\n";
}

int getNthTerm( int a, int d, int n )
{
    return ( a + ( n - 1 ) * d );
}

int getSum( int a, int d, int n )
{
    float r = (float) n / 2;
    float ai = ( 2 * a + ( (float) n - 1 ) * d );
    return r * ai;
}
