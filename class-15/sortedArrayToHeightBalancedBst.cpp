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

Node* constructUtil(vector<int> &arr, int low, int high) {
    if (low > high) {
        return NULL;
    }

    int mid = (low + high) / 2;
    Node* root = new Node(arr[mid]);

    root->left = constructUtil(arr, low, mid - 1);
    root->right = constructUtil(arr, mid + 1, high);

    return root;
}

// TC: O(n)
// AS: O(log(n))
Node* constructBstFromSortedArray(vector<int> arr) {

    return constructUtil(arr, 0, arr.size() - 1);
}

int main() {
}
