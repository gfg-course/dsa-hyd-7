#include<bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)
// TODO: Write a generic solution up till k decimal places.
int sqrt(int n) {

    int low = 0, high = n;
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (mid * mid <= n) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {

    cout << sqrt(25) << endl;
    cout << sqrt(30) << endl;
    cout << sqrt(0) << endl;
}
