#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
void reverse(queue<int> &q) {
    if (q.empty()) {
        return;
    }

    int curr = q.front();
    q.pop();

    reverse(q);

    q.push(curr);
}

int main() {
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    reverse(q);

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
}
