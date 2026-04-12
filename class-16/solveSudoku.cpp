#include<bits/stdc++.h>
using namespace std;

bool isSafe(int num, vector<vector<int>> &arr, int i, int j) {
    // row check.
    for (int c = 0; c < 9; c++) {
        if (arr[i][c] == num) {
            return false;
        }
    }

    // col check.
    for (int r = 0; r < 9; r++) {
        if (arr[r][j] == num) {
            return false;
        }
    }

    // 3x3 grid check.
    int row = i - i%3;
    int col = j - j%3;

    for (int r = row; r < row + 3; r++) {
        for (int c = col; c < col + 3; c++) {
            if (arr[r][c] == num) {
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolverUtil(int i, int j, vector<vector<int>> &arr) {
    if (i == 8 && j == 9) {
        return true;
    }

    if (j == 9) {
        i++;
        j = 0;
    }

    if (arr[i][j] != 0) {
        return sudokuSolverUtil(i, j + 1, arr);
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(num, arr, i, j)) {
            arr[i][j] = num;
            if (sudokuSolverUtil(i, j + 1, arr)) {
                return true;
            }
            arr[i][j] = 0;
        }
    }

    return false; 
}

// TC: O(9^m)
// AS: O(m)
// where m is the number of unfilled cells.
void sudokuSolver(vector<vector<int>> &arr) {
    cout << sudokuSolverUtil(0, 0, arr) << endl;
}

int main() {

    vector<vector<int>> arr = {{3, 0, 6, 5, 7, 8, 4, 0, 0},
                               {5, 2, 0, 0, 0, 0, 0, 0, 0},
                               {0, 8, 7, 0, 0, 0, 0, 3, 1},
                               {0, 0, 3, 0, 1, 0, 0, 8, 0},
                               {9, 0, 0, 8, 6, 3, 0, 0, 5},
                               {0, 5, 0, 0, 9, 0, 6, 0, 0},
                               {1, 3, 0, 0, 0, 0, 2, 5, 0},
                               {0, 0, 0, 0, 0, 0, 0, 7, 4},
                               {0, 0, 5, 2, 8, 6, 3, 0, 0}};

    sudokuSolver(arr);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
