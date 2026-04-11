#include<bits/stdc++.h>
using namespace std;

void getUniqueSubsetsUtil(int i, vector<int> &arr, vector<int> &curr, vector<vector<int>> &res) {
    if (i == arr.size()) {
        res.push_back(curr);
        return;
    }

    int j = i + 1;
    while (j < arr.size() && arr[j] == arr[i]) {
        j++;
    }

    int freq = j - i;

    // for (int k = 0; k <= freq; k++) {

    //     for (int l = 0; l <= k; l++) {
    //         curr.push_back(arr[i]);
    //     }

    //     getUniqueSubsetsUtil(j, arr, curr, res);

    //     for (int l = 0; l <= k; l++) {
    //         curr.pop_back();
    //     }
    // }

    getUniqueSubsetsUtil(j, arr, curr, res);
    for (int k = 1; k <= freq; k++) {
        curr.push_back(arr[i]);
        getUniqueSubsetsUtil(j, arr, curr, res);
    }

    for (int k = 1; k <= freq; k++) {
        curr.pop_back();
    }
}


// TC: O(2^n)
// AS: O(n)
vector<vector<int>> getUniqueSubsets(vector<int> arr) {

    vector<int> curr;
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());

    getUniqueSubsetsUtil(0, arr, curr, res);

    return res;
}

int main() {

    vector<vector<int>> res1 = getUniqueSubsets({2, 1, 2});
    vector<vector<int>> res2 = getUniqueSubsets({1, 2, 3, 3});

    for (auto i : res1) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (auto i : res2) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

}
