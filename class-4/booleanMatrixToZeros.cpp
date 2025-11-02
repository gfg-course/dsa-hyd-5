#include<bits/stdc++.h>
using namespace std;

// TC: O(n*m)
// AS: O(n + m)
vector<vector<int>> booleanMatrixZeros(vector<vector<int>> arr) {
    int n = arr.size();
    int m = arr[0].size();

    vector<bool> rows(n, false);
    vector<bool> cols(m, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (rows[i] == true || cols[j] == true) {
                arr[i][j] = 0;
            }
        }
    }

    return arr;
}

// TC: O(n*m)
// AS: O(1)
vector<vector<int>> booleanMatrixZerosUsingBucketing(vector<vector<int>> arr) {
    int n = arr.size();
    int m = arr[0].size();

    bool zerothRowZero = false;
    bool zerothColZero = false;

    for (int j = 0; j < m; j++) {
        if (arr[0][j] == 0) {
            zerothRowZero = true;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i][0] == 0) {
            zerothColZero = true;
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 0) {
                arr[i][0] = 0; // row bucket
                arr[0][j] = 0; // col bucket
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][0] == 0 || arr[0][j] == 0) {
                arr[i][j] = 0;
            }
        }
    }

    if (zerothRowZero) {
        for (int j = 0; j < m; j++) {
            arr[0][j] = 0;
        }
    }

    if (zerothColZero) {
        for (int i = 0; i < n; i++) {
            arr[i][0] = 0;
        }
    }

    return arr;
}

int main() {

    vector<vector<int>> arr1 = booleanMatrixZerosUsingBucketing({{1, 0, 1},
                                                                 {1, 1, 1},
                                                                 {1, 1, 1}});

    vector<vector<int>> arr2 = booleanMatrixZerosUsingBucketing({{1, 0, 1},
                                                                 {1, 1, 1},
                                                                 {1, 0, 1}});

    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr1[i].size(); j++) {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < arr2.size(); i++) {
        for (int j = 0; j < arr2[i].size(); j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}