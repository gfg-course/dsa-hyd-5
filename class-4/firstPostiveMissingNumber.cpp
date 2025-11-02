#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int firstPositiveMissingNumber(vector<int> arr) {

    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (arr[i] <= 0) {
            arr[i] = n + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = abs(arr[i]) - 1;
        if (bucketIndex < n && arr[bucketIndex] > 0) {
            arr[bucketIndex] *= -1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {

    cout << firstPositiveMissingNumber({-20, -10, 0, 1, 1, 2, 3, 5}) << endl;
    cout << firstPositiveMissingNumber({50, 52, 53}) << endl;
}