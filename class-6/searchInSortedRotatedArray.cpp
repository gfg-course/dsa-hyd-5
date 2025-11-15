#include<bits/stdc++.h>
using namespace std;

// TODO: Solve via 3 binary search approach
// Step-1: Find the pivot (smallest element)
// Step-2: Binary Search in the left half.
// Step-3: Binary Search in the right half.

// TC: O(log(n))
// AS: O(1)
int searchInSortedRotatedArray(vector<int> arr, int target) {

    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] >= arr[low]) { // LH is sorted.
            if (target >= arr[low] && target <= arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else { // RH is sorted
            if (target >= arr[mid] && target <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {

    cout << searchInSortedRotatedArray({5, 6, 7, 8, 9, 10, 1, 2, 3}, 7) << endl;
    cout << searchInSortedRotatedArray({5, 6, 7, 8, 9, 10, 1, 2, 3}, 5) << endl;
    cout << searchInSortedRotatedArray({5, 6, 7, 8, 9, 10, 1, 2, 3}, 3) << endl;
    cout << searchInSortedRotatedArray({5, 6, 7, 8, 9, 10, 1, 2, 3}, 11) << endl;
    cout << searchInSortedRotatedArray({5, 6, 7, 8, 9, 10, 1, 2, 3}, 0) << endl;
    cout << searchInSortedRotatedArray({5, 6, 7, 8, 9, 10, 1, 2, 3}, 4) << endl;
}