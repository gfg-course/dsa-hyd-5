#include<bits/stdc++.h>
using namespace std;

// TODO: Find the answer till the first decimal place.

// TC: O(log(n))
// AS: O(1)
int sqrt(int n) {

    int result = n;
    int low = 1, high = n;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (mid * mid == n) {
            return mid;
        }
        if (mid * mid < n) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {

    cout << sqrt(30) << endl;
    cout << sqrt(16) << endl;
}