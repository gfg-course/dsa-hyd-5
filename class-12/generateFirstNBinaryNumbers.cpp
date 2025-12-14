#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n * log(n))
vector<string> firstNBinaryNumbers(int n) {
    queue<string> q;
    vector<string> res;

    q.push("1");
    int inserts = 1; 

    while (inserts < n) {
        string curr = q.front();
        q.pop();

        res.push_back(curr);

        q.push(curr + "0");
        q.push(curr + "1");
        inserts += 2;
    }

    while (res.size() != n) {
        res.push_back(q.front());
        q.pop();
    }

    cout << q.size() << endl;

    return res;
}

int main() {

    vector<string> res = firstNBinaryNumbers(10);

    for (string i  :res){ 
        cout << i << endl;
    }
}
