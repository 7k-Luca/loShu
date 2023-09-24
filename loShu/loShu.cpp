#include <iostream>
#include <iomanip>
using namespace std;

// Global Variables
const int rows = 3;
const int columns = 3;
int num = 0;
// function quit
bool function = true;

// Global Array
int square[rows][columns];

// Function Prototypes
void showArray(const int[][columns], int);
void inputArray(const int[][columns], int, int);
void tryAgain();
bool repeats(const int arr[][columns], int x, int y, int n);
void isLoShu(const int arr[][columns]);
void makeEmpty(const int arr[][columns], int rows, int columns);

int main()
{

    // Do-While Function
    do {
        cout << "Lo Shu Square ..." << endl;
        cout << "\nCreating Lo Shu Square ..." << endl;
        cout << "\nEnter Nine Numbers (1-9)" << endl;

        // Calling Functions
        inputArray(square, rows, columns);
        showArray(square, rows);
        isLoShu(square);
        tryAgain();
    } while (function != false);

    return 0;
}

// The showArray function displays the Lo Shu Magic Square
void showArray(const int numbers[rows][columns], int rows2) {
    for (int x = 0; x < rows; x++)
    {
        cout << " -------------" << endl;
        for (int y = 0; y < columns; y++)
        {
            cout << setw(1) << "| " << numbers[x][y] << " |";
        }
        cout << endl;
    }
    cout << setw(4) << " -------------";

}

// The inputArray function asks user to input the number values
void inputArray(const int arr[rows][columns], int rows, int columns) {
    for (int count1 = 0; count1 < rows; count1++)
    {
        for (int count2 = 0; count2 < columns; count2++)
        {
            int n;
            num += 1;
            cout << "\tNumber " << num << ": ";
            cin >> n;
            int x = count1;
            int y = count2;
            while (repeats(square, x, y, n) || (n > 9 || n < 1)) // Checking if the number is valid
            {
                if (n > 9 || n < 1) { // If it is out of 1-9
                    cout << "\tError ... Invalid number. Try again" << endl;
                    cout << "\n\tNumber " << num << ": ";
                    cin >> n;
                }
                if (repeats(square, x, y, n)) { // if it repeats
                    cout << "\tError ... " << n << " is already in the Lo Shu Square. Try again " << endl;
                    cout << "\n\tNumber " << num << ": ";
                    cin >> n;
                }
            }

            square[count1][count2] = n; // Adding the number to the array

        }
    }
    cout << endl;
}

// tryAgain Function either ends the program or keeps it going when finished
void tryAgain() {
    char yesNo;
    cout << "Would you like to try again (y/n)? " << endl;
    cin >> yesNo;
    if (yesNo == 'y')
    {
        function = true;
        num = 0;
        makeEmpty(square, rows, columns);
    }
    else {
        function = false;
    }
}

// repeats Function checks if the inputed value has already been used in the arrays
bool repeats(const int arr[][columns], int x, int y, int n) {
    for (int i = 0; i <= y; i++) {
        for (int j = 0; j <= x; j++) {
            if (square[j][i] == n)
                return true;
        }
    }
    return false;

}

// isLoShu checks if the square makes a lo shu square
void isLoShu(const int arr[rows][columns]) {
    if (((square[0][0] + square[0][1] + square[0][2]) == 15) && ((square[1][0] + square[1][1] + square[1][2]) == 15) && ((square[2][0] + square[2][1] + square[2][2]) == 15) && ((square[0][0] + square[1][1] + square[2][2]) == 15) && ((square[0][2] + square[1][1] + square[2][0]) == 15)) {
        cout << "\n\nThis is a Lo Shu Magic Square !!!" << endl << endl;
    }
    else {
        cout << "\n\nSorry ... this is not a Lo Shu Magic Square" << endl << endl;
    }
}

// makeEmpty empties the arrays in case of a retrial of program
void makeEmpty(const int arr[][columns], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns;j++)
        {
            square[i][j] = '\0';
        }
    }
    return;
}