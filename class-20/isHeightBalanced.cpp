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

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

// TC: O(n*n)
// AS: O(H)
bool isHeightBalanced(Node* root) {
    if (root == NULL) {
        return true;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return
        abs(lh - rh) <= 1 &&
        isHeightBalanced(root->left) &&
        isHeightBalanced(root->right);
}

int main() {

    Node* root = constructBstUsingSortedArray({1, 2, 3, 4, 5, 6, 7});

    cout << isHeightBalanced(root) << endl;

    root->right->left = NULL;
    root->right->right->right = new Node(8);

    cout << isHeightBalanced(root) << endl;
}
