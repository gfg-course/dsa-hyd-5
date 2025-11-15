#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int removeDuplicatesAndReturnSize(vector<int> &arr) {

    int n = arr.size();

    int i = 0;
    int j = 0;

    while (i < n) {
        // i is at the first occ of a new element.
        // j is at the pos where the first occ should come at.

        arr[j] = arr[i];
        
        while (i < n && arr[i] == arr[j]) {
            i++;
        }
        j++;
    }

    return j;
}

int main() {

    vector<int> arr = {1, 1, 2, 3, 3, 3, 4, 7};
    int size = removeDuplicatesAndReturnSize(arr);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}