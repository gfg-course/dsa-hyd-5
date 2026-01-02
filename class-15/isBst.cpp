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

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }
    if (root->data == value) {
        return root;
    }
    if (root->data > value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

bool isBstUtil(Node* root, int low, int high) {
    if (root == NULL) {
        return true;
    }

    return 
        root->data >= low && root->data <= high &&
        isBstUtil(root->left, low, root->data - 1) &&
        isBstUtil(root->right, root->data + 1, high);

}

// TC: O(n)
// AS: O(H)
bool isBst(Node* root) {
    return isBstUtil(root, -1e9, +1e9);
}


bool isBstUisingInorderUtil(Node* root, int &prev) {
    if (root == NULL) {
        return true;
    }

    bool leftRes = isBstUisingInorderUtil(root->left, prev);
    
    if (root->data <= prev) {
        return false;
    }
    prev = root->data;

    bool rightRes = isBstUisingInorderUtil(root->right, prev);

    return leftRes && rightRes;
    
}

// TC: O(n)
// AS: O(H)
bool isBstUisingInorder(Node* root) {
    int prev = -1e9;

    return isBstUisingInorderUtil(root, prev);
}

int main() {
    Node* root = NULL;
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 6);

    cout << isBst(root) << endl;
    cout << isBstUisingInorder(root) << endl;

    root->right->left->data = 1;
    cout << isBst(root) << endl;
    cout << isBstUisingInorder(root) << endl;
}
