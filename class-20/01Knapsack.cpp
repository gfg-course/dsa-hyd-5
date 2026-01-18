#include<bits/stdc++.h>
using namespace std;

int knapsackUtil(int i, vector<int> &vals, vector<int> &wts, int W, vector<vector<int>> &memo) {
    if (W == 0) {
        return 0;
    }
    if (i == vals.size()) {
        return 0;
    }
    if (memo[i][W] != -1) {
        return memo[i][W];
    }

    int result = knapsackUtil(i + 1, vals, wts, W, memo);
    if (wts[i] <= W) {
        result =  max(result, vals[i] + knapsackUtil(i + 1, vals, wts, W - wts[i], memo));
    }

    memo[i][W] = result;
    return result;
}

// TC:
// Rec: O(2^n)
// With DP: O(n*W)
// AS:
// Rec: O(n)
// With DP: O(n*W)
int knapsack(vector<int> vals, vector<int> wts, int W) {
    int n = vals.size();
    vector<vector<int>> memo(n, vector<int> (W + 1, -1));
    return knapsackUtil(0, vals, wts, W, memo);
}

int main() {

    cout << knapsack({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << knapsack({60, 100, 120}, {10, 20, 50}, 50) << endl;
}
