#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
bool checkSubarrayWith0Sum(vector<int> arr) {
    int n = arr.size();
    int sum = 0;

    unordered_set<int> sumsVisited;
    sumsVisited.insert(sum);

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        
        // If the sum has been seen before.
        if (sumsVisited.find(sum) != sumsVisited.end()) {
            return true;
        }

        sumsVisited.insert(sum);
    }

    return false;
}

int main() {

    cout << checkSubarrayWith0Sum({4, 2, -3, 1, 6}) << endl;
    cout << checkSubarrayWith0Sum({4, 2, 0, 1, 6}) << endl;
    cout << checkSubarrayWith0Sum({2, -3, 1, 4, 6}) << endl;
    cout << checkSubarrayWith0Sum({4, 6, 1, 2, -3}) << endl;
    cout << checkSubarrayWith0Sum({0, -3, 1, 4, 6}) << endl;
    cout << checkSubarrayWith0Sum({-5, 3, 1, 4, -3}) << endl;
    cout << checkSubarrayWith0Sum({3, 1, 4, 6}) << endl;
    
}
