#include<bits/stdc++.h>
using namespace std;

vector<string> keypad = {
    "", 
    "", "abc", "def", 
    "ghi", "jkl", "mno", 
    "pqrs", "tuv", "wxyz"};

void wordsFromKeypadUtil(int i, vector<int> &arr, string &curr, vector<string> &result) {
    if (i == arr.size()) {
        result.push_back(curr);
        return;
    }

    for (char ch : keypad[arr[i]]) {

        curr.push_back(ch);
        wordsFromKeypadUtil(i + 1, arr, curr, result);
        curr.pop_back();
    }
}

// TC: O(4^n)
// AS: O(n)
vector<string> wordsFromKeypad(vector<int> arr) {

    string curr = "";
    vector<string> result;

    wordsFromKeypadUtil(0, arr, curr, result);

    return result;
}

int main() {

    vector<string> result = wordsFromKeypad({2, 3});
    for (string i : result) {
        cout << i << " ";
    }
}
