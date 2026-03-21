#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1) - because of tail recursion.
void printNTo1(int n) {
    if (n == 0) {
        return;
    }

    cout << n << endl;
    printNTo1(n - 1);
}

int main() {

    printNTo1(10);
}
