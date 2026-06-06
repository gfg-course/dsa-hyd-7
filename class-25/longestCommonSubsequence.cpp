#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequenceUtil(int i, int j, string &s1, string &s2, vector<vector<int>> &memo) {
    if (i == s1.length() || j == s2.length()) {
        return 0;
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (s1[i] == s2[j]) {
        memo[i][j] = 1 + longestCommonSubsequenceUtil(i + 1, j + 1, s1, s2, memo);
        return memo[i][j];
    }

    memo[i][j] = max(
        longestCommonSubsequenceUtil(i + 1, j, s1, s2, memo), 
        longestCommonSubsequenceUtil(i, j + 1, s1, s2, memo)
    );
    return memo[i][j];
}

// Plain recursion:
// TC: O(2^max(n, m))
// AS: O(max(n, m))

// DP:
// TC: O(n*m)
// AS: O(n*m)
int longestCommonSubsequence(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    // 2D memo table - because there are 2 changing params in recursion -> i & j.
    vector<vector<int>> memo(n, vector<int> (m, -1));

    return longestCommonSubsequenceUtil(0, 0, s1, s2, memo);
}

int main() {

    cout << longestCommonSubsequence("ABCDGH", "AEDFHR") << endl;
    cout << longestCommonSubsequence("ABC", "AC") << endl;
    cout << longestCommonSubsequence("", "AC") << endl;
}
