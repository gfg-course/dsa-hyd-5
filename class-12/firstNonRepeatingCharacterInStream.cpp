#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
string firstNonRepeatingInStream(string s) {
    vector<int> freq(26, 0);

    queue<char> q;

    string res = "";

    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
        if (freq[s[i] - 'a'] == 1) {
            q.push(s[i]);
        }

        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }
        if (q.empty()) {
            res.push_back('#');
        } else {
            res.push_back(q.front());
        }
    }

    return res;
}

int main() {

    cout << firstNonRepeatingInStream("aabc") << endl;
    cout << firstNonRepeatingInStream("aacb") << endl;
    cout << firstNonRepeatingInStream("zz") << endl;
}
