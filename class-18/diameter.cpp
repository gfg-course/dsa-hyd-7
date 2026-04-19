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

// TC: O(n)
// AS: O(H)
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

// TC: O(n^2)
// AS: O(H)
int diameter(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    int leftDiam = diameter(root->left);
    int rightDiam = diameter(root->right);

    return max({lh + rh, leftDiam, rightDiam});
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
