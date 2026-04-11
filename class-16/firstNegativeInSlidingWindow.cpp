#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(k)
vector<int> getFirstNegativeInSlidingWindow(vector<int> arr, int k) {
    int n = arr.size();
    queue<int> q;
    vector<int> result;

    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            q.push(i);
        }
    }
    
    if (q.empty()) {
        result.push_back(0);
    } else {
        result.push_back(arr[q.front()]);
    }

    for (int i = k; i < n; i++) {
        if (arr[i] < 0) {
            q.push(i);
        }
        if (!q.empty() && q.front() <= i - k) {
            q.pop();
        }

        if (q.empty()) {
            result.push_back(0);
        } else {
            result.push_back(arr[q.front()]);
        }
    }

    return result;
}

int main() {

    vector<int> res1 = getFirstNegativeInSlidingWindow({-8, 2, 3, -6, 10}, 2);
    vector<int> res2 = getFirstNegativeInSlidingWindow({12, -1, -7, 8, -15, 30, 16, 28}, 3);
    vector<int> res3 = getFirstNegativeInSlidingWindow({12, 1, 3, 5}, 3);

    for (int i : res1) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : res2) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : res3) {
        cout << i << " ";
    }
}
