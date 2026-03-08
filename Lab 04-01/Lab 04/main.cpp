//==========================================================
//
// Title:      Geese Observation
// Course:     CSC 1101
// Lab Number: 04-1
// Author:     Jacob Wahlgren
// Date:       05242023
// Description:
//   To track the observation of geese on a golf course.
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
  string course;
  int days;
  int geese;

  // Show application header
    cout << "Welcome to the Golf Course Geese Observation Program (GCGOP)" << endl;

  // Prompt for and get course name
  cout << "Enter golf course name (no spaces): ";
  cin >> course;

  // Prompt for and get observation days
  cout << "Enter observation days: ";
  cin >> days;

  // Prompt for and get course name
  cout << "Enter observed geese: ";
  cin >> geese;

  // Print inputs and outputs
  cout << "\nGolf course:\t\t\t" << course << endl;
  cout << "Observation days:\t\t" << days << endl;
  cout << "Observed geese:\t\t\t" << geese << endl;
  cout << "Rough average geese per day:\t"
    << geese / days << endl;
  cout << "Precise average geese per day:\t"
    << (double) geese / days << endl << endl;

  // Show application close
    cout << "GCGOP end." << endl << endl;
}
