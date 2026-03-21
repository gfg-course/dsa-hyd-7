#include<bits/stdc++.h>
using namespace std;

void factUtil(int n, int &result) {
    if (n == 0) {
        return;
    }

    result = result * n;
    factUtil(n - 1, result);
}

// TC: O(n)
// AS: O(n)
int fact(int n) {

    int result = 1;
    factUtil(n, result);
    return result;
}

int main() {

    cout << fact(5) << endl;
}
