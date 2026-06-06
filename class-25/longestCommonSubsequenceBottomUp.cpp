#include<bits/stdc++.h>
using namespace std;

// int longestCommonSubsequenceUtil(int i, int j, string &s1, string &s2, vector<vector<int>> &memo) {
//     if (i == s1.length() || j == s2.length()) {
//         return 0;
//     }

//     if (memo[i][j] != -1) {
//         return memo[i][j];
//     }

//     if (s1[i] == s2[j]) {
//         memo[i][j] = 1 + longestCommonSubsequenceUtil(i + 1, j + 1, s1, s2, memo);
//         return memo[i][j];
//     }

//     memo[i][j] = max(
//         longestCommonSubsequenceUtil(i + 1, j, s1, s2, memo), 
//         longestCommonSubsequenceUtil(i, j + 1, s1, s2, memo)
//     );
//     return memo[i][j];
// }

// TC: O(n*m)
// AS: O(n*m)
int longestCommonSubsequence(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int> (m + 1));

    // Step-1: Tackle the base-conditions.
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 0;
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    // Step-2: Tackle the actual cases in the reverse direction.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n][m];
}

int main() {

    cout << longestCommonSubsequence("ABCDGH", "AEDFHR") << endl;
    // cout << longestCommonSubsequence("ABC", "AC") << endl;
    // cout << longestCommonSubsequence("", "AC") << endl;
}
