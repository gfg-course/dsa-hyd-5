#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1) as its tail-recursive.
void printNto1(int n) {
    if (n <= 0) {
        return;
    }

    cout << n << endl;
    printNto1(n - 1);
}

// TC: O(n)
// AS: O(n)
void print1ToN(int n) {
    if (n <= 0) {
        return;
    }

    print1ToN(n - 1);
    cout << n << endl;
}

int main() {
    // printNto1(10);
    print1ToN(10);
}
