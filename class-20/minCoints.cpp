#include<bits/stdc++.h>
using namespace std;

int getMinCoinsUtil(int i, vector<int> &coins, int value, vector<vector<int>> &memo) {
    if (value == 0) {
        return 0;
    }
    if (i == coins.size()) {
        return -1;
    }
    if (memo[i][value] != -2) {
        return memo[i][value];
    }

    int exc = getMinCoinsUtil(i + 1, coins, value, memo); // exclude.
    int inc = -1;

    // include if possible.
    if (coins[i] <= value) {
       inc = getMinCoinsUtil(i, coins, value - coins[i], memo);
    }

    int result = -1;
    if (exc == -1 && inc == -1) {
        result = -1;
    } else if (inc == -1) {
        result = exc;
    } else if (exc == -1) {
        result = 1 + inc;
    } else {
        result = min(exc, 1 + inc);
    }
    memo[i][value] = result;
    return memo[i][value];
}

// TC: O(n * value)
// AS: O(n * value)
int getMinCoins(vector<int> coins, int value) {
    int n = coins.size();
    vector<vector<int>> memo(n, vector<int> (value + 1, -2));
    return getMinCoinsUtil(0, coins, value, memo);
}

int main() {
    cout << getMinCoins({3, 6, 3}, 10) << endl;
    cout << getMinCoins({2, 3, 5, 6}, 10) << endl;
}
