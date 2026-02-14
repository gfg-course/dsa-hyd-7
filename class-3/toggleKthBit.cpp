#include<bits/stdc++.h>
using namespace std;

int toggleKthBit(int n, int k) {
    return n ^ (1 << k);
}

int main() {

    cout << toggleKthBit(50, 2) << endl;
    cout << toggleKthBit(54, 2) << endl;
}
