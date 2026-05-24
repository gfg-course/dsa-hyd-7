#include<bits/stdc++.h>
using namespace std;

int dx[8] = {-2, -1, +1, +2, +2, +1, -1, -2};
int dy[8] = {+1, +2, +2, +1, -1, -2, -2, -1};

bool isSafe(int i, int j, int n, vector<vector<bool>> &vis) {
    return
        i >= 0 && i < n &&
        j >= 0 && j < n &&
        !vis[i][j];
}

// For BFS
// TC: O(V + E)
// AS: O(V)
// For this problem,
// V = n^2
// E = 8*n^2
// TC: O(n^2)
// AS: O(n^2)
int getShortestDistByKnight(int n, pair<int, int> source, pair<int, int> target) {
    // Converting 1-based positions to 0-based positions.
    source.first--;
    source.second--;
    target.first--;
    target.second--;

    vector<vector<bool>> vis(n, vector<bool> (n, false));
    queue<pair<int, int>> q;

    vis[source.first][source.second] = true;
    q.push(source);

    int currentLevel = 0;

    while (!q.empty()) {
        int sz = q.size();
        for (int _ = 0; _ < sz; _++) {

            pair<int, int> curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            if (i == target.first && j == target.second) {
                return currentLevel;
            }

            for (int k = 0; k < 8; k++) {
                int new_i = i + dx[k];
                int new_j = j + dy[k];

                if (isSafe(new_i, new_j, n, vis)) {
                    vis[new_i][new_j] = true;
                    q.push({new_i, new_j});
                }
            }
        }
        currentLevel++;
    }

    return -1;
}

int main() {

    cout << getShortestDistByKnight(3, {3, 3}, {1, 2}) << endl;
    cout << getShortestDistByKnight(6, {4, 5}, {1, 1}) << endl;
}
