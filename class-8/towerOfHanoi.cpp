#include<bits/stdc++.h>
using namespace std;

// TC: O(2^n)
// AS: O(n)
int towerOfHanoi(int n, string A, string C, string B) {
    if (n == 0) {
        return 0;
    }

    int result = towerOfHanoi(n - 1, A, B, C);
    result++;
    cout << "Move " << n << "-th disk from rod " << A << " to " << C << endl;
    result += towerOfHanoi(n - 1, B, C, A);

    return result;
}

// TC: O(n)
// AS: O(n)  ddd
int towerOfHanoi(int n) {
    if (n == 0) {
        return 0;
    }

    // int result = towerOfHanoi(n - 1);
    // result++;
    // result += towerOfHanoi(n - 1);

    return 2*towerOfHanoi(n - 1) + 1;
}

int main() {

    // cout << towerOfHanoi(3, "A", "C", "B");
    cout << towerOfHanoi(3);
}
