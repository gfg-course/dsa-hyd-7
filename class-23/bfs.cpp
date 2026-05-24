#include<bits/stdc++.h>
using namespace std;

// TC: O(V + E)
// AS: O(V)
void bfsUtil(vector<vector<int>> adj, int source, vector<bool> &vis) {
    int V = adj.size();
    queue<int> q;

    q.push(source);
    vis[source] = true;

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

void bfs(vector<vector<int>> adj) {
    int V = adj.size();
    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            bfsUtil(adj, i, vis);
        }
    }
}

int main() {

    bfs({
        {1},
        {0, 2, 5},
        {1, 3},
        {2, 4},
        {3, 5, 6},
        {4, 6},
        {4, 5},
        {8},
        {7}
    });
}
