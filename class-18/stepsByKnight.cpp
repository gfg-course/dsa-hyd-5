#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, int n, vector<vector<bool>> &vis) {
    return
        i >= 0 && i < n &&
        j >= 0 && j < n &&
        vis[i][j] == false;
}


// TC: O(V + E) = O(n^2)
// AS: O(V) = O(n^2)
int dx[8] = {-2, -1, +1, +2, +2, +1, -1, -2};
int dy[8] = {+1, +2, +2, +1, -1, -2, -2, -1};
int getMinimumJumpsByKnight(pair<int, int> start, pair<int, int> target, int n) {
    // Converting the coordinates to 0-based indexing.
    start.first--;
    start.second--;
    target.first--;
    target.second--;

    vector<vector<bool>> vis(n, vector<bool>(n, false));

    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = true;

    int count = 0;
    while (!q.empty()) {

        int sz = q.size();
        for (int _ = 0; _ < sz; _++) {
            pair<int, int> curr = q.front();
            q.pop();

            if (curr == target) {
                return count;
            }

            int i = curr.first;
            int j = curr.second;

            for (int k = 0; k < 8; k++) {
                if (isSafe(i + dx[k], j + dy[k], n, vis)) {
                    vis[i + dx[k]][j + dy[k]] = true;
                    q.push({i + dx[k], j + dy[k]});
                }
            }
        }
        count++;
    }

    return -1;
}

int main() {

    cout << getMinimumJumpsByKnight({3, 3}, {1, 2}, 3) << endl;
    cout << getMinimumJumpsByKnight({4, 5}, {1, 1}, 6) << endl;
}
