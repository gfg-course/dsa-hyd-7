#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
void merge(vector<int> &arr, int low, int mid, int high) {
    // [low ... mid], [mid + 1 ... high]

    vector<int> temp;
    int i = low, j = mid + 1;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= high) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        arr[low + k] = temp[k];
    }
}

// T(n) = 2 * T(n/2) + n
// TC: O(nlog(n))
// AS: O(n)
void mergeSortUtil(vector<int> &arr, int low, int high) {
    if (low >= high) {
        return;
    }

    int mid = (low + high) / 2;
    mergeSortUtil(arr, low, mid);
    mergeSortUtil(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr) {

    mergeSortUtil(arr, 0, arr.size() - 1);
}

int main() {
}
