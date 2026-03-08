//==========================================================
//
// Title:      Happy Hoopsters
// Course:     CSC 1101
// Lab Number: 15
// Author:     Jacob Wahlgren
// Date:       20230714
// Description:
//   Console application which tracks the scores of a four-quarter basketball game.
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include <array>
using namespace std; // So "std::cout" may be abbreviated to "cout"

// prototypes
void resetScores( int scores[] );
void printScores( int team1[], int team2[], int quarter );
int teamScore( int scores[], int quarter );

int main()
{
    // constant declaration and initialization
    const string SENTINEL = "n";
    const int SIZE = 4;
    const string OUTPUT_FILE = "Scores.txt";
    
    // variable declaration
    ofstream games;
    string userInput;
    bool flag;
    int score;
    int game;
    int team1[SIZE];
    int team2[SIZE];
    
    // initialization
    game = 0;
    flag = true;
    
    games.open(OUTPUT_FILE);
    
    // Welcome message
    cout << "Welcome to Happy Hoopsters\n--------------------------------\n" << endl;
    if ( !games.is_open() ) {
        cout << "Error: file '" << OUTPUT_FILE << "' will not open." << endl;
    } else {
        cout << "Enter another game (y or n)? ";
        cin >> userInput;
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
        
        while ( userInput != SENTINEL ) {
            while ( ( userInput != "y" && userInput != SENTINEL ) || userInput.length() > 1 ) {
                cin.clear();
                cin.ignore(1000000, '\n');
                
                cout << "Enter another game (y or n)? ";
                cin >> userInput;
                
                transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
                
                if ( userInput == SENTINEL ) {
                    flag = false;
                }
            }
            if ( flag ) {
                resetScores(team1);
                resetScores(team2);
                
                // skip a line
                cout << endl;
                
                game = game + 1;
                cout << "Game " << game << "\n------------------------------------------\n" << endl;
                
                for ( int i = 1; i < 5; i++ ) {
                    cout << "Game " << game << ", quarter " << i << endl;
                    
                    cout << "Enter Warriors score: ";
                    cin >> score;
                    
                    while ( cin.fail() || score < 0 ) {
                        cin.clear();
                        cin.ignore(1000000, '\n');
                        
                        cout << "Enter Warriors score: ";
                        cin >> score;
                    }
                    
                    team1[ i - 1 ] = score;
                    
                    cout << "Enter Lakers score: ";
                    cin >> score;
                    
                    while ( cin.fail() || score < 0 ) {
                        cin.clear();
                        cin.ignore(1000000, '\n');
                        
                        cout << "Enter Lakers score: ";
                        cin >> score;
                    }
                    
                    team2[ i - 1 ] = score;
                    
                    // skip a line
                    cout << endl;
                    
                    printScores(team1, team2, i);
                    
                }
                // Final Score
                cout << "Game " << game << " final score: Warriors " << teamScore( team1, 4 ) << ", Lakers " << teamScore( team2, 4 ) << endl << endl;
                
                games << "Game " << game << endl;
                games << "Warriors " << teamScore( team1, 4 ) << endl;
                games << "Lakers " << teamScore( team2, 4 ) << endl;
                
                cout << "Enter another game (y or n)? ";
                cin >> userInput;
            }
        }
    }
    games.close();
    
    // end messages
    cout << endl << game << " game(s) written to file '" << OUTPUT_FILE <<"'." << endl << endl;
    cout << "End of Happy Hoopsters" << endl;
    
}

void resetScores( int scores[] ) {
    const int SIZE = sizeof(scores)/sizeof(scores[0]);
    
    for ( int i = 0; i < SIZE; i++ ) {
        scores[i] = 0;
    }
}

void printScores( int team1[], int team2[], int quarter ) {
    const int COL_ONE = 10;
    const int COL_TWO = 3;
    const int COL_THR = 11;
    
    // score message
    cout << "Score after quarter " << quarter << endl;
    
    cout << setw(COL_ONE) << left << "Warriors";
    for ( int i = 0; i < quarter; i++ ) {
        cout << setw(COL_TWO) << right << team1[i] << " ";
    }
    cout << setw(COL_THR) << right << teamScore( team1, quarter );
    // skip a line
    cout << endl;
    
    cout << setw(COL_ONE) << left << "Lakers";
    for ( int i = 0; i < quarter; i++ ) {
        cout << setw(COL_TWO) << right << team2[i] << " ";
    }
    cout << setw(COL_THR) << right << teamScore( team2, quarter );
    
    // skip two lines
    cout << endl << endl;
}

int teamScore( int scores[], int quarter ) {
    // variable declaration
    int sum;
    
    // intialization
    sum = 0;
    
    for ( int i = 0; i < quarter; i++ ) {
        sum = sum + scores[i];
    }
    
    return sum;
}
