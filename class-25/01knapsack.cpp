#include<bits/stdc++.h>
using namespace std;

int getMaxValueUtil(int i, int W, vector<int> &values, vector<int> &wts, vector<vector<int>> &memo) {
    if (i == values.size() || W == 0) {
        return 0;
    }

    if (memo[i][W] != -1) {
        return memo[i][W];
    }

    // Leave the current item.
    int result = getMaxValueUtil(i + 1, W, values, wts, memo);

    // Take the current item, if possible.
    if (wts[i] <= W) {
        result = max(result, values[i] + getMaxValueUtil(i + 1, W - wts[i], values, wts, memo));
    }

    memo[i][W] = result;
    return memo[i][W];
}

// TC: O(n * W)
// AS: O(n * W)
int getMaxValue(vector<int> values, vector<int> wts, int W) {
    int n = values.size();
    vector<vector<int>> memo(n, vector<int> (W + 1, -1));

    return getMaxValueUtil(0, W, values, wts, memo);
}

int main() {

    cout << getMaxValue({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << getMaxValue({60, 100, 120}, {10, 20, 50}, 50) << endl;
}
