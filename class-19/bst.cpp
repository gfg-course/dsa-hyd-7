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

// TC: O(H)
// AS: O(1) - Tail Recursive
bool searchInBstRec(Node* root, int value) {
    if (root == NULL) {
        return false;
    }

    if (root->data == value) {
        return true;
    }
    if (value < root->data) {
        return searchInBstRec(root->left, value);
    }
    return searchInBstRec(root->right, value);
}

// TC: O(H)
// AS: O(1)
bool searchInBstIterative(Node* root, int value) {
    while (root != NULL) {
        if (root->data == value) {
            return true;
        }
        if (value < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return false;
}

// TC: O(H)
// AS: O(H)
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (root->data == value) {
        return root;
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

int main() {
}
