//==========================================================
//
// Title:      Binary Buzzards Encode-Decode Text
// Course:     CSC 1101
// Lab Number: 10
// Author:     Jacob Wahlgren
// Date:       20230621
// Description:
//   Write a C++ console application that encodes and decodes text.
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

// global const variable declaration and initialization
const string G_FILE_PATH = "/Volumes/T7 Shield/SprSum 2023/CSC1101/Lab Code/Lab 10/";
const string G_SAMPLE_TEXT = "SampleText1-1.txt";
const string G_RANDOM = "RandomNumbers.txt";
const int G_COL_WIDTH = 10;
const int G_CHARBOUND = 256;
const string G_SAMPLE = G_FILE_PATH + G_SAMPLE_TEXT;
const string G_RAND = G_FILE_PATH + G_RANDOM;

// function prototype phase
string encodedLine( string inLine, int shift );
string decodedLine( string inLine, int shift );

int main()
{
    // variable declaration phase
    ifstream iFile;
    ifstream iShift;
    string line;
    string eLine;
    int token;
    int numOfLines;
    int numOfShift;
    
    // variable initialization phase
    numOfLines = 0;
    numOfShift = 0;
    
    // open files
    iFile.open(G_SAMPLE);
    iShift.open(G_RAND);
    
    if (!iFile.is_open() || !iShift.is_open()) {
        if ( !iFile.is_open() && iShift.is_open() ) {
            cout << "Error: file '" << G_SAMPLE_TEXT << "' could not be opened." << endl << endl;
        } // end if
        else if ( !iShift.is_open() && iFile.is_open() ) {
            cout << "Error: file '" << G_RANDOM << "' could not be opened." << endl << endl;
        } // end else if
        
        else {
            cout << "Error: file '" << G_SAMPLE_TEXT << "' and '" << G_RANDOM << "' could not be opened." << endl << endl;
        }
        return 0; // return 0 to end program
    } // end if
    
    else {
        
        cout
        << "Reading lines from file '" << G_SAMPLE_TEXT << "' ..." << endl
        << "Reading numbers from file '" << G_RANDOM << "' ..." << endl
        << endl;
        
        while ( iFile.good() ) {
            iShift >> token;
            getline( iFile, line );
            
            numOfLines = numOfLines + 1;
            numOfShift = numOfShift + 1;
            
            eLine = encodedLine( line, token );
            
            cout << setw(G_COL_WIDTH) << "Original: "<< left << line
            << endl
            << setw(G_COL_WIDTH) << left << "Encoded: " << eLine << " (" << token << ")"
            << endl
            << setw(G_COL_WIDTH) << left << "Decoded: " << decodedLine( eLine, token ) << " (" << -token << ")"
            << endl << endl;

        } // end while
    } // end else
    
    // close file
    iFile.close();
    iShift.close();
    
    // Number of lines and shift numbers
    cout
    << numOfLines << " line(s) read from the file '" << G_SAMPLE_TEXT << "'." << endl
    << numOfShift << " number(s) read from the file '" << G_RANDOM << "'." << endl << endl;
    
} // end main

string encodedLine( string inLine, int shift )
{
    // variable declaration phase
    char asciiChar;
    int i;
    string str;
    int asciiValue;
    
    // initialization phase
    str = "";
    
    for ( i = 0; i < inLine.length(); i++ ) {
        
        asciiChar = inLine[i];

        asciiValue = (int) asciiChar;
        
        asciiValue = asciiValue + shift;
        
        asciiValue = asciiValue % G_CHARBOUND;
        
        asciiChar = (char) asciiValue;
 
        str = str + asciiChar;
    } // end for
    
    return str;
} // end encodedLine

string decodedLine( string inLine, int shift )
{
    // variable declaration phase
    char alphChar;
    int i;
    string str;
    int alphNum;
    
    // initialization phase
    str = "";
    
    for ( i = 0; i < inLine.length(); i++ ) {
        
        alphChar = inLine[i];
        
        alphNum = (int) alphChar;
        
        alphNum = alphNum - shift;
        
        alphNum = alphNum % G_CHARBOUND;
        
        alphChar = (char) alphNum;
        
        str = str + alphChar;

    } // end for

    return str;
} // end decodedLine

// end program
