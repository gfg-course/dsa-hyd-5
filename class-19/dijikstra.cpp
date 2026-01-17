#include<bits/stdc++.h>
using namespace std;


// edge = {u, v, w}
vector<vector<pair<int, int>>> buildAdj(vector<vector<int>> &edges, int V) {
    vector<vector<pair<int, int>>> adj(V);

    for (vector<int> edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    return adj;
}

vector<int> dijiktra(int V, vector<vector<int>> edges, int source) {

    vector<vector<pair<int, int>>> adj = buildAdj(edges, V);

    vector<int> dist(V, INT_MAX);
    dist[source] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();

        int distU = curr.first;
        int u = curr.second;

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

    vector<int> res = dijiktra(9, {{0, 1, 4}, {0, 7, 8}, {1, 7, 11}, {1, 2, 8}, {7, 8, 7},
                             {7, 6, 1}, {2, 8, 2}, {8, 6, 6}, {2, 5, 4}, {2, 3, 7},
                             {6, 5, 2}, {3, 5, 14}, {3, 4, 9}, {4, 5, 10}}, 0);
    
    for (int i = 0; i < res.size(); i++) {
        cout << i << ": " << res[i] << endl;
    }
}
