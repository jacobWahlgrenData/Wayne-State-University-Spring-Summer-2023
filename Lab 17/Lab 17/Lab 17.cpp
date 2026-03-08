//==========================================================
//
// Title:      <application>
// Course:     CSC 1101
// Lab Number: <number>
// Author:     <name>
// Date:       <date>
// Description:
//   Inventory Management System
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

//structures
struct product {
    int ID;
    string product;
    double wholesale;
    double retail;
    int quantity;
};

// constants
const string FILENAME = "SnowShepherdsInventory-1.txt";
const int ARRAY_SIZE = 5;
const int COL_ONE = 13;
const int COL_TWO = 16;
const int COL_THR = 15;
const int COL_FOU = 30;
const int COL_FIV = 10;
const int SENTINEL = 9;


// prototypes
int menuOption( void );
int findProductByID( product products[ ARRAY_SIZE ], int key );
int findProductByName( product products[ ARRAY_SIZE ], string key );
void printProduct( product products[ ARRAY_SIZE ], int index );

int main( void )
{
    // declaration
    product products[ ARRAY_SIZE ];
    ifstream file;
    string line;
    
    int id;
    string prod;
    double wholesale;
    double retail;
    int quantity;
    
    int index;
    int theChoice;
    string name;
    bool flag;
    int findProdID;
    int search;
    int ai;
    
    // initialization
    index = 0;
    theChoice = 0;
    flag = true;
    
    // welcome
    cout << "Welcome to Snow Shepherds\n-------------------------\n";
    file.open(FILENAME);
    
    if ( !file.is_open() ) {
        cout << "Error: unable to open file '" << FILENAME << "'." << endl;
    }
    
    else {
        while ( file.good() )
        {
            getline( file, line );
            
            file >> id;
            products[index].ID = id;
            
            file >> prod;
            products[index].product = prod;
            
            file >> wholesale;
            products[index].wholesale = wholesale;
            
            file >> retail;
            products[index].retail = retail;
            
            file >> quantity;
            products[index].quantity = quantity;
            
            index++;
        }
    }
    file.close();
    
    while ( theChoice != SENTINEL )
    {
        theChoice = menuOption();

        if ( theChoice == SENTINEL ) {
            continue;
        }
        
        else if ( theChoice == 1 ) {
            
            while ( flag == true )
            {
                cout << "Enter product ID to search for: ";
                cin >> search;
                
                if ( cin.fail() ) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else {
                    findProdID = findProductByID( products, search );
                    flag = false;
                }
            }
            
            
            if (  findProdID == -1 ) {
                cout << "Error: product ID '" << search << "' not in inventory." << endl;
                flag = true;
            }
            
            else {
                cout << "\nProduct " << products[findProdID].ID << endl;
                printProduct( products, findProdID );
            }
            
        }
        
        else if ( theChoice == 2 ) {
            
            cout << "Enter product name to search for: ";
            cin >> name;
            
            if ( findProductByName( products, name ) == -1 ) {
                cout << "Error: product name '" << name << "' not in inventory." << endl;
            }
            
            else {
                // convert name to lowercase
                transform(name.begin(), name.end(), name.begin(), ::tolower);
                ai = findProductByName( products, name );
                cout << "\nProduct " << products[ai].ID << endl;
                printProduct( products, ai );
            }
            
        }
        
        else if ( theChoice == 3 ) {
            cout << "\nProduct Inventory" << endl;
            cout << setw(COL_ONE) << left << "Code";
            cout << setw(COL_TWO) << left << "Product";
            cout << setw(COL_TWO) << left << "Wholesale ($)";
            cout << setw(COL_TWO) << left << "Retail ($)";
            cout << setw(COL_ONE) << left << "Inventory"
                 << endl;

            for ( int i = 0; i < ARRAY_SIZE; i++ )
            {
                cout << fixed << setprecision(2)
                << setw(COL_ONE) << left  << products[ i ].ID
                << setw(COL_ONE) << left  << products[ i ].product
                << setw(COL_TWO) << right << products[ i ].wholesale
                << setw(COL_ONE) << right << products[ i ].retail
                << setw(COL_THR) << right << products[ i ].quantity
                << endl;
                
            }
        }
        
        else {
            theChoice = 0;
        }
            
    }
    // end message
    cout << "\nEnd of Snow Shepherds" << endl;

}

int menuOption( void )
{
    int userInput;
    bool flag;
    
    userInput = 0;
    flag = true;
    
    while ( flag == true )
    {
        cout << "\nSnow Sheprherds Menu"  << endl
             << "1-Find Products by ID"   << endl
             << "2-Find products by Name" << endl
             << "3-List Products"         << endl
             << "9-Exit"                  << endl
                                          << endl
             << "Enter an option: ";
        cin  >> userInput;
        
        if ( cin.fail() ) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            flag = false;
        }
    }
    return userInput;
}

int findProductByID( product products[ ARRAY_SIZE ], int key )
{
    for ( int i = 0; i < ARRAY_SIZE; i++ )
    {
        if ( products[ i ].ID == key )  {
            return i;
        }
    }
    return -1;
}

int findProductByName( product products[ ARRAY_SIZE ], string key )
{
    string product;

    for ( int i = 0; i < ARRAY_SIZE; i++ )
    {
        product = products[ i ].product;
        
        // convert product to lowercase
        transform(product.begin(), product.end(), product.begin(), ::tolower);
       
        if ( product == key ) {
            return i;
        }
    }
    return -1;
}

void printProduct( product products[ ARRAY_SIZE ], int index )
{
    cout << fixed         << setprecision(2)
    << setw(COL_FOU) << left << "Product:"             << setw(COL_FIV) << right << products[ index ].product   << endl
    << setw(COL_FOU) << left << "Wholesale price ($):" << setw(COL_FIV) << right << products[ index ].wholesale << endl
    << setw(COL_FOU) << left << "Retail price ($):"    << setw(COL_FIV) << right << products[ index ].retail    << endl
    << setw(COL_FOU) << left << "Quantity in stock:"   << setw(COL_FIV) << right << products[ index ].quantity  << endl;
}
