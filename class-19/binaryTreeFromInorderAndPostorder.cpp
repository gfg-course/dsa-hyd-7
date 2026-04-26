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

void postorderTrav(Node* root) {
    if (root == NULL) {
        return;
    }

    postorderTrav(root->left);
    postorderTrav(root->right);
    cout << root->data << " ";
}

void inorderTrav(Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTrav(root->left);
    cout << root->data << " ";
    inorderTrav(root->right);
}

Node* constructUtil(int inStart, int inEnd, vector<int> &inorder, 
                    int &postIdx, vector<int> &postorder) {
    
    if (inStart > inEnd) {
        return NULL;
    }
    
    Node* root = new Node(postorder[postIdx]);
    postIdx--;

    // int inIdx = -1;
    // for (int i = inStart; i <= inEnd; i++) {
    //     if (inorder[i] == root->data) {
    //         inIdx = i;
    //         break;
    //     }
    // }

    int inIdx = inStart;
    for (int i = inStart + 1; i <= inEnd; i++) {
        if (inorder[i] == root->data) {
            inIdx = i;
            break;
        }
    }

    root->right = constructUtil(inIdx + 1, inEnd, inorder, postIdx, postorder);
    root->left = constructUtil(inStart, inIdx - 1, inorder, postIdx, postorder);

    return root;
}   

// TC: O(n)
// AS: O(H)
Node* constructTreeUsingInorderAndPostorder(vector<int> inorder, vector<int> postorder) {

    int inStart = 0;
    int inEnd = inorder.size() - 1;
    int postIdx = postorder.size() - 1;

    return constructUtil(inStart, inEnd, inorder, postIdx, postorder);
}

int main() {

    Node* root = constructTreeUsingInorderAndPostorder({4, 2, 5, 1, 3}, {4, 5, 2, 3, 1});

    inorderTrav(root);
    cout << endl;
    postorderTrav(root);
    cout << endl;
}
