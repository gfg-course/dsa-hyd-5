#include<bits/stdc++.h>
using namespace std;

// TC: O(m) where m is the length of the string.
// AS: O(1)
string getHashKey(string s) {
    vector<int> freq(26, 0);
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
    }
    string hashKey = "";
    for (int i = 0; i < 26; i++) {
        hashKey += to_string(freq[i]);
        hashKey += "#";
    }
    return hashKey;
}

// TC: O(n*m)
// AS: O(n*m)
// TODO: Optimize the aux space to O(n) by using the following hashMap:
// freq_string -> {indices of the strings}
// instead of 
// freq_string -> {original strings}
vector<vector<string>> groupAnagrams(vector<string> arr) {

    unordered_map<string, vector<string>> groupedAnagrams;

    for (int i = 0; i < arr.size(); i++) {
        string hashKey = getHashKey(arr[i]);
        
        // if the hashKey is not there in the hashMap
        if (groupAnagrams.find(hashKey) == groupAnagrams.end()) {
            groupAnagrams[hashKey] = {};
        }

        groupAnagrams[hashKey].push_back(arr[i]);
    }

    vector<vector<string>> result;

    for (auto i : groupedAnagrams) {
        vector<string> value = i.second;
        result.push_back(value);
    }
    return result;
}

int main() {
}
