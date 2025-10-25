for (int i = 0; i < A.size(); i++) { 
    cout << A[i] << endl;
}
for (int i = 0; i < B.size(); i++) { 
    cout << B[i] << endl;
}

// ---------------------------------------------------

for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < B.size(); j++) {
        cout << A[i] + B[j] << endl;
    }
}

// ---------------------------------------------------

void func(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << i + j << endl;
        }
    }
}

// ---------------------------------------------------

// TC: O(n^2 * len(s))
void func(int n, string s) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << s << endl;
        }
    }
}

// ---------------------------------------------------

vector<int> func(vector<vector<int>> arr) { // arr: m^2, output: k
    // ....
    vector<int> temp(n);
    // ....

    vector<int> result;
    // ....
    return result;
}

// ---------------------------------------------------

string func(vector<string> arr) { // arr: m
    // ...
    vector<string> temp(n);

    // ...
    return result;
}