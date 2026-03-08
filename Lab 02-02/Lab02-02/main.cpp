//==========================================================
//
// Title:      Lab 02-02
// Course:     CSC 1101
// Lab Number: 02-02
// Author:     Jacob Wahlgren
// Date:       20230517
// Description:
//   UNICODE numbers and names (5 total chosen + 1 pre-programmed)
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

  // Declare variables
  string u1 = "U+00B0";
  string u1desc = "Degree sign";

  // your codes and descriptions here ...
  string u2 = "U+2121";
  string u2desc = "Telephone Sign";
  string u3 = "U+1F933";
  string u3desc = "Selfie Sign";
  string u4 = "U+2706";
  string u4desc = "Telephone Location Sign";
  string u5 = "U+1F919";
  string u5desc = "Call Me Hand Sign";
  string u6 = "U+1F50B";
  string u6desc = "Battery Sign";

  // Show application header
    cout << "Welcome to Unicodes and Descriptions\n" << endl;

  // Prompt for and get hexadecimal number
  cout << "Unicode   Description" << endl;

  // your spacing here ...
  cout << u1 << "    " << u1desc << endl;
  cout << u2 << "    " << u2desc << endl;
  cout << u3 << "   " << u3desc << endl;
  cout << u4 << "    " << u4desc << endl;
  cout << u5 << "   " << u5desc << endl;
  cout << u6 << "   " << u6desc << endl;

  // Show application close
  cout << "\nEnd of Program" << endl;
}

