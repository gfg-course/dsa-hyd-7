#include<bits/stdc++.h>
using namespace std;

// TODO: Painter's Partition Problem.

// If possible to allocate books such that no student gets more than mid pages.
bool isPossible(vector<int> &books, int M, int mid) {

    int numStudents = 1, numPages = 0;
    for (int i = 0; i < books.size(); i++) {
        if (numPages + books[i] <= mid) {
            numPages += books[i];
        } else {
            numStudents++;
            numPages = books[i];
        }
    }

    // if (numStudents <= M) {
    //     return true;
    // } else {
    //     return false;
    // }
    return numStudents <= M;
}

// TC: O(n * log(sum))
// AS: O(1)
int getMinimumOfMaximumPages(vector<int> books, int M) {
    int n = books.size();
    
    if (n < M) {
        return -1;
    }

    int low = books[0];
    int high = books[0];

    for (int i = 1; i < n; i++) {
        low = max(low, books[i]);
        high += books[i];
    }

    int result = high;
    while (low <= high) {

        int mid = (low + high) / 2;
        if (isPossible(books, M, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    cout << getMinimumOfMaximumPages({10, 20, 10, 30}, 2) << endl;
    cout << getMinimumOfMaximumPages({12, 34, 67, 90}, 2) << endl;
    cout << getMinimumOfMaximumPages({10, 20, 10, 30}, 5) << endl;
    cout << getMinimumOfMaximumPages({10, 20, 10, 30}, 1) << endl;
    cout << getMinimumOfMaximumPages({10, 20, 10, 30}, 4) << endl;
}
