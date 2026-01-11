#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, vector<vector<int>> &arr) {
    return
        i >= 0 && i < arr.size() &&
        j >= 0 && j < arr[i].size() &&
        arr[i][j] == 1;
}

int dx[8] = {-1, -1, +0, +1, +1, +1, +0, -1};
int dy[8] = {+0, +1, +1, +1, +0, -1, -1, -1};
void dfsUtil(int i, int j, vector<vector<int>> &arr) {

    arr[i][j] = 0;

    for (int k = 0; k < 8; k++) {
        if (isSafe(i + dx[k], j + dy[k], arr)) {
            dfsUtil(i + dx[k], j + dy[k], arr);
        }
    }
}

// TC: O(n*m)
// AS: O(n*m)
int countIslands(vector<vector<int>> arr) {

    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == 1) {
                count++;
                dfsUtil(i, j, arr);
            }
        }
    }

    return count;
}

int main() {
}
