#include<bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)
int searchInSortedRotatedArray(vector<int> arr, int target) {

    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] >= arr[0]) { // [low ... mid] is sorted.
            if (target >= arr[low] && target <= arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else { // [mid ... high] is sorted.
            if (target >= arr[mid] && target <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {

    cout << searchInSortedRotatedArray({5, 6, 7, 8, 9, 10, 1, 2, 3}, 7) << endl;
    cout << searchInSortedRotatedArray({5, 6, 7, 8, 9, 10, 1, 2, 3}, 2) << endl;
    cout << searchInSortedRotatedArray({5, 6, 7, 8, 9, 10, 1, 2, 3}, 10) << endl;
    cout << searchInSortedRotatedArray({5, 6, 7, 8, 9, 10, 1, 2, 3}, 1) << endl;
    cout << searchInSortedRotatedArray({5, 6, 7, 8, 9, 10, 1, 2, 3}, 5) << endl;
    cout << searchInSortedRotatedArray({5, 6, 7, 8, 9, 10, 1, 2, 3}, 3) << endl;
    cout << searchInSortedRotatedArray({10, 11, 12, 13, 8, 9}, 11) << endl;

    cout << searchInSortedRotatedArray({5, 6, 7, 8, 9, 10, 1, 2, 3}, -1) << endl;
    cout << searchInSortedRotatedArray({5, 6, 7, 8, 9, 10, 1, 2, 3}, 4) << endl;
    cout << searchInSortedRotatedArray({5, 6, 7, 8, 9, 10, 1, 2, 3}, 11) << endl;
}
