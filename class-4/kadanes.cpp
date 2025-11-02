#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
int maxSubarraySum(vector<int> arr) {
    int n = arr.size();

    vector<int> maxTillIndex(n);

    maxTillIndex[0] = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        maxTillIndex[i] = max(arr[i], maxTillIndex[i - 1] + arr[i]);
        result = max(result, maxTillIndex[i]);
    }

    return result;
}

// TC: O(n)
// AS: O(1)
int maxSubarraySumSpaceOptimal(vector<int> arr) {
    int n = arr.size();

    int maxTillIndex = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        maxTillIndex = max(arr[i], maxTillIndex + arr[i]);
        result = max(result, maxTillIndex);
    }

    return result;
}

int main() {

    cout << maxSubarraySumSpaceOptimal({-5, 1, 2, 3, -9, 5}) << endl;
    cout << maxSubarraySumSpaceOptimal({-5, -1, -2}) << endl;
}