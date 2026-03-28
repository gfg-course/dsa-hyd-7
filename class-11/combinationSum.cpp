#include<bits/stdc++.h>
using namespace std;

void getAllCombinationsUtil(int i, int target, vector<int> &arr, vector<int> &curr, vector<vector<int>> &res) {
    if (target == 0) {
        res.push_back(curr);
        return;
    }
    if (i == arr.size()) {
        return;
    }
    
    // consider the current element, if possible.
    if (arr[i] <= target) {
        curr.push_back(arr[i]);
        getAllCombinationsUtil(i, target - arr[i], arr, curr, res);
        curr.pop_back();
    }

    // ignore the current element.
    getAllCombinationsUtil(i + 1, target, arr, curr, res);
    
}

// TC: O(2 ^ max(n, target))
// AS: O(target + max(n, target)) = O(max(n, target))
vector<vector<int>> getAllCombinations(vector<int> arr, int target) {

    vector<int> curr;
    vector<vector<int>> res;

    getAllCombinationsUtil(0, target, arr, curr, res);
    return res;
}

int main() {

    vector<vector<int>> res = getAllCombinations({2, 4, 6, 8}, 8);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
