#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
bool checkSubarrayWithGivenSum(vector<int> arr, int x) {

    int currentSum = 0;
    unordered_set<int> prefixSums;

    prefixSums.insert(currentSum);

    for (int i = 0; i < arr.size(); i++) {
        currentSum += arr[i];

        // Checking if currentSum if present in the prefixSums hashset or not.
        if (prefixSums.find(currentSum - x) != prefixSums.end()) {
            return true;
        }

        prefixSums.insert(currentSum);
    }

    return false;
}

vector<int> getSubarrayWithGivenSum(vector<int> arr, int x) {

    int currentSum = 0;
    unordered_map<int, int> prefixSumsToIndex;

    prefixSumsToIndex.insert({currentSum, -1});

    for (int i = 0; i < arr.size(); i++) {
        currentSum += arr[i];

        // Checking if currentSum if present in the prefixSums hashset or not.
        if (prefixSumsToIndex.find(currentSum - x) != prefixSumsToIndex.end()) {
            return {prefixSumsToIndex[currentSum - x] + 1, i};
        }

        prefixSumsToIndex.insert({currentSum, i});
    }

    return {-1, -1};
}

int main() {

    cout << checkSubarrayWithGivenSum({1, 2, 1, 3, 5, 6}, 12) << endl;
    cout << checkSubarrayWithGivenSum({1, 2, 1, 3, 5, 6}, 7) << endl;
    cout << checkSubarrayWithGivenSum({1, 2, 1, 3, 5, 6}, 0) << endl;

    vector<int> res1 = getSubarrayWithGivenSum({1, 2, 1, 3, 5, 6}, 12);
    vector<int> res2 = getSubarrayWithGivenSum({1, 2, 1, 3, 5, 6}, 7);
    vector<int> res3 = getSubarrayWithGivenSum({1, 2, 1, 3, 5, 6}, 8);
    vector<int> res4 = getSubarrayWithGivenSum({1, 2, 1, 3, 5, 6}, 0);

    cout << res1[0] << " " << res1[1] << endl;
    cout << res2[0] << " " << res2[1] << endl;
    cout << res3[0] << " " << res3[1] << endl;
    cout << res4[0] << " " << res4[1] << endl;
}