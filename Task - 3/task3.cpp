#include <iostream>
using namespace std;
const int SIZE = 9;

// Function to print the board
void printBoard(int board[SIZE][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        if (row % 3 == 0 && row != 0)
        {
            cout << "---------------------" << endl;
        }
        for (int col = 0; col < SIZE; col++)
        {
            if (col % 3 == 0 && col != 0)
            {
                cout << "| ";
            }
            if (board[row][col] == 0)
                cout << ". ";
            else
                cout << board[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
// Function to check if placing a number is valid
bool check(int board[SIZE][SIZE], int row, int col, int num)
{
    // Check row
    for (int x = 0; x < SIZE; ++x)
    {
        if (board[row][x] == num)
            return false;
    }

    // Check column
    for (int x = 0; x < SIZE; ++x)
    {
        if (board[x][col] == num)
            return false;
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3, startCol = col - col % 3; // to know the initial row,col of the subgrid
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i + startRow][j + startCol] == num)
                return false;
        }
    }

    return true;
}

// Function to find if the board is completely filled
bool isComplete(int board[SIZE][SIZE])
{
    for (int row = 0; row < SIZE; ++row)
    {
        for (int col = 0; col < SIZE; ++col)
        {
            if (board[row][col] == 0)
                return false;
        }
    }
    return true;
}

int main()
{
    int board[SIZE][SIZE] = {
        {3, 1, 6, 5, 0, 8, 4, 9, 2},
        {5, 2, 9, 1, 3, 4, 7, 6, 8},
        {4, 8, 7, 6, 2, 9, 5, 3, 1},
        {2, 6, 3, 0, 1, 5, 9, 8, 7},
        {9, 7, 4, 8, 6, 0, 1, 2, 5},
        {8, 5, 1, 7, 9, 2, 6, 4, 3},
        {1, 3, 8, 0, 4, 7, 2, 0, 6},
        {6, 9, 2, 3, 5, 1, 8, 7, 4},
        {7, 4, 5, 2, 8, 6, 3, 1, 9}};

    int row, col, num;
    char quit;
    while (true)
    {
        cout << "*** Sudoku Puzzle ***" << endl
             << endl;
        printBoard(board);

        if (isComplete(board))
        {
            cout << "Congratulations! You have solved the Sudoku puzzle!" << endl;
            break;
        }
        cout << "Instructions to solve the puzzle" << endl;
        cout << ">>> you can place numbers only where there is dot (.) in the board" << endl;
        cout << ">>> Enter the row no (1-9), column no (1-9), and number (1-9) you want to palce\n";
        cout << ">>> Follow this format: separate row, column, and number by spaces (e.g 1 1 5) " << endl
             << endl;
        cin >> row >> col >> num;
        row--; // As it's 0-indexed array
        col--; // As it's 0-indexed array

        if (row >= SIZE || col >= SIZE || num > 9)
        {
            cout << "Invalid input! Please enter numbers within the valid range(1-9)." << endl;
            continue;
        }

        if (board[row][col] != 0)
        {
            cout << "Cell already filled! Choose another cell." << endl;
            continue;
        }

        if (check(board, row, col, num))
        {
            board[row][col] = num;
            cout << "Wow champ!!! it's a great move" << endl;
            cout << "Do you want to continue? ('y' / 'n') " << endl;
            cin >> quit;
            if (quit == 'n')
            {
                break;
            }
        }
        else
        {
            cout << "Invalid move! " << endl;
        }
    }
    return 0;
}