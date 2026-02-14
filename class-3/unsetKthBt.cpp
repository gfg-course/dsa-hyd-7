#include<bits/stdc++.h>
using namespace std;

int unsetKthBit(int n, int k) {
    return n & (~(1 << k));
}

int main() {

    cout << unsetKthBit(50, 2) << endl;
    cout << unsetKthBit(54, 2) << endl;
}
