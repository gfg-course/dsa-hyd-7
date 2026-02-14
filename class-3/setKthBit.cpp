#include<bits/stdc++.h>
using namespace std;

int setKthBit(int n, int k) {
    return n | (1 << k);
}

int main() {

    cout << setKthBit(50, 2) << endl;
    cout << setKthBit(54, 2) << endl;
}
