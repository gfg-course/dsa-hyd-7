#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int getSingleNumber(vector<int> arr) {
    
    int n = arr.size();
    vector<int> freq(32, 0);

    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int pos = 0;

        // finding the set bits in each position of arr[i] (num).
        while (pos < 32) {
            if (num % 2 == 1) {
                freq[pos]++;
            }
            pos++;
            num = (num >> 1); // num >>= 1;
        }
    }

    int mul = 1;
    int result = 0;
    for (int i = 0; i < 32; i++) {
        result += (freq[i] % 3) * mul;
        mul *= 2;
    }

    return result;
}

int main() {

    cout << getSingleNumber({1}) << endl;
    cout << getSingleNumber({1, 2, 1, 1, 2, 3, 2}) << endl;
}
