#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(k)
vector<int> getMaxInSlidingWindow(vector<int> arr, int k) {
    int n = arr.size();
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    result.push_back(arr[dq.front()]);

    for (int i = k; i < n; i++) {
        if (dq.front() <= i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        result.push_back(arr[dq.front()]);
    }

    return result;
}

int main() {

    vector<int> res1 = getMaxInSlidingWindow({1, 2, 3, 1, 4, 5, 2, 3, 6}, 3);
    vector<int> res2 = getMaxInSlidingWindow({5, 4, 3, 2, 1}, 3);
    vector<int> res3 = getMaxInSlidingWindow({1, 2, 3, 4, 5}, 3);
    vector<int> res4 = getMaxInSlidingWindow({1, 1, 1, 1}, 2);
    vector<int> res5 = getMaxInSlidingWindow({1, 2, 3, 1, 4, 5, 2, 3, 6}, 9);
    vector<int> res6 = getMaxInSlidingWindow({1, 2, 3, 1, 4, 5, 2, 3, 6}, 1);

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
    cout << endl;
    for (int i : res4) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : res5) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : res6) {
        cout << i << " ";
    }
    cout << endl;
}
