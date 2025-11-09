#include<bits/stdc++.h>
using namespace std;

// TC: O(n^2)
// AS: O(1)
bool checkTripletSum(vector<int> arr, int target) {

    sort(arr.begin(), arr.end());
    int n = arr.size();

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;
        int newTarget = target - arr[i];

        while (left < right) {
            if (arr[left] + arr[right] == newTarget) {
                return true;
            }
            if (arr[left] + arr[right] > newTarget) {
                right--;
            } else {
                left++;
            }
        }
    }

    return false;
}

int main() {

    cout << checkTripletSum({1, 4, 45, 6, 10, 8}, 13) << endl;
    cout << checkTripletSum({1, 4, 45, 6, 10, 8}, 30) << endl;
}