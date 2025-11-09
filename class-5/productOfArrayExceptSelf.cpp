#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
vector<int> productExceptSelf(vector<int> arr) {

    int n = arr.size();
    vector<int> ans(n);

    // ans[] will initially store the suff products.
    ans[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        ans[i] = ans[i + 1] * arr[i + 1];
    }

    // multiplying the pref products to the suff products on the fly.
    int prefProd = 1;
    for (int i = 0; i < n; i++) {
        ans[i] = prefProd * ans[i];
        prefProd *= arr[i];
    }
    return ans;
}

int main() {
}