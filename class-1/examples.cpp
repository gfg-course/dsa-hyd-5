
// TC: O(A + B)
// AS: O(1)
for (int i = 0; i < A.size(); i++) { 
    cout << A[i] << endl;
}
for (int i = 0; i < B.size(); i++) { 
    cout << B[i] << endl;
}

// ---------------------------------------------------

// TC: O(A*B)
// AS: O(1)
for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < B.size(); j++) {
        cout << A[i] + B[j] << endl;
    }
}

// ---------------------------------------------------

// TC: O(n^2)
// AS: O(1)
void func(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << i + j << endl;
        }
    }
}

// ---------------------------------------------------

// TC: O(m * n^2) where m is the length of the string.
// AS: O(1)
void func(int n, string s) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << s << endl;
        }
    }
}

// ---------------------------------------------------

// Input Space: O(m^2)
// Output Space: O(k)
// Aux Space: O(n)
vector<int> func(vector<vector<int>> arr) { // arr: m^2, output: k
    // ....
    vector<int> temp(n);
    // ....

    vector<int> result;
    // ....
    return result;
}

// ---------------------------------------------------

// Input Space: O(m * max_length)
// Aux Space: O(n * max_length)
string func(vector<string> arr) { // arr: m
    // ...
    vector<string> temp(n);

    // ...
    return result;
}