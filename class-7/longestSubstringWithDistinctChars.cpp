#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(26) = O(1)
int getLongestSubstrWithDistinctChars(string s) {

    unordered_map<char, bool> charsVisited;
    int n = s.length();

    int i = 0, j = 0;
    int result = 0;

    while (j < n) {
        if (charsVisited[s[j]] == false) {
            charsVisited[s[j]] = true;
            result = max(result, j - i + 1);
        } else {
            while (i < j && s[i] != s[j]) {
                charsVisited[s[i]] = false;
                i++;
            }
            i++;
        }
        j++;
    }

    return result;
}


// TC: O(n)
// AS: O(26) = O(1)
int getLongestSubstrWithDistinctCharsUsingArray(string s) {

    vector<bool> charsVisited(26, false);
    int n = s.length();

    int i = 0, j = 0;
    int result = 0;

    while (j < n) {
        if (charsVisited[s[j] - 'a'] == false) {
            charsVisited[s[j] -'a'] = true;
            result = max(result, j - i + 1);
        } else {
            while (i < j && s[i] != s[j]) {
                charsVisited[s[i] - 'a'] = false;
                i++;
            }
            i++;
        }
        j++;
    }

    return result;
}

int main() {

    cout << getLongestSubstrWithDistinctChars("geeksforgeeks") << endl;
    cout << getLongestSubstrWithDistinctChars("aaa") << endl;
}
