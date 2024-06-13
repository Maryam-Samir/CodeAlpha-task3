#include <iostream>
#include <vector>

using namespace std;

const int GRID_SIZE = 9;

vector<vector<int>> grid(GRID_SIZE, vector<int>(GRID_SIZE));

bool isSafe(int row, int col, int num) {
    // Check row
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }

    // Check 3x3 box
    int boxRow = (row / 3) * 3;
    int boxCol = (col / 3) * 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

void printGrid() {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool solveSudoku() {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= GRID_SIZE; num++) {
                    if (isSafe(row, col, num)) {
                        cout << "Trying to place " << num << " at (" << row << ", " << col << ")" << endl;
                        grid[row][col] = num;
                        if (solveSudoku()) {
                            return true;
                        }
                        grid[row][col] = 0;
                    }
                }
                cout << "No valid placement found at (" << row << ", " << col << ")" << endl;
                return false;
            }
        }
    }
    cout << "Sudoku puzzle solved!" << endl;
    printGrid();
    return true;
}

int main() {
    cout << "Enter the Sudoku grid to be equal columns and rows (0 for empty cells):" << endl;
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            cin >> grid[row][col];
        }
    }

    if (!solveSudoku()) {
        cout << "Unable to solve the Sudoku puzzle." << endl;
    }
    return 0;
}