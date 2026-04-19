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
// AS: O(n)
vector<vector<int>> levelByLevelTraversal(Node* root) {
    if (root == NULL) {
        return {};
    }

    vector<vector<int>> result;
    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        vector<int> currentLevel;

        for (int i = 0; i < sz; i++) {
            Node* curr = q.front();
            q.pop();

            currentLevel.push_back(curr->data);

            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }

        result.push_back(currentLevel);
    }

    return result;
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

    vector<vector<int>> res = levelByLevelTraversal(root);

    for (auto i : res) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
