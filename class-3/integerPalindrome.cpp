#include<bits/stdc++.h>
using namespace std;

int getReverse(int n) {

    int rev = 0;
    while (n != 0) {
        int last = n%10;
        rev = rev*10 + last;
        n = n/10;
    }

    return rev;
}

// TC: O(log(n))
// As: O(1)
bool isPalindrome(int n) {

    int reverse = getReverse(n);
    return n == reverse;
}

int main() {

    cout << isPalindrome(1234) << endl;
    cout << isPalindrome(12344321) << endl;
}