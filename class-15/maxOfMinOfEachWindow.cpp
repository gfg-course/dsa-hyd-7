#include<bits/stdc++.h>
using namespace std;

vector<int> getPrevSmaller(vector<int> &heights) {
    stack<int> helper;

    int n = heights.size();
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        while (!helper.empty() && heights[helper.top()] >= heights[i]) {
            helper.pop();
        }

        if (helper.empty()) {
            result[i] = -1;
        } else {
            result[i] = helper.top();
        }

        helper.push(i);
    }

    return result; 
}

vector<int> getNextSmaller(vector<int> &heights) {
    stack<int> helper;

    int n = heights.size();
    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!helper.empty() && heights[helper.top()] >= heights[i]) {
            helper.pop();
        }

        if (helper.empty()) {
            result[i] = n;
        } else {
            result[i] = helper.top();
        }

        helper.push(i);
    }

    return result; 
}

// TC: O(n)
// AS: O(n)
vector<int> getMaxOfMinOfEachWindow(vector<int> arr) {

    int n = arr.size();

    vector<int> prevSmaller = getPrevSmaller(arr);
    vector<int> nextSmaller = getNextSmaller(arr);

    vector<int> result(n, INT_MIN);

    for (int i = 0; i < n; i++) {
        int width = nextSmaller[i] - prevSmaller[i] - 1;
        result[width - 1] = max(result[width - 1], arr[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        result[i] = max(result[i], result[i + 1]);
    }

    return result;
}

int main() {
    vector<int> result = getMaxOfMinOfEachWindow({10, 20, 30, 50, 10, 70, 30});
    for (int i : result) {
        cout << i << " ";
    }
}