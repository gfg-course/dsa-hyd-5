#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
int countSubarraysWithEqual0sAnd1s(vector<int> arr) {

    unordered_map<int, int> sumToFreq;
    int n = arr.size();

    int currentSum = 0;
    sumToFreq[currentSum] = 1;

    int result = 0;

    for (int i = 0; i < n; i++) {
        // if (arr[i] == 0) {
        //     currentSum--;
        // } else {
        //     currentSum++;
        // }
        currentSum += arr[i] == 0 ? -1: +1;

        result += sumToFreq[currentSum];
        sumToFreq[currentSum]++;
    }

    return result;
}

int main() {

    cout << countSubarraysWithEqual0sAnd1s({1, 0, 0, 1, 0, 1, 1}) << endl;
    cout << countSubarraysWithEqual0sAnd1s({1, 1, 1, 0}) << endl;
}