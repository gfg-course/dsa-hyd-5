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

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// TC: O(H)
// AS: O(1) - (tail recursive)
bool search(Node* root, int target) {
    if (root == NULL) {
        return false;
    }

    if (root->data == target) {
        return true;
    }

    if (target < root->data) {
        return search(root->left, target);
    }
    return search(root->right, target);
}

// TC: O(H)
// AS: O(H)
Node* insert(Node* root, int value) {
    // 1. root is empty
    // 2. root->data == value -> No insertion should be done.
    // 3. root->data > value -> insert in the left subtree.
    // 4. root->data < value -> insert in the right subtree.

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

int getSmallest(Node* root) {

    while (root->left != NULL) {
        root = root->left;
    }

    return root->data;
}

// TC: O(H)
Node* deleteNode(Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (root->data > value) {
        root->left = deleteNode(root->left, value);
    } else if (root->data < value) {
        root->right = deleteNode(root->right, value);
    } else {

        if (root->left == NULL) {
            return root->right;
        }
        if (root->right == NULL) {
            return root->left;
        }

        int inorderSuccessor = getSmallest(root->right);
        root->data = inorderSuccessor;
        root->right = deleteNode(root->right, inorderSuccessor);

        // int childCount = 0;
        // if (root->left != NULL) {
        //     childCount++;
        // }
        // if (root->right != NULL) {
        //     childCount++;
        // }

        // // Case-1: 
        // if (childCount == 0) {
        //     return NULL;
        // }

        // // Case-2:
        // if (childCount == 1) {
        //     if (root->left != NULL) {
        //         return root->left;
        //     }
        //     return root->right;
        // }

        // // Case-3:
        // if (childCount == 2) {
        //     int inorderSuccessor = getSmallest(root->right);
        //     root->data = inorderSuccessor;

        //     root->right = deleteNode(root->right, inorderSuccessor);
        // }
    }

    return root;
}

int main() {

    Node* root = NULL;
    root = insert(root, 11);
    root = insert(root, 2);
    root = insert(root, 13);
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 8);

    cout << search(root, 13) << endl;
    cout << search(root, 9) << endl;
    cout << search(root, 10) << endl;

    inorder(root);
    cout << endl;

    root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    root = deleteNode(root, 20);
    root = deleteNode(root, 30);
    root = deleteNode(root, 50);

    inorder(root);
    cout << endl;
}
