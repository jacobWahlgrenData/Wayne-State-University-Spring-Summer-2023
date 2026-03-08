//==========================================================
//
// Title:      Lab 02-01
// Course:     CSC 1101
// Lab Number: 02-01
// Author:     Jacob Wahlgren
// Date:       20230517
// Description:
//   Display lyrics from the song a Spoonfull of Sugar from Mary Poppins.
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

  // Show application header
  cout << "Welcome to Sugar Sellers" << endl;
  cout << "------------------------" << endl << endl;

  // Show lyrics
  cout << "In every job that must be done, there is an element of fun" << endl;
  // More lyrics here ...
  cout << "You find the fun and snap, the job's a game" << endl;
  cout << "And every task you undertake becomes a piece of cake" << endl;
  cout << "A lark, a spree, it's very clear to see" << endl << endl;

  cout << "That a spoonful of sugar helps the medicine go down" << endl;
  cout << "The medicine go down, the medicine go down" << endl;
  cout << "Just a spoonful of sugar helps the medicine go down" << endl;
  cout << "In a most delightful way" << endl;

  // Show application close
  cout << "\nEnd of Sugar Sellers" << endl << endl;
}
