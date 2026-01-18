#include<bits/stdc++.h>
using namespace std;

// TC: O(nm)
// AS: O(nm)
int lcsBottomUp(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1));

    // Fill for the base cases.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 0;
    }

    // Fill the rest of the values.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int lcsUtil(int i, int j, string &s1, string &s2, vector<vector<int>> &memo) {
    if (i == s1.length() || j == s2.length()) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (s1[i] == s2[j]) {
        memo[i][j] = 1 + lcsUtil(i + 1, j + 1, s1, s2, memo);
        return memo[i][j];
    }

    memo[i][j] = max(lcsUtil(i + 1, j, s1, s2, memo), lcsUtil(i, j + 1, s1, s2, memo));
    return memo[i][j];
}

// TC: O(nm)
// AS: O(nm)
int lcs(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    vector<vector<int>> memo(n, vector<int> (m, -1));
    int res = lcsUtil(0, 0, s1, s2, memo);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }
    return res;
}

int main() {

    cout << lcsBottomUp("abcdgh", "aedfhr") << endl;
    cout << lcsBottomUp("abc", "ac") << endl;
    cout << lcsBottomUp("abc", "def") << endl;
}
