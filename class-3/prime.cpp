#include<bits/stdc++.h>
using namespace std;

// TC: O(sqrt(n))
// AS: O(1)
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    cout << isPrime(25) << endl;
    cout << isPrime(1) << endl;
    cout << isPrime(35) << endl;
    cout << isPrime(37) << endl;
}