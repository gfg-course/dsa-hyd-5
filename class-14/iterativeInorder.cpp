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

void pushLeft(Node* root, stack<Node*> &st) {

    while (root != NULL) {
        st.push(root);
        root = root->left;
    }
}

// TC: O(n)
// AS: O(H)
vector<int> iterativeInorder(Node* root) {

    vector<int> result;
    stack<Node*> st;

    pushLeft(root, st);

    while (!st.empty()) {

        Node* curr = st.top();
        st.pop();

        result.push_back(curr->data);

        pushLeft(curr->right, st);
    }

    return result;
}

int main() {

    vector<Node*> n(12);
    for (int i = 1; i <= 11; i++) {
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
    n[10]->right = n[11];

    vector<int> res = iterativeInorder(n[1]);
    for (int i : res) {
        cout << i << " ";
    }
}
