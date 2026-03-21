#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
int fact(int n) {
    if (n == 1) {
        return 1;
    }

    return n * fact(n - 1);
}

int main() {

    cout << fact(5) << endl;
}
