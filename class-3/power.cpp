#include<bits/stdc++.h>
using namespace std;

// T(b) = T(b/2) + c
// TC: O(log(b))
// AS: O(log(b))
int power(int a, int b) {
    if (b == 0) {
        return 1;
    }

    int temp = power(a, b/2);
    if (b % 2 == 0) {
        return temp * temp;
    }
    return a * temp * temp;
}

int main() {
    cout << power(2, 3) << endl;
    cout << power(2, 4) << endl;
    cout << power(0, 3) << endl;
    cout << power(2231312, 1) << endl;
}