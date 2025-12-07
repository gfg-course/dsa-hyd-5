#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElements(vector<int> arr) {

    stack<int> helper;
    int n = arr.size();
    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!helper.empty() && arr[helper.top()] > arr[i]) {
            helper.pop();
        }
        if (helper.empty()) {
            result[i] = n;
        } else {
            result[i] = helper.top();
        }

        helper.push(i);
    }

    return result;
}

vector<int> prevSmallerElements(vector<int> arr) {

    stack<int> helper;
    int n = arr.size();
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        while (!helper.empty() && arr[helper.top()] > arr[i]) {
            helper.pop();
        }
        if (helper.empty()) {
            result[i] = -1;
        } else {
            result[i] = helper.top();
        }

        helper.push(i);
    }

    return result;
}

int maxHistogramArea(vector<int> heights) {
    int n = heights.size();

    vector<int> nse = nextSmallerElements(heights);
    vector<int> pse = prevSmallerElements(heights);

    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        int width = nse[i] - pse[i] - 1;
        int area = width * heights[i];

        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {

    cout << maxHistogramArea({6, 2, 5, 4, 5, 1, 6}) << endl;
}
