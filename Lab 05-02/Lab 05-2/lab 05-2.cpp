//==========================================================
//
// Title:      Frigid Feet Altitude Celsius-Fahrenheit Calculator
// Course:     CSC 1101
// Lab Number: 05-2
// Author:     Jacob Wahlgren
// Date:       20230606
// Description:
//   Calculate the temperature in both celsius and fahrenheit, at a certain altitude.
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
    // Constant declaration phase
    int const COL_ONE = 40;
    int const COL_TWO = 6;
    
    // variable declaration phase
    float groundTemp;
    float altitude;
    float celsius;
    float fahrenheit;
    
    // Welcome User
    cout << "Welcome to Frigid Feet\n-----------------------\n" << endl;
    
    // Prompt user for groundTemp
    cout << "Enter ground temperature (ºC): ";
    cin >> groundTemp;
    
    // Prompt user for altitude
    cout << "Enter Altitude (km): ";
    cin >> altitude;
    
    // Calculate air-temperature in celsius
    celsius = groundTemp - (altitude * 6.5);
    
    // Calculate fahrenheit
    fahrenheit = (celsius) * 1.8 + 32;
    
    // Display groundTemp, altitude, celsius and fahrenheit
    
    cout
    << fixed << setprecision(2)
    
    << setw(COL_ONE) << left << "\nGround Temperature:" << setw(COL_TWO) << right << printf("   %.2f ºC", groundTemp) << endl
    
    << setw(COL_ONE) << left << "Altitude:" << setw(COL_TWO) << right << altitude << " km" << endl
    
    << setw(COL_ONE) << left << "Air temperature:" << setw(COL_TWO) << right << celsius << " ºC" << endl
    
    << setw(COL_ONE) << left << "Air temperature:" << setw(COL_TWO) << right << fahrenheit << " ºF" << endl << endl;
    
    // end program
    cout << "End of Frigid Feet" << endl << endl;
}
