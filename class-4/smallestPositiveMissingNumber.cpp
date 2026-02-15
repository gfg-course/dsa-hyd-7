#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int smallestPositiveMissingNumber(vector<int> arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (arr[i] <= 0) {
            arr[i] = n + 2;
        }
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = abs(arr[i]) - 1;
        if (bucketIndex >= 0 && bucketIndex <= n - 1 && arr[bucketIndex] > 0) {
            arr[bucketIndex] *= -1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {

    cout << smallestPositiveMissingNumber({1, 2, 3, 4, 5}) << endl;
    cout << smallestPositiveMissingNumber({0, -10, 1, 3, -20}) << endl;
    cout << smallestPositiveMissingNumber({1, 1, 4, 3, 5}) << endl;
}
