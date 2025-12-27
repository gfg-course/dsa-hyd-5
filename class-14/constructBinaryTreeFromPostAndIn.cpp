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

void postorder(Node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* constructUtil(vector<int> &inorder, vector<int> &postorder, 
                    int inStart, int inEnd, int &postIdx) {
    
    if (inStart > inEnd) {
        return NULL;
    }

    Node* root = new Node(postorder[postIdx]);
    postIdx--;

    // TODO : Optimize the TC to O(n) by creating a reverse-index mapping
    // for inorder[]
    // map{value -> index in inorder[]}
    // Using this map, the below search can be done in O(1) time.
    int index = inStart;
    for (int i = inStart + 1; i <= inEnd; i++) {
        if (inorder[i] == root->data) {
            index = i;
            break;
        }
    }

    root->right = constructUtil(inorder, postorder, index + 1, inEnd, postIdx);
    root->left = constructUtil(inorder, postorder, inStart, index - 1, postIdx);

    return root;
}

// TC: O(n^2)
// AS: O(H)
Node* constructFromPostOrderAndInorder(vector<int> inorder, vector<int> postorder) {

    int n = inorder.size();

    int postIdx = n - 1;
    return constructUtil(inorder, postorder, 0, n - 1, postIdx);
}

int main() {

    Node* root = constructFromPostOrderAndInorder({4, 8, 2, 5, 1, 6, 3, 7},
                                                  {8, 4, 5, 2, 6, 7, 3, 1});
    
    inorder(root);
    cout << endl;
    postorder(root);
}
