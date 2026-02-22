#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
vector<int> productExceptSelf(vector<int> nums) {

    int n = nums.size();
    int prefixProd;
    vector<int> suffixProd(n);
    vector<int> ans(n);

    prefixProd = 1;
    // for (int i = 1; i < n; i++) {
    //     prefixProd[i] = prefixProd[i - 1] * nums[i - 1];
    // }

    suffixProd[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        suffixProd[i] = suffixProd[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < n; i++) {
        ans[i] = prefixProd * suffixProd[i];
        prefixProd = prefixProd * nums[i];
    }
    return ans;
}

int main() {

    vector<int> ans = productExceptSelf({1, 2, 3, 4});
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> ans2 = productExceptSelf({-1, 1, 0, -3, 3});
    for (int i : ans2) {
        cout << i << " ";
    }
}
