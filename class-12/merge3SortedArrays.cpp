#include<bits/stdc++.h>
using namespace std;

// TC: O(n1 + n2 + n3)
// AS: O(1)
vector<int> merge3SortedArrays(vector<int> A, vector<int> B, vector<int> C) {

    vector<int> result;
    int n1 = A.size();
    int n2 = B.size();
    int n3 = C.size();

    int i = 0, j = 0, k = 0;

    while (i < n1 || j < n2 || k < n3) {
        int a = i < n1 ? A[i] : INT_MAX;
        int b = j < n2 ? B[j] : INT_MAX;
        int c = k < n3 ? C[k] : INT_MAX;

        int newElement = min({a, b, c});

        if (a == newElement) {
            i++;
        } else if (b == newElement) {
            j++;
        } else {
            k++;
        }

        result.push_back(newElement);
    }

    return result;
}

int main() {

    vector<int> res = merge3SortedArrays({1, 2, 3}, {1, 1, 4}, {5, 6, 7, 8});
    for (int i : res) {
        cout << i << " ";
    }
}
