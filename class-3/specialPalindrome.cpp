#include<bits/stdc++.h>
using namespace std;

bool isAlphaNumeric(char ch) {
    // bool isUpperCase = (ch >= 'A' && ch <= 'Z');
    // bool isLowerCase = (ch >= 'a' && ch <= 'z');
    // bool isNumeric = (ch >= '0' && ch <= '9');

    // return isUpperCase || isLowerCase || isNumeric;

    return 
        (ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z') || 
        (ch >= '0' && ch <= '9');
}

bool isSame(char a, char b) {
    if (a == b) {
        return true;
    }

    return 
        (a - 'A' + 'a' == b) ||
        (b - 'A' + 'a' == a);
}

// TC: O(n)
// AS: O(1)
bool isSpecialPalindrome(string s) {

    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (!isAlphaNumeric(s[i])) {
            i++;
        } else if (!isAlphaNumeric(s[j])) {
            j--;
        } else {
            if (!isSame(s[i], s[j])) {
                return false;
            }
            i++;
            j--;
        }
    }

    return true;
}

int main() {

    cout << isSpecialPalindrome("race a car") << endl;
    cout << isSpecialPalindrome("A man: Nama") << endl;
    cout << isSpecialPalindrome("A__man:__Nama__") << endl;
}