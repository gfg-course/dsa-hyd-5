#include<bits/stdc++.h>
using namespace std;

int editDistance(int i, int j, string &s1, string &s2, vector<vector<int>> &memo) {
    if (i == s1.length()) {
        return s2.length() - j;
    }
    if (j == s2.length()) {
        return s1.length() - i;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (s1[i] == s2[j]) {
        memo[i][j] = editDistance(i + 1, j + 1, s1, s2, memo);
        return memo[i][j];
    }

    int insert = editDistance(i, j + 1, s1, s2, memo);
    int del = editDistance(i + 1, j, s1, s2, memo);
    int replace = editDistance(i + 1, j + 1, s1, s2, memo);

    memo[i][j] = 1 + min({insert, del, replace});
    return memo[i][j];
}

// TC:
// Rec: O(3^max(n,m))
// DP: O(nm)
// AS:
// Rec: O(max(n, m))
// DP: O(nm)
int editDistance(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> memo(n, vector<int> (m, -1));
    return editDistance(0, 0, s1, s2, memo);
}

int main() {

    cout << editDistance("abad", "abac") << endl;
    cout << editDistance("anshuman", "antihuman") << endl;
}
