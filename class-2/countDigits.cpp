#include<bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)
int countDigits(int n) {
    if (n == 0) {
        return 1;
    }

    n = abs(n);
    int count = 0;
    while (n != 0) {
        n = n/10;
        count++;
    }
    return count;
}

int main() {

    cout << countDigits(123421) << endl;
    cout << countDigits(0) << endl;
    cout << countDigits(9) << endl;
}
