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

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfsUtil(i, adj, vis);
        }
    }
}

int main() {

    dfs({{1, 2},
         {0, 3, 4},
         {0},
         {1, 5},
         {1, 5},
         {3, 4},
         {7},
         {6}});
}
