#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
bool checkPairSum(vector<int> arr, int target) {

    int left = 0, right = arr.size() - 1;

    while (left < right) {
        if (arr[left] + arr[right] == target) {
            return true;
        }
        if (arr[left] + arr[right] > target) {
            right--;
        } else {
            left++;
        }
    }

    return false;
}

int main() {
    cout << checkPairSum({1, 2, 5, 6, 10}, 8) << endl;
    cout << checkPairSum({1, 2, 4, 10}, 8) << endl;
    cout << checkPairSum({1, 2, 4, 4, 10}, 8) << endl;
}