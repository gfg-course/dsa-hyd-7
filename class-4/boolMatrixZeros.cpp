#include<bits/stdc++.h>
using namespace std;

// TC: O(nm)
// AS: O(1)
void setMatrixZeros(vector<vector<int>> &arr) {

    int n = arr.size();
    int m = arr[0].size();

    bool firstRowZero = false;
    bool firstColZero = false;

    // col
    for (int i = 0; i < n; i++) {
        if (arr[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }

    // row
    for (int j = 0; j < m; j++) {
        if (arr[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 0) {
                arr[i][0] = 0; // row bucket
                arr[0][j] = 0; // col bucket
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][0] == 0 || arr[0][j] == 0) {
                arr[i][j] = 0;
            }
        }
    }

    if (firstColZero) {
        for (int i = 0; i < n; i++) {
            arr[i][0] = 0;
        }
    }

    if (firstRowZero) {
        for (int j = 0; j < m; j++) {
            arr[0][j] = 0;
        }
    }
}

int main() {

    vector<vector<int>> arr = {{1, 1, 0, 1, 1},
                                {1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1},
                                {0, 1, 1, 0, 1}};
    
    setMatrixZeros(arr);

    for (auto i : arr) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
