#include<bits/stdc++.h>
using namespace std;

string getHashKey(string s) {
    vector<int> freq(26, 0);
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
    }

    string key = "";
    for (int i = 0; i < 26; i++) {
        key += to_string(freq[i]);
        key += "#";
    }

    return key;
}

// TC: O(nm)
// AS: O(nm)
// TODO - convert this to O(n) by using unordered_map<string, vector<int>> hashmap.
vector<vector<string>> groupAnagramsTogether(vector<string> arr) {
    unordered_map<string, vector<string>> groupedAnagrams;

    for (int i = 0; i < arr.size(); i++) {
        string hashKey = getHashKey(arr[i]);

        if (groupedAnagrams.find(hashKey) == groupedAnagrams.end()) {
            groupedAnagrams[hashKey] = {};
        }

        groupedAnagrams[hashKey].push_back(arr[i]);
    }

    vector<vector<string>> result;

    for (auto entry : groupedAnagrams) {
        result.push_back(entry.second);
    }

    return result;
}

int main() {

    vector<vector<string>> result = groupAnagramsTogether({"act", "god", "cat", "dog", "tac"});
    for (auto i : result) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
