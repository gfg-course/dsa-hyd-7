#include<bits/stdc++.h>
using namespace std;

// T(n) = 2*T(n - 1) + c;
// TC: O(2^n)
// AS: O(n)
int towerOfHanoi(int n, string A, string B, string C) {
    if (n == 0) {
        return 0;
    }

    int result = towerOfHanoi(n - 1, A, C, B);
    
    result++;
    cout << "Move " << n << "-th disk from " << A << " to " << C << endl;

    result += towerOfHanoi(n - 1, B, A, C);

    return result;
}

// TC: O(n)
// AS: O(n)
int towerOfHanoiOptimal(int n) {
    if (n == 0) {
        return 0;
    }

    // int result = towerOfHanoiOptimal(n - 1);
    // result++;
    // result += towerOfHanoiOptimal(n - 1);

    return 2*towerOfHanoiOptimal(n - 1) + 1;
}

int main() {

    cout << towerOfHanoi(2, "A", "B", "C") << endl;
    cout << towerOfHanoi(3, "A", "B", "C") << endl;

    cout << towerOfHanoiOptimal(2) << endl;
    cout << towerOfHanoiOptimal(3) << endl;

}
