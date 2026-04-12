#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, int n, vector<string> &curr) {

    // col check.
    for (int r = 0; r < n; r++) {
        if (curr[r][j] == 'Q') {
            return false;
        }
    }

    // diagonal check.
    for (int r = 0; r <= i - 1; r++) {
        for (int c = 0; c < n; c++) {
            if (curr[r][c] == 'Q') {
                if (abs(r - i) == abs(c - j)) {
                    return false;
                }
            }
        }
    }

    return true;
}

void nQueensUtil(int i, int n, vector<string> &curr, vector<vector<string>> &res) {
    if (i == n) {
        res.push_back(curr);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isSafe(i, j, n, curr)) {
            curr[i][j] = 'Q';
            nQueensUtil(i + 1, n, curr, res);
            curr[i][j] = '.';
        }
    }
}

vector<vector<string>> nQueens(int n) {
    vector<string> curr;
    string row = "";
    for (int i = 0; i < n; i++) {
        row += ".";
    }
    for (int i = 0; i < n; i++) {
        curr.push_back(row);
    }

    vector<vector<string>> res;
    nQueensUtil(0, n, curr, res);
    return res;
}

int main() {

    vector<vector<string>> res = nQueens(6);
    for (vector<string> i : res) {
        for (string j : i) {
            cout << j << endl;
        }
        cout << endl;
    }
}
