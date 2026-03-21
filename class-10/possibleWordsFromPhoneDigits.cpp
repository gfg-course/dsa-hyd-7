#include<bits/stdc++.h>
using namespace std;

vector<string> keypad = {
    "",
    "", "abc", "def",
    "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz"
};

void possibleWordsFromPhoneDigitsUtil(int i, vector<int> &arr, string &curr, vector<string> &result) {
    if (i == arr.size()) {
        result.push_back(curr);
        return;
    }

    string word = keypad[arr[i]];

    for (char ch : word) {
        curr.push_back(ch);
        possibleWordsFromPhoneDigitsUtil(i + 1, arr, curr, result);
        curr.pop_back();
    }
}

// T(n) = 4*T(n - 1) + C
// TC: O(4^n)
// AS: O(n)
vector<string> possibleWordsFromPhoneDigits(vector<int> arr) {

    string curr = "";
    vector<string> result;

    possibleWordsFromPhoneDigitsUtil(0, arr, curr, result);
    return result;
}

int main() {

    vector<string> result = possibleWordsFromPhoneDigits({2, 3, 4});
    cout << result.size() << endl;

    for (auto i : result) {
        cout << i << " ";
    }
}
