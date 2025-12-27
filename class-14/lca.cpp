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

void getPathUtil(Node* root, int target, vector<int> &currPath, vector<int> &resPath) {
    if (root == NULL || resPath.size() > 0) {
        return;
    }

    currPath.push_back(root->data);
    if (root->data == target) {
        resPath = currPath;
        return;
    }

    getPathUtil(root->left, target, currPath, resPath);
    getPathUtil(root->right, target, currPath, resPath);

    currPath.pop_back();
}

// TC: O(n)
// AS: O(H)
vector<int> getPath(Node* root, int target) {

    vector<int> currPath;
    vector<int> resPath;

    getPathUtil(root, target, currPath, resPath);
    return resPath;
}


// TC: O(n)
// AS: O(H)
int lca(Node* root, int n1, int n2) {

    vector<int> pathN1 = getPath(root, n1);
    vector<int> pathN2 = getPath(root, n2);

    if (pathN1.size() == 0 || pathN2.size() == 0) {
        return -1;
    }

    int i = 1;
    int result = pathN1[0];

    while (i < pathN1.size() && i < pathN2.size()) {
        if (pathN1[i] != pathN2[i]) {
            break;
        }
        result = pathN1[i];
        i++;
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

    cout << lca(n[1], 4, 8) << endl;
    cout << lca(n[1], 2, 7) << endl;
    cout << lca(n[1], 10, 11) << endl;
    cout << lca(n[1], 7, 11) << endl;
    cout << lca(n[1], 7, 12) << endl;
}
