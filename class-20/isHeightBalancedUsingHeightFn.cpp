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

Node* constructBstUsingSortedArray(vector<int> arr) {
    return constructBstUsingSortedArrayUtil(arr, 0, arr.size() - 1);
}

int height(Node* root, bool &isHeightBalanced) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left, isHeightBalanced);
    int rightHeight = height(root->right, isHeightBalanced);

    if (abs(leftHeight - rightHeight) > 1) {
        isHeightBalanced = false;
    }

    return 1 + max(leftHeight, rightHeight);
}

// TC: O(n)
// AS: O(H)
bool isHeightBalancedUsingHeightFn(Node* root) {
    bool result = true;
    height(root, result);
    return result;
}

int main() {
    Node* root = constructBstUsingSortedArray({1, 2, 3, 4, 5, 6, 7});

    cout << isHeightBalancedUsingHeightFn(root) << endl;

    root->right->left = NULL;
    root->right->right->right = new Node(8);

    cout << isHeightBalancedUsingHeightFn(root) << endl;
}
