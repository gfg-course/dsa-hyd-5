#include<bits/stdc++.h>
using namespace std;

int getFirstOcc(vector<int> &arr, int target) {

    int low = 0, high = arr.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            result = mid;
            high = mid - 1;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int getLastOcc(vector<int> &arr, int target) {

    int low = 0, high = arr.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            result = mid;
            low = mid + 1;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

// TC: O(log(n))
// AS: O(1)
vector<int> getFirstAndLastOcc(vector<int> arr, int target) {

    int firstOcc = getFirstOcc(arr, target);

    if (firstOcc == -1) {
        return {-1, -1};
    }

    int lastOcc = getLastOcc(arr, target);

    return {firstOcc, lastOcc};
}

int main() {

    vector<int> res = getFirstAndLastOcc({1, 3, 5, 5, 5, 5, 67, 123, 125}, 5);
    vector<int> res2 = getFirstAndLastOcc({1, 3, 5, 5, 5, 5, 67, 123, 125}, 7);

    cout << res[0] << " " << res[1] << endl;
    cout << res2[0] << " " << res2[1] << endl;
}