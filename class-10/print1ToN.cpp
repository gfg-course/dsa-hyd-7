#include<bits/stdc++.h>
using namespace std;

void print1ToNUtil(int start, int n) {
    if (start > n) {
        return;
    }

    cout << start << endl;
    print1ToNUtil(start + 1, n);
}

// TC: O(n)
// AS: O(1) - because of tail recursion.
void print1ToN(int n) {
    print1ToNUtil(1, n);
}

int main() {

    print1ToN(10);
}
