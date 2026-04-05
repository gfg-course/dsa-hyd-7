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
int largestAreaInHistogram(vector<int> heights) {

    int n = heights.size();
    vector<int> prevSmaller = getPrevSmaller(heights);
    vector<int> nextSmaller = getNextSmaller(heights);

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = nextSmaller[i] - prevSmaller[i] - 1;
        maxArea = max(maxArea, width * heights[i]);
    }

    return maxArea;
}

int main() {
    cout << largestAreaInHistogram({6, 2, 5, 4, 5, 1, 6}) << endl;
}