//==========================================================
//
// Title:      Office Oaks Customer Purchase Calculator
// Course:     CSC 1101
// Lab Number: 07-2
// Author:     Jacob Wahlgren
// Date:       20230607
// Description:
//   Calculates the cost of one customer purchase
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
    int const COL_ONE = 40;
    int const COL_TWO = 20;
    float const DISCOUNT_RATE = .1;
    string const c = "Clipboards";
    string const p = "Printer paper";
    string const r = "Scissors";
    string const s = "Stapler";
    string const w = "Writing Pads";
    
    // variable declaration phase
    int qtyPurchased;
    float productCost;
    float sTotal; // sub total
    float total;
    float discount;
    string pName; // product name
    char prodCode;
    
    // initialization phase
    productCost = 0.0;
    discount = 0.0;
    
    // welcome user
    cout << "Welcome to Office Oaks\n-------------------------\n" << endl;
    
    // prompt user for quantity purchased in range 2 to 20
    cout << "Quantity purchased in range 2 and 20: ";
    cin >> qtyPurchased;
    
    if ( qtyPurchased < 2 || qtyPurchased > 20) {
        cout << "Error: quantity purchased must be in range 2 and 20.\n" << endl;
        return printf("End of Office Oaks\n");
    }
    //output menu
    cout
    // skip line
    << endl
    << "Enter the product code" << endl
    << " c-" + c << endl
    << " p-" + p << endl
    << " r-" + r << endl
    << " s-" + s << endl
    << " w-" + w << endl
    << " : ";
    cin >> prodCode;
    
    // skip line
    cout << endl;
    
    // switch statement to determine productCost
    switch ( prodCode ) {
        case 'c':
            productCost = 8.00;
            pName = c;
            break;
        
        case 'p':
            productCost = 15.00;
            pName = p;
            break;
        
        case 'r':
            productCost = 10.75;
            pName = r;
            break;
        
        case 's':
            productCost = 11.25;
            pName = s;
            break;
        
        case 'w':
            productCost = 12.50;
            pName = w;
            break;
            
        default:
            productCost = 12.50;
            pName = w;
            prodCode = 'w';
            break;
    }
    
    // calculate sub-total
    sTotal = qtyPurchased * productCost;
    
    // check if there is a discount
    if ( sTotal > 50 ) {
        discount = sTotal * DISCOUNT_RATE;
        total = sTotal - discount;
    }
    else {
        total = sTotal;
    }
    
    // outputs
    cout
    << fixed << setprecision(2)
    
    << setw(COL_ONE) << left << "Product code:"
    << setw(COL_TWO) << right << prodCode << endl
    
    << setw(COL_ONE) << left << "Product name:"
    << setw(COL_TWO) << right << pName << endl
    
    << setw(COL_ONE) << left << "Product cost ($):"
    << setw(COL_TWO) << right << productCost << endl
    
    << setw(COL_ONE) << left << "Quantity:"
    << setw(COL_TWO) << right << qtyPurchased << endl
    
    << setw(COL_ONE) << left << "Subtotal ($):"
    << setw(COL_TWO) << right << sTotal << endl
    
    << setw(COL_ONE) << left << "Discount ($):"
    << setw(COL_TWO) << right << discount << endl
    
    << setw(COL_ONE) << left << "Total ($):"
    << setw(COL_TWO) << right << total << endl;
    
    // end program
    cout
    //skip line
    << endl
    
    << "End of Office Oaks" << endl;
    
}
