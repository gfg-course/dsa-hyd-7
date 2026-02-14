#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n) {

    int result = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            result++;
        }
        n = (n >> 1);
    }

    return result;
}

int countSetBitsOptimal(int n) {

    int result = 0;
    while (n > 0) {
        n = (n & (n - 1));
        result++;
    }
    return result;
}

int main() {

    cout << countSetBits(20) << endl;
    cout << countSetBitsOptimal(20) << endl;
}
