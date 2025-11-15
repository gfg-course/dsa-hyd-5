#include<bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)
bool binarySearch(vector<int> arr, int target) {

    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return true;
        }

        if (arr[mid] > target) { // discard the RH
            high = mid - 1;
        } else { // discard the LH
            low = mid + 1;
        }
    }

    return false;
}

int main() {
    cout << binarySearch({1, 3, 5, 8, 11, 15, 25}, 11) << endl;
    cout << binarySearch({1, 3, 5, 8, 11, 15, 25}, 10) << endl;
    cout << binarySearch({1, 3, 5, 8, 11, 15, 25}, 0) << endl;
    cout << binarySearch({1, 3, 5, 8, 11, 15, 25}, 100) << endl;
}