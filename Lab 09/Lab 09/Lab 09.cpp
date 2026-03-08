//==========================================================
//
// Title:      Text Turtles Text Reading Grade Level
// Course:     CSC 1101
// Lab Number: 09
// Author:     Jacob Wahlgren
// Date:       20230615
// Description:
//   Determines the reading grade level from the text of a file.
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
    // constant declaration phase
    const string file = "/Users/ipbk-private/Documents/CSC1101/Lab Code/Lab 09/Lab 09/SampleText2-2.txt";
    const int COL_ONE = 60;
    const int COL_TWO = 10;
    
    // declaration phase
    ifstream oFile;
    int alphNumChar;
    int punctChar;
    int spaces;
    int otherChar;
    int numOfWords;
    int numOfSentences;
    int numLines;
    int totalChar;
    string line;
    char l;
    float Factor1;
    float Factor2;
    float readingLevel;
    
    // initialization phase
    numOfWords = 0;
    numOfSentences = 0;
    otherChar = 0;
    alphNumChar = 0;
    punctChar = 0;
    spaces = 0;
    numLines = 0;
    
    // Welcome the User
    cout << "Welcome to Text Turtles\n-----------------------\n" << endl;
    
    // open oFile
    oFile.open(file);
    
    if ( !oFile.is_open() ) {
        cout << "Error: unable to open File '" << file << "'.\n" << endl;
    }
    else {
        // print reading lines
        cout << "Reading lines from file '" << file << "'  ..." << endl << endl;
        
        while ( oFile.good() )
        {
            numLines = numLines + 1;
            
            getline(oFile, line);
        
            for ( int i = 0; i < line.length(); i++ ) {
                l = line[i];
                
                if ( isalnum( l ) ) {
                    alphNumChar = alphNumChar + 1;
                    
                } // end if
                
                else if ( ispunct( l ) ) {
                    if ( l == '.' ) {
                        numOfSentences = numOfSentences + 1;
                        punctChar = punctChar + 1;
                        
                    } // end if
                    
                    else {
                        punctChar = punctChar + 1;
                    } // end else
                } // end else if
                
                else if ( l == ' ' ) {
                    spaces = spaces + 1;
                } // end else if
            } // end for
        } // end while
    } // end else
    
    // calculation phase
    totalChar = alphNumChar + punctChar + spaces;
    
    numOfWords = numOfSentences + spaces;
    
    Factor1 = (float) alphNumChar / (float) numOfWords * 100.0;
    
    Factor2 = (float) numOfSentences / (float) numOfWords * 100.0;
    
    readingLevel = ( 0.0588 * Factor1 ) - ( 0.296 * Factor2 ) - 15.8;
    
    // output phase
    cout
    
    << fixed << setprecision(1)
    
    << setw(COL_ONE) << left << "Alphanumeric chars:"
    << setw(COL_TWO) << right << alphNumChar << endl
    
    << setw(COL_ONE) << left << "Punctuation chars:"
    << setw(COL_TWO) << right << punctChar << endl
    
    << setw(COL_ONE) << left << "Spaces:"
    << setw(COL_TWO) << right << spaces << endl
    
    << setw(COL_ONE) << left << "Other characters:"
    << setw(COL_TWO) << right << otherChar << endl
    
    << setw(COL_ONE) << left << "Total characters:"
    << setw(COL_TWO) << right << totalChar << endl << endl
    
    << setw(COL_ONE) << left << "Sentences:"
    << setw(COL_TWO) << right << numOfSentences << endl
    
    << setw(COL_ONE) << left << "Words:"
    << setw(COL_TWO) << right << numOfWords << endl
    
    << setw(COL_ONE) << left << "Letters in Words:"
    << setw(COL_TWO) << right << alphNumChar << endl << endl
    
    << setw(COL_ONE) << left << "Factor 1:"
    << setw(COL_TWO) << right << Factor1 << endl
    
    << setw(COL_ONE) << left << "Factor 2:"
    << setw(COL_TWO) << right << Factor2 << endl
    
    << setw(COL_ONE) << left << "Reading level:"
    << setw(COL_TWO) << right << readingLevel << endl << endl;
    
    // end of text turtles
    cout << "End of Text Turtles." << endl << endl;
    
    
}
