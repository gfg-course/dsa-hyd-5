#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(k)
vector<int> slidingWindowMax(vector<int> arr, int k) {
    int n = arr.size();

    deque<int> dq;
    vector<int> res;

    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    res.push_back(arr[dq.front()]);

    for (int i = k; i < n; i++) {
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        if (dq.front() <= i - k) {
            dq.pop_front();
        }

        res.push_back(arr[dq.front()]);
    }

    return res;
}

int main() {

    vector<int> res = slidingWindowMax({8, 5, 10, 7, 9, 4, 9, 12, 90, 13}, 4);
    for (int i : res) {
        cout << i << " ";
    }
}
