#include<bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)
int sumDigits1ToN(int n) {

    int result = 0;
    for (int i = 1; i < n + 1; i *= 10) {
        result += n - (i - 1);
    }
    return result;
}

int main() {
    cout << sumDigits1ToN(10) << endl;
    cout << sumDigits1ToN(25) << endl;
}