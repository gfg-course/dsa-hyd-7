#include<bits/stdc++.h>
using namespace std;

int inf = 1e6;

int getMinCoinsUtil(int i, int value, vector<int> &coins, vector<vector<int>> &memo) {
    if (value == 0) {
        return 0;   
    }
    if (i == coins.size()) {
        return inf;
    }
    if (memo[i][value] != -1) {
        return memo[i][value];
    }

    // Leave the current coin.
    int result = getMinCoinsUtil(i + 1, value, coins, memo);

    // Take the coin, if possible.
    if (value >= coins[i]) {
        result = min(result, 1 + getMinCoinsUtil(i, value - coins[i], coins, memo));
    }

    memo[i][value] = result;
    return memo[i][value];
}

// TC: O(n * value)
// AS: O(n * value)
int getMinCoins(vector<int> coins, int value) {
    int n = coins.size();
    vector<vector<int>> memo(n, vector<int> (value + 1, -1));

    int result = getMinCoinsUtil(0, value, coins, memo);
    if (result >= inf) {
        return -1;
    }
    return result;
}

int main() {

    cout << getMinCoins({2, 5, 3, 6}, 10) << endl;
    cout << getMinCoins({3, 6, 3}, 5) << endl;
}
