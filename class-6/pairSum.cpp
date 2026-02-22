#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
bool checkPairWithTargetSum(vector<int> arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low < high) {
        if (arr[low] + arr[high] == target) {
            return true;
        }
        if (arr[low] + arr[high] > target) {
            high--;
        } else {
            low++;
        }
    }

    return false;
}

int main() {

    cout << checkPairWithTargetSum({1, 3, 4, 10, 11}, 8) << endl;
    cout << checkPairWithTargetSum({1, 3, 4, 4, 11}, 8) << endl;
    cout << checkPairWithTargetSum({1, 3, 4, 10, 11}, 4) << endl;
    cout << checkPairWithTargetSum({1, 3, 4, 10, 11}, 21) << endl;
    cout << checkPairWithTargetSum({1, 3, 4, 10, 11}, 13) << endl;
    cout << checkPairWithTargetSum({-10, -3, 4, 10, 11}, 1) << endl;
    cout << checkPairWithTargetSum({-10, -3, 4, 10, 11}, -12) << endl;
    cout << checkPairWithTargetSum({-10, -3, 0, 4, 10, 11}, 4) << endl;
}
