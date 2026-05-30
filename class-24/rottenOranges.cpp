#include<bits/stdc++.h>
using namespace std;

int dx[4] = {+1, -1, +0, +0};
int dy[4] = {+0, +0, +1, -1};

bool isSafe(int i, int j, vector<vector<int>> &arr) {
    return
        i >= 0 and i < arr.size() and
        j >= 0 and j < arr[i].size() and
        arr[i][j] == 1;
}

// V = n*m, E = 4*n*m
// TC: O(V + E) = O(nm)
// AS: O(V) = O(nm)
int rottenOranges(vector<vector<int>> arr) {

    int n = arr.size();
    int m = arr[0].size();

    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int> (m, INT_MAX));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 2) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    int result = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int _ = 0; _ < sz; _++) {
            pair<int, int> curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            for (int k = 0; k < 4; k++) {
                int new_i = i + dx[k];
                int new_j = j + dy[k];

                if (isSafe(new_i, new_j, arr) && dist[new_i][new_j] > 1 + dist[i][j]) {
                    arr[new_i][new_j] = 2;
                    dist[new_i][new_j] = 1 + dist[i][j];
                    q.push({new_i, new_j});
                }
            }
        }
        result++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                return -1;
            }
        }
    }

    return result == 0 ? 0 : result - 1;
}

int main() {

    cout << rottenOranges({
        {0, 1, 1, 2},
        {1, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 1, 1, 2}
    }) << endl;

    cout << rottenOranges({
        {1, 1, 1, 2},
        {0, 0, 0, 0},
        {1, 1, 1, 1}
    }) << endl;

    cout << rottenOranges({
        {2, 2, 2, 2}
    }) << endl;

    cout << rottenOranges({
        {1, 1, 1, 1}
    }) << endl;

    cout << rottenOranges({
        {0, 0, 0, 0}
    }) << endl;
}
