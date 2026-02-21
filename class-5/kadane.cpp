#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int getMaxSubarraySum(vector<int> arr) {
    int n = arr.size();

    int maxSum = arr[0];
    int result = maxSum;

    for (int i = 1; i < n; i++) {
        maxSum = max(arr[i], maxSum + arr[i]);
        result = max(result, maxSum);
    }
    return result;
}

int main() {
    cout << getMaxSubarraySum({-10, 1, 3, 6, -2, 5, -20, -11, 10}) << endl;
    cout << getMaxSubarraySum({-1, -4, -2, -3});
}
