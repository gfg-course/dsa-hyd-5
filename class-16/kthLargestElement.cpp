#include<bits/stdc++.h>
using namespace std;

// TC: O(n*log(k))
// AS: O(k)
int kthLargestElement(vector<int> arr, int k) {
    priority_queue <int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < k; i++) {
        min_heap.push(arr[i]);
    }

    for (int i = k; i < arr.size(); i++) {
        if (arr[i] > min_heap.top()) {
            min_heap.pop();
            min_heap.push(arr[i]);
        }
    }

    return min_heap.top();
}

int main() {

    cout << kthLargestElement({3, 5, 4, 2, 9}, 3) << endl;
}
