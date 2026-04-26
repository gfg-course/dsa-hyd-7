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

void inorder(Node* root, int &prev, bool &result) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, prev, result);
    if (root->data <= prev) {
        result = false;
    }
    prev = root->data;
    inorder(root->right, prev, result);
}

// TC: O(n)
// AS: O(H)
bool isBst(Node* root) {
    int prev = INT_MIN;

    bool result = true;
    inorder(root, prev, result);
    return result;
}

int main() {

}
