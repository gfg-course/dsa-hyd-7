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

// TC: O(n)
// AS: O(H)
bool isBstUtil(Node* root, int low, int high) {
    if (root == NULL) {
        return true;
    }

    // if (root->data < low || root->data > high) {
    //     return false;
    // }

    // bool isRightSubtreeValid = isBstUtil(root->right, root->data + 1, high);
    // bool isLeftSubtreeValid = isBstUtil(root->left, low, root->data - 1);

    // return isRightSubtreeValid && isLeftSubtreeValid;

    return 
        (root->data >= low && root->data <= high) &&
        isBstUtil(root->right, root->data + 1, high) && 
        isBstUtil(root->left, low, root->data - 1);
}

bool isBstUsingRanges(Node* root) {
    return isBstUtil(root, INT_MIN, INT_MAX);
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

    cout << isBstUsingRanges(root) << endl;

    root->right->left->data = 4;

    cout << isBstUsingRanges(root) << endl;
}
