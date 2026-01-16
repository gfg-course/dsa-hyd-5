#include<bits/stdc++.h>
using namespace std;

bool isCyclicUtil(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &recStack) {
    
    vis[u] = true;
    recStack[u] = true;

    for (int v : adj[u]) {
        if (recStack[v]) {
            return true;
        }
        if (!vis[v] && isCyclicUtil(v, adj, vis,recStack)) {
            return true;
        }
    }

    recStack[u] = false;
    return false;
}

// TC: O(V + E)
// AS: O(V)
bool isCyclic(vector<vector<int>> adj) {

    int V = adj.size();
    vector<bool> vis(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (isCyclicUtil(i, adj, vis, recStack)) {
                return true;
            }
        }
    }

    return false;
}

int main() {

    cout << isCyclic({{1},
                    {2},
                    {3},
                    {3}}) << endl;
    
    cout << isCyclic({{1},
                    {2},
                    {}}) << endl;
}
