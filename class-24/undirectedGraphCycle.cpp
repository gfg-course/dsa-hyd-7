#include<bits/stdc++.h>
using namespace std;

bool isCyclicUtil(int u, vector<vector<int>> &adj, vector<bool> &vis, int parent) {
    vis[u] = true;

    for (int v : adj[u]) {
        if (vis[v] && v != parent) {
            return true;
        }
        // INCORRECT!!
        // if (!vis[v]) {
        //     return isCyclicUtil(v, adj, vis, u);
        // }
        if (!vis[v] && isCyclicUtil(v, adj, vis, u)) {
            return true;
        }
    }

    return false;
}

// TC: O(V + E)
// AS: O(V)
bool isCyclic(vector<vector<int>> adj) {

    int V = adj.size();
    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (isCyclicUtil(i, adj, vis, -1)) {
                return true;
            }
        }
    }

    return false;
}

int main() {

    cout << isCyclic({
        {1},
        {0, 4, 2},
        {1, 3},
        {2, 4},
        {3, 1}
    }) << endl;

    cout << isCyclic({
        {1},
        {0},
        {3, 4},
        {2, 4},
        {2, 3}
    }) << endl;

    cout << isCyclic({
        {1, 3},
        {0, 2},
        {1},
        {1, 4, 5},
        {3, 5},
        {3, 4}
    }) << endl;

    cout << isCyclic({
        {1},
        {0},
        {3},
        {2, 4},
        {3}
    }) << endl;
}
