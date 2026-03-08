//==========================================================
//
// Title:      Decimal-to-binary converter
// Course:     CSC 1101
// Lab Number: 04-02
// Author:     Jacob Wahlgren
// Date:       20230525
// Description:
//   This program will convert a decimal number into a binary number.
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

  // Declare constants
  const int BASE = 2;
    
  // Declare variables
  int numDec;
  int numBin;
  string numStr;
    
  // Show application header
  cout << "Welcome to the decimal-to-binary converter." << endl;

  // Prompt for and get decimal number
  cout << "Enter a decimal number: ";
  cin >> numDec;

  // Loop to convert decimal to binary
  cout << "Decimal " << numDec << " is binary ";
  numStr = "";
  while (numDec > 0)
  {
    numBin = numDec % BASE;
    if (numBin == 0)
      numStr = "0" + numStr;
    else
      numStr = "1" + numStr;
    numDec = numDec / BASE;
  }
  cout << numStr << endl << endl;

  // Show application close
    cout << "Decimal-to-binary converter program end." << endl << endl;

}
