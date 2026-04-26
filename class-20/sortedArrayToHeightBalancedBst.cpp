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

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

Node* constructBstUsingSortedArrayUtil(vector<int> &arr, int i, int j) {
    if (i > j) {
        return NULL;
    }

    int mid = (i + j) / 2;
    Node* root = new Node(arr[mid]);

    root->left = constructBstUsingSortedArrayUtil(arr, i, mid-1);
    root->right = constructBstUsingSortedArrayUtil(arr, mid+1, j);

    return root;
}

// TC: O(n)
// AS: O(log(n))
Node* constructBstUsingSortedArray(vector<int> arr) {
    return constructBstUsingSortedArrayUtil(arr, 0, arr.size() - 1);
}

int main() {

    Node* root = constructBstUsingSortedArray({1, 2, 3, 4, 5, 6, 7});

    cout << isBst(root) << endl;
    cout << height(root) << endl;

    Node* root2 = constructBstUsingSortedArray({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

    cout << isBst(root2) << endl;
    cout << height(root2) << endl;
}
