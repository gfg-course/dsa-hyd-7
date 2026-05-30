#include<bits/stdc++.h>
using namespace std;

void addUndirectedEdge(vector<vector<pair<int, int>>> &adj, int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

vector<int> dijikstra(vector<vector<pair<int, int>>> adj, int source) {

    int V = adj.size();
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // min-heap to store {dist, node}
    vector<int> dist(V, INT_MAX);

    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();

        int u = curr.second;
        int distU = curr.first;

        for (pair<int, int> neighbor : adj[u]) {
            int v = neighbor.first;
            int distUV = neighbor.second;

            if (dist[v] > distU + distUV) {
                dist[v] = distU + distUV;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    vector<vector<pair<int, int>>> adj(9);

    addUndirectedEdge(adj, 0, 1, 4);
    addUndirectedEdge(adj, 0, 7, 8);
    addUndirectedEdge(adj, 1, 7, 11);
    addUndirectedEdge(adj, 1, 2, 8);
    addUndirectedEdge(adj, 7, 8, 7);
    addUndirectedEdge(adj, 7, 6, 1);
    addUndirectedEdge(adj, 2, 8, 2);
    addUndirectedEdge(adj, 6, 8, 6);
    addUndirectedEdge(adj, 2, 3, 7);
    addUndirectedEdge(adj, 2, 5, 4);
    addUndirectedEdge(adj, 6, 5, 2);
    addUndirectedEdge(adj, 3, 5, 14);
    addUndirectedEdge(adj, 3, 4, 9);
    addUndirectedEdge(adj, 5, 4, 10);

    vector<int> distances = dijikstra(adj, 0);
    for (int i = 0; i < distances.size(); i++) {
        cout << i << " -> " << distances[i] << endl;
    }
}
