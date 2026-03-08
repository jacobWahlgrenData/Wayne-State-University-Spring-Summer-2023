//==========================================================
//
// Title:      CS Grader - Grade and Course GPA / Student
// Course:     CSC 1101
// Lab Number: 08
// Author:     Jacob Wahlgren
// Date:       20230612
// Description:
//   Shows grade and Course GPA earned by student
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
    // const declaration phase
    string const course = "Programming Language Lab";
    string const courseID = "CSC 1101";
    int const COL_ONE = 60;
    int const COL_TWO = 30;
    
    // declaration phase
    float userInput;
    float earnedScore;
    string letterGrade;
    float gradePoint;
    
    // welcome user
    cout << "Welcome to Wayne State University\n---------------------------------\n" << endl;
    
    // prompt user for score
    cout << "Enter the score: ";
    cin >> userInput;
    
    // logic to determine letterGrade and gradePoint
    if ( userInput < 0 || userInput > 100 ) { // check to determine if userInput in correct range
        cout << "\nError: number not within range.\n" << endl;
        return 0;
    }
    
    else if ( userInput >= 93 ) {
        letterGrade = "A";
        gradePoint = 4.0;
    }
    else if ( userInput >= 90 ) {
        letterGrade = "A-";
        gradePoint = 3.67;
    }
    else if ( userInput >= 87 ) {
        letterGrade = "B+";
        gradePoint = 3.33;
    }
    else if ( userInput >= 83 ) {
        letterGrade = "B";
        gradePoint = 3.0;
    }
    else if ( userInput >= 80 ) {
        letterGrade = "B-";
        gradePoint = 2.67;
    }
    else if ( userInput >= 77 ) {
        letterGrade = "C+";
        gradePoint = 2.33;
    }
    else if ( userInput >= 73 ) {
        letterGrade = "C";
        gradePoint = 2.0;
    }
    else if ( userInput >= 70 ) {
        letterGrade = "C-";
        gradePoint = 1.67;
    }
    else if ( userInput >= 67 ) {
        letterGrade = "D+";
        gradePoint = 1.33;
    }
    else if ( userInput >= 63) {
        letterGrade = "D";
        gradePoint = 1.0;
    }
    else if ( userInput >= 60 ) {
        letterGrade = "D-";
        gradePoint = .67;
    }
    else {
        letterGrade = "F";
        gradePoint = 0.0;
    }

    // display outputs
    cout
    // skip line
    << endl
    
    << fixed << setprecision(2) // set precision to 2 for float datatypes
    
    << setw(COL_ONE) << left << "Course name:"
    << setw(COL_TWO) << right << course << endl
    
    << setw(COL_ONE) << left << "Course ID:"
    << setw(COL_TWO) << right << courseID << endl
    
    << setw(COL_ONE) << left << "Earned score:"
    << setw(COL_TWO) << right << userInput << endl
    
    << setw(COL_ONE) << left << "Letter grade:"
    << setw(COL_TWO) << right << letterGrade << endl
    
    << setw(COL_ONE) << left << "Grade point:"
    << setw(COL_TWO) << right << gradePoint << endl;
    
    // ending statement
    cout << "\nEnd of Wayne State University" << endl;
}
