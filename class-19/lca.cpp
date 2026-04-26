#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void getPathUtil(Node* root, int val, vector<Node*> &currPath, vector<Node*> &resultPath) {
    if (root == NULL || resultPath.size() > 0) {
        return;
    }

    currPath.push_back(root);
    
    if (root->data == val) {
        resultPath = currPath;
        return;
    }
    getPathUtil(root->left, val, currPath, resultPath);
    getPathUtil(root->right, val, currPath, resultPath);

    currPath.pop_back();
}

vector<Node*> getPath(Node* root, int val) {
    vector<Node*> currPath;
    vector<Node*> resultPath;

    getPathUtil(root, val, currPath, resultPath);
    return resultPath;
}

// TC: O(n + n + H) = O(n)
// AS: O(4H) = O(H)
Node* lca(Node* root, int n1, int n2) {
    vector<Node*> path1 = getPath(root, n1);
    vector<Node*> path2 = getPath(root, n2);

    Node* result = root;
    int i = 0;

    while (i < path1.size() && i < path2.size() && path1[i] == path2[i]) {
        result = path1[i];
        i++;
    }

    return result;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->right->right = new Node(6);

    cout << lca(root, 7, 8)->data << endl;
    cout << lca(root, 5, 2)->data << endl;
    cout << lca(root, 4, 6)->data << endl;

}
