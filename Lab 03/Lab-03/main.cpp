//==========================================================
//
// Title:      Shoppers' Zone
// Course:     CSC 1101
// Lab Number: Lab 03
// Author:     Jacob Wahlgren
// Date:       20230522
// Description:
//   To display Shoppers' Zone customer name, product name, quantity, unit price, and total cost.
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
  // declare variables
  string customerName;
  string productName;
  int productQuantity;
  double unitPrice;
  double totalCost;
    
  
  
  // initialize variables
  customerName = "Darren";
  productQuantity = 5;
  unitPrice = 8.57;
  productName = "Sketchbook";
  
  totalCost = unitPrice * productQuantity;
  
  // application header
  cout << "Welcome to Shoppers' Zone\n--------------------------------" << endl;
    
    cout << "Label             Value" << endl;
    
    cout << "Customer name:     " << customerName << endl;
    
    cout << "Product name:      " << productName << endl;
    
    cout << "Quantity:          " << productQuantity << endl;
    
    cout << "Unit Price($):     " << unitPrice << endl;
    
    cout << "Total cost($):     " << totalCost << endl << endl;
    
    // application close
    cout << "End of Shoppers' Zone" << endl << endl;
}
