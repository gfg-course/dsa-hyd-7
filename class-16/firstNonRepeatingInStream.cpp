#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(26 + 26) = O(1)
string getFirstNonRepeatingInStream(string s) {

    unordered_map<char, int> freq;
    queue<char> q;
    string res;

    for (int i = 0; i < s.length(); i++) {
        freq[s[i]]++;

        if (freq[s[i]] == 1) {
            q.push(s[i]);
        }

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) {
            res.push_back('#');
        } else {
            res.push_back(q.front());
        }
    }

    return res;
}

int main() {

    cout << getFirstNonRepeatingInStream("aabc") << endl;
    cout << getFirstNonRepeatingInStream("zz") << endl;
    cout << getFirstNonRepeatingInStream("aaaaaa") << endl;
    cout << getFirstNonRepeatingInStream("abcdef") << endl;
    cout << getFirstNonRepeatingInStream("") << endl;
    cout << getFirstNonRepeatingInStream("aabcbc") << endl;
}
