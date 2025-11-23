#include<bits/stdc++.h>
using namespace std;

void combinationSumUtil(int i, vector<int> &arr, int target, vector<int> &curr, vector<vector<int>> &result) {
    if (target == 0) {
        result.push_back(curr);
        return;
    }
    if (i == arr.size()) {
        return;
    }

    // skip arr[i]
    combinationSumUtil(i + 1, arr, target, curr, result);

    // consider arr[i]
    if (target >= arr[i]) {
        curr.push_back(arr[i]);
        combinationSumUtil(i, arr, target - arr[i], curr, result);
        curr.pop_back();
    }
}


// Height H = max(n, target)
// TC: O(2^(max(n, target)))
// AS: O(max(n, target))
vector<vector<int>> combinationSum(vector<int> arr, int target) {

    vector<int> curr;
    vector<vector<int>> result;

    combinationSumUtil(0, arr, target, curr, result);

    return result;
}

int main() {
    vector<vector<int>> result = combinationSum({2, 4, 6, 8}, 8);

    for (auto i : result) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
