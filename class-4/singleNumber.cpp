#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int getSingleNumber(vector<int> arr) {

    int result = 0;
    for (int i = 0; i < arr.size(); i++) {
        result = (result ^ arr[i]);
    }

    return result;
}

int main() {

    cout << getSingleNumber({1}) << endl;
    cout << getSingleNumber({1, 2, 5, 2, 7, 5, 1});
}
