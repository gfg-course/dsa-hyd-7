#include<bits/stdc++.h>
using namespace std;

void dfsUtil(int u, vector<vector<int>> &adj, vector<bool> &vis) {

    vis[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!vis[v]) {
            dfsUtil(v, adj, vis);
        }
    }
}

// TC: O(V + E)
// AS: O(V)
void dfs(vector<vector<int>> adj) {
    int V = adj.size();
    vector<bool> vis(V, false);

    int componentCount = 0;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            componentCount++;
            dfsUtil(i, adj, vis);
        }
    }

    cout << endl << componentCount;
}

int main() {

    dfs({
        {1, 2},
        {0, 2, 3, 4},
        {0, 1, 4},
        {1, 4},
        {1, 2, 3},
        {6},
        {5}
    });
}
