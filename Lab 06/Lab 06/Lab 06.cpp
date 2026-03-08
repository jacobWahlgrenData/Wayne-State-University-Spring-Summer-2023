//==========================================================
//
// Title:      Detroit Book Store
// Course:     CSC 1101
// Lab Number: 06
// Author:     Jacob Wahlgren
// Date:       20230605
// Description:
//   Detroit Book Store Price Calculator
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

int main( void ) {
    // constant declaration
    float const BOOK_PRICE = 3.62;
    float const MAGAZINE_PRICE = 1.90;
    float const DISCOUNT_RATE = .05;
    int const COL_ONE = 40;
    int const COL_TWO = 10;
    
    // variable declaration phase
    int numberOfBooks;
    int numberOfMagazines;
    double cost;
    double finalCost;
    double discount;
    
    // application header
    cout << "Welcome to Detroit Book Store\n-----------------------------\n" << endl;
    
    cout << "Enter the Number of books: " << endl;
    cin >> numberOfBooks;
    
    cout << "Enter the Number of magazines: " << endl;
    cin >> numberOfMagazines;
    
    // calculate cost, finalCost, and discount
    
    cost = numberOfBooks * BOOK_PRICE + numberOfMagazines * MAGAZINE_PRICE;
    
    discount = cost * DISCOUNT_RATE;
    
    finalCost = cost - discount;
    
    // outputs
    cout
    << fixed
    << setprecision(2)
    
    << setw(COL_ONE)
    << left
    << "\nPrice of a book (USD) :"
    << setw(COL_TWO)
    << right
    << BOOK_PRICE
    << endl
    
    << setw(COL_ONE)
    << left
    << "Price of a magazine(USD) :"
    << setw(COL_TWO)
    << right
    << MAGAZINE_PRICE
    << endl
    
    << setw(COL_ONE)
    << left
    << "Total Cost(USD):"
    << setw(COL_TWO)
    << right
    << cost
    << endl
    
    << setw(COL_ONE)
    << left
    << "Discount (USD):"
    << setw(COL_TWO)
    << right
    << discount
    << endl
    
    << setw(COL_ONE)
    << left
    << "Final cost (USD):"
    << setw(COL_TWO)
    << right
    << finalCost
    << endl;
    
    
    // application close
    cout << "\nEnd of Detroit Book Store\n----------------------------\n" << endl;
    
    
}
