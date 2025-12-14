#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

// TC: O(n)
// AS: O(n)
vector<vector<int>> levelByLevelTraversal(Node* root) {
    if (root == NULL) {
        return {};
    }

    queue<Node*> q;
    vector<vector<int>> res;

    q.push(root);

    while (!q.empty()) {
        int sz = q.size();

        vector<int> currLevel;
        for (int _ = 0; _ < sz; _++) {
            Node* curr = q.front();
            q.pop();

            currLevel.push_back(curr->data);

            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }

        res.push_back(currLevel);
    }

    return res;
}

int main() {

    vector<Node*> n(11);
    for (int i = 1; i <= 10; i++) {
        n[i] = new Node(i);
    }

    n[1]->left = n[2];
    n[1]->right = n[3];
    n[2]->left = n[4];
    n[2]->right = n[5];
    n[5]->left = n[7];
    n[5]->right = n[8];
    n[3]->right = n[6];
    n[6]->left = n[9];
    n[6]->right = n[10];

    vector<vector<int>> res = levelByLevelTraversal(n[1]);

    for (auto i : res) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
