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

int height(Node* root, unordered_map<Node*, int> &heights) {
    if (root == NULL) {
        return 0;
    }

    // If already calculated, return from the storage.
    if (heights.find(root) != heights.end()) {
        return heights[root];
    }

    // If not calculated, calculate it -> store -> then return.
    int leftHeight = height(root->left, heights);
    int rightHeight = height(root->right, heights);

    heights[root] = 1 + max(leftHeight, rightHeight);
    return heights[root];
}

bool isHeightBalancedUtil(Node* root, unordered_map<Node*, int> &heights) {
    if (root == NULL) {
        return true;
    }

    int lh = height(root->left, heights);
    int rh = height(root->right, heights);

    return
        abs(lh - rh) <= 1 &&
        isHeightBalancedUtil(root->left, heights) &&
        isHeightBalancedUtil(root->right, heights);
}

// TC: O(n)
// AS: O(n)
bool isHeightBalanced(Node* root) {
    unordered_map<Node*, int> heights;
    return isHeightBalancedUtil(root, heights);
}

int main() {
    Node* root = constructBstUsingSortedArray({1, 2, 3, 4, 5, 6, 7});

    cout << isHeightBalanced(root) << endl;

    root->right->left = NULL;
    root->right->right->right = new Node(8);

    cout << isHeightBalanced(root) << endl;
}
