#include<bits/stdc++.h>
using namespace std;

// TC: O(1)
bool isPowerOf2(int n) {
    if (n == 0) {
        return false;
    }

    return (n & (n - 1)) == 0;
}

int main() {

    cout << isPowerOf2(16) << endl;
    cout << isPowerOf2(20) << endl;
    cout << isPowerOf2(15) << endl;
}
