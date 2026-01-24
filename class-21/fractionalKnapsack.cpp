#include<bits/stdc++.h>
using namespace std;

// TC: O(n*log(n))
// AS: O(n)
double getMaxValue(vector<int> vals, vector<int> wts, int W) {

    int n = vals.size();

    // {val/wt, wt}
    vector<pair<double, int>> valByWtToWt;
    for (int i = 0; i < n; i++) {
        valByWtToWt.push_back({((double)vals[i] / wts[i]), wts[i]});
    }

    sort(valByWtToWt.begin(), valByWtToWt.end());

    double result = 0;
    for (int i = n - 1; i >= 0; i--) {
        double valByWt = valByWtToWt[i].first;
        int wt = valByWtToWt[i].second;

        if (wt <= W) {
            W -= wt;
            result += wt * valByWt;
        } else {
            result += W * valByWt;
            W = 0;
            break;
        }
    }

    return result;
}

int main() {

    cout << getMaxValue({60, 100, 120},{10, 20, 30}, 50) << endl;
    cout << getMaxValue({60, 100, 120},{10, 20, 50}, 50) << endl;
}
