#include<bits/stdc++.h>
using namespace std;

// TC: TODO
// AS: O(n)
vector<int> nextGreater(vector<int> arr) {
    stack<int> helper;

    int n = arr.size();
    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!helper.empty() && helper.top() < arr[i]) {
            helper.pop();
        }

        if (helper.empty()) {
            result[i] = -1;
        } else {
            result[i] = helper.top();
        }

        helper.push(arr[i]);
    }

    return result;  
}

int main() {
}
