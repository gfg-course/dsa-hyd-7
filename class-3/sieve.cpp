#include<bits/stdc++.h>
using namespace std;

// TC: O(n * log(log(n)))
// AS: O(n)
vector<int> getPrimes(int n) {
    vector<bool> isPrime(n + 1, true);

    for (int i = 2; i*i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> result;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {

    vector<int> res = getPrimes(20);
    for (int i : res) {
        cout << i << " ";
    }
}
