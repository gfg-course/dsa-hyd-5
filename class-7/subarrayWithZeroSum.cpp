#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
bool checkSubarrayWithZeroSum(vector<int> arr) {

    int currentSum = 0;
    unordered_set<int> prefixSums;

    prefixSums.insert(currentSum);

    for (int i = 0; i < arr.size(); i++) {
        currentSum += arr[i];

        // Checking if currentSum if present in the prefixSums hashset or not.
        if (prefixSums.find(currentSum) != prefixSums.end()) {
            return true;
        }

        prefixSums.insert(currentSum);
    }

    return false;
}

int main() {

    cout << checkSubarrayWithZeroSum({4, 2, -3, 1, 6}) << endl;
    cout << checkSubarrayWithZeroSum({4, 2, 0, 1, 6}) << endl;
    cout << checkSubarrayWithZeroSum({4, 2, 1, 1, 6}) << endl;
    cout << checkSubarrayWithZeroSum({1, 2, -1, -2}) << endl;
}