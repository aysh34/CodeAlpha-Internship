#include <iostream>

using namespace std;

const int SIZE = 9;

// Function to print the board
void Board(int board[SIZE][SIZE])
{
    for (int row = 0; row < SIZE; ++row)
    {
        for (int col = 0; col < SIZE; ++col)
        {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to check if placing a number is valid
bool isValid(int board[SIZE][SIZE], int row, int col, int num)
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
    int startRow = row - row % 3, startCol = col - col % 3;
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

// Function to find an empty cell
bool findEmptyCell(int board[SIZE][SIZE], int &row, int &col)
{
    for (row = 0; row < SIZE; ++row)
    {
        for (col = 0; col < SIZE; ++col)
        {
            if (board[row][col] == 0)
                return true;
        }
    }
    return false;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int board[SIZE][SIZE])
{
    int row, col;

    // If no empty cell is found, the puzzle is solved
    if (!findEmptyCell(board, row, col))
        return true;

    // Try placing numbers 1 to 9 in the empty cell
    for (int num = 1; num <= 9; ++num)
    {
        if (isValid(board, row, col, num))
        {
            board[row][col] = num;

            // Recursively attempt to solve the rest of the puzzle
            if (solveSudoku(board))
                return true;

            // If no solution is found, backtrack
            board[row][col] = 0;
        }
    }
    return false; // Trigger backtracking
}
int main()
{
    int board[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 1, 2},
        {6, 0, 0, 1, 9, 5, 0, 0, 8},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 5, 0, 0, 6, 0, 0, 0, 3},
        {4, 2, 0, 8, 0, 3, 0, 0, 1},
        {7, 1, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 4, 5, 0, 8, 0, 0, 7, 9}};

    cout << "Sudoku Puzzle:" << endl;
    Board(board);

    if (solveSudoku(board))
    {
        cout << "\nSolved Sudoku puzzle" << endl;
        Board(board);
    }
    else
    {
        cout << "\nNo solution exists" << endl;
    }

    return 0;
}
