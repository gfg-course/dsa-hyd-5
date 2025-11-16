#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int longestSubstrWithoutRepeatingChars(string s) {

    int n = s.length();
    int left = 0, right = 0;
    vector<bool> isPresent(26, false);

    int result = 0;

    while (right < n) {
        if (!isPresent[s[right] - 'a']) {
            isPresent[s[right] - 'a'] = true;
            result = max(result, right - left + 1);
        } else {
            while (left < n && s[left] != s[right]) {
                isPresent[s[left] - 'a'] = false;
                left++;
            }
            left++;
        }
        right++;
    }

    return result;
}

int main() {
    cout << longestSubstrWithoutRepeatingChars("geeksforgeeks") << endl;
    cout << longestSubstrWithoutRepeatingChars("aaaaa") << endl;
}