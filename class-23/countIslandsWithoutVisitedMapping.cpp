#include<bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, +0, +1, +1, +1, +0, -1};
int dy[8] = {+0, +1, +1, +1, +0, -1, -1, -1};

bool isSafe(int i, int j, vector<vector<int>> &arr) {
    return
        i >= 0 && i < arr.size() &&
        j >= 0 && j < arr[i].size() &&
        arr[i][j] == 1;
}

void dfsUtil(int i, int j, vector<vector<int>> &arr) {
    arr[i][j] = 0;

    for (int k = 0; k < 8; k++) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];

        if (isSafe(new_i, new_j, arr)) {
            dfsUtil(new_i, new_j, arr);
        }
    }
}

// TC: O(V + E) for DFS
// V = n*m
// E = 8*n*m
// Our TC: O(9*n*m) = O(nm)
// AS: O(nm)
int countIslands(vector<vector<int>> arr) {

    int n = arr.size();
    int m = arr[0].size();

    int componentCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                componentCount++;
                dfsUtil(i, j, arr);
            }
        }
    }

    return componentCount;
}

int main() {

    cout << countIslands({
        {0, 1, 0, 1, 1, 0, 1},
        {0, 0, 1, 0, 1, 0, 0}
    }) << endl;
}
