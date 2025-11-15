#include<bits/stdc++.h>
using namespace std;

// TODO: Painter's parition problem.

// Checks if it is possible to allocation books to M students such that no
// student gets more than mid number of pages.
bool isPossible(vector<int> &arr, int M, int mid) {

    int numStudents = 1, numPages = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] + numPages <= mid) {
            numPages += arr[i];
        } else {
            numStudents++;
            numPages = arr[i];
        }
    }

    return numStudents <= M;
}

// TC: O(n * log(sum))
// AS: O(1)
int getMinPages(vector<int> arr, int M) {

    int n = arr.size();

    if (M > n) {
        return -1;
    }

    int low = arr[0], high = arr[0];
    for (int i = 1; i < n; i++) {
        low = max(low, arr[i]);
        high += arr[i];
    }   

    int result = high;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, M, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {

    cout << getMinPages({12, 34, 67, 90}, 2) << endl;
    cout << getMinPages({10, 20, 10, 30}, 2) << endl;
    cout << getMinPages({10, 20, 10, 30}, 1) << endl;
    cout << getMinPages({10, 20, 10, 30}, 4) << endl;
    cout << getMinPages({10, 20, 10, 30}, 5) << endl;
}