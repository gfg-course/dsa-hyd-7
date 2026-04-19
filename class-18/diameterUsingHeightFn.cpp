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

int calcHeightAndUpdateDiam(Node* root, int &diam) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = calcHeightAndUpdateDiam(root->left, diam);
    int rightHeight = calcHeightAndUpdateDiam(root->right, diam);

    diam = max(diam, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

// TC: O(n)
// AS: O(H)
int diameter(Node* root) {
    int diam = 0;
    calcHeightAndUpdateDiam(root, diam);
    return diam;
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

    cout << diameter(root) << endl;
}
