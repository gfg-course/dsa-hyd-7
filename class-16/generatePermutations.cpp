#include<bits/stdc++.h>
using namespace std;

void getAllPermutationsUtil(int i, vector<int> &arr, vector<vector<int>> &res) {
    if (i == arr.size()) {
        res.push_back(arr);
        return;
    }

    for (int j = i; j < arr.size(); j++) {
        swap(arr[i], arr[j]);
        getAllPermutationsUtil(i + 1, arr, res);
        swap(arr[i], arr[j]);
    }
}

// TC: O(n * n!)
// AS: O(n)
vector<vector<int>> getAllPermutations(vector<int> arr) {

    vector<vector<int>> res;
    getAllPermutationsUtil(0, arr, res);
    return res;
}

int main() {
    vector<vector<int>> res = getAllPermutations({1, 2, 3});
    for (auto i : res) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
