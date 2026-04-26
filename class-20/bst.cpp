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

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

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

int getSmallestValue(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// TC: O(H)
// AS: O(H)
Node* deleteFromBst(Node* root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if (value < root->data) {
        root->left = deleteFromBst(root->left, value);
    } else if (value > root->data) {
        root->right = deleteFromBst(root->right, value);
    } else {
        // int childCount = 0;
        // if (root->left != NULL) {
        //     childCount++;
        // }
        // if (root->right != NULL) {
        //     childCount++;
        // }

        // // case-1: no child node.
        // if (childCount == 0) {
        //     return NULL;
        // }
        
        // // case-2: one child node.
        // if (childCount == 1) {
        //     if (root->left != NULL) {
        //         return root->left;
        //     }
        //     return root->right;
        // }
        
        // // case-3: two child nodes.
        // int inorderSucc = getSmallestValue(root->right);
        // root->data = inorderSucc;
        // root->right = deleteFromBst(root->right, inorderSucc);

        if (root->left == NULL) {
            return root->right;
        }
        if (root->right == NULL) {
            return root->left;
        }
        // int inorderPred = getLargestValue(root->left);
        // root->data = inorderPred;
        // root->left = deleteFromBst(root->left, inorderPred);
        int inorderSucc = getSmallestValue(root->right);
        root->data = inorderSucc;
        root->right = deleteFromBst(root->right, inorderSucc);
    }
    return root;
}

int main() {

    Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    cout << searchInBstRec(root, 8) << endl;
    cout << searchInBstRec(root, 3) << endl;
    cout << searchInBstRec(root, 5) << endl;
    cout << searchInBstRec(root, 9) << endl;

    cout << searchInBstIterative(root, 8) << endl;
    cout << searchInBstIterative(root, 3) << endl;
    cout << searchInBstIterative(root, 5) << endl;
    cout << searchInBstIterative(root, 9) << endl;

    root = deleteFromBst(root, 8);
    root = deleteFromBst(root, 7);
    root = deleteFromBst(root, 3);
    root = deleteFromBst(root, 5);

    cout << searchInBstIterative(root, 8) << endl;
    cout << searchInBstIterative(root, 7) << endl;
    cout << searchInBstIterative(root, 3) << endl;
    cout << searchInBstIterative(root, 5) << endl;

    inorder(root);
}
