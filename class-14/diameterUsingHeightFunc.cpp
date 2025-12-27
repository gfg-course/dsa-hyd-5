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

int height(Node* root, int &diam) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left, diam);
    int rightHeight = height(root->right, diam);
    diam = max(diam, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

// TC: O(n)
// AS: O(H)
int diameter(Node* root) {
    int result = 0;
    height(root, result);
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

    // cout << height(n[1]) << endl;
}
