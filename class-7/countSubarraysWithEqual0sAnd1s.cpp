#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
int countSubarraysWithEqual0sAnd1s(vector<int> arr) {
    int n = arr.size();
    unordered_map<int, int> sumFreq;
    int sum = 0;
    sumFreq[sum] = 1;

    int result = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            sum++;
        } else {
            sum--;
        }

        result += sumFreq[sum];

        sumFreq[sum]++;
    }

    return result;

}

int main() {

    cout << countSubarraysWithEqual0sAnd1s({1, 0, 0, 1, 0, 1, 1}) << endl;
    cout << countSubarraysWithEqual0sAnd1s({0, 1, 1, 0}) << endl;
}
