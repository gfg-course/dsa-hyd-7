#include<bits/stdc++.h>
using namespace std;

// TC: O(n^2)
// AS: O(1)

// TODO: Solve the k-sum problem using recursion.
bool checkTripletWithGivenSum(vector<int> arr, int target) {
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {
        int low = i + 1, high = arr.size() - 1;
        while (low < high) {
            if (arr[low] + arr[high] == target - arr[i]) {
                return true;
            }
            if (arr[low] + arr[high] > target - arr[i]) {
                high--;
            } else {
                low++;
            }
        }
    }

    return false;
}

int main() {
    cout << checkTripletWithGivenSum({1, 4, 45, 6, 10, 8}, 13) << endl;
    cout << checkTripletWithGivenSum({1, 4, 45, 6, 10, 8}, 30) << endl;
}
