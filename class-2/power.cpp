#include<bits/stdc++.h>
using namespace std;

// TC: O(log(b))
// AS: O(log(b))
int power(int a, int b) {
    if (b == 0) {
        return 1;
    }

    int temp = power(a, b/2);
    if (b%2 == 0) {
        return temp * temp;
    }
    return temp * temp * a;
}

int main() {

    cout << power(2, 10) << endl;
    cout << power(2012312, 1) << endl;
}
