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
// AS: O(H)
int height(Node* root, unordered_map<Node*, int> &heights) {
    if (root == NULL) {
        return 0;
    }

    if (heights.find(root) != heights.end()) { // if root already exists in the map.
        return heights[root];
    }

    int leftHeight = height(root->left, heights);
    int rightHeight = height(root->right, heights);

    heights[root] = 1 + max(leftHeight, rightHeight);
    return heights[root];
}

void diameterUtil(Node* root, int &result, unordered_map<Node*, int> &heights) {
    if (root == NULL) {
        return;
    }

    int lh = height(root->left, heights);
    int rh = height(root->right, heights);
    result = max(result, lh + rh);

    diameterUtil(root->left, result);
    diameterUtil(root->right, result);
}

// TC: O(n)
// AS: O(n)
int diameter(Node* root) {

    int result = 0;
    unordered_map<Node*, int> heights;
    diameterUtil(root, result, heights);
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
