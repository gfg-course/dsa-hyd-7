#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
vector<int> getUniqueElements(vector<int> arr) {

    int n = arr.size();
    int i = 0, j = 0;
    vector<int> result;

    while (j < n) {
        result.push_back(arr[i]);
        while (j < n && arr[j] == arr[i]) {
            j++;
        }
        i = j;
    }

    return result;
}

// TC: O(n)
// AS: O(1)
int getUniqueElementsInPlace(vector<int> &arr) {

    int n = arr.size();
    int i = 0, j = 0;

    while (j < n) {
        arr[i] = arr[j];
        while (j < n && arr[j] == arr[i]) {
            j++;
        }
        i++;
    }

    return i;
}

int main() {

    vector<int> result = getUniqueElements({1, 1, 1, 2, 3, 3, 8, 9, 9, 10});
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> arr = {1, 1, 1, 2, 3, 3, 8, 9, 9, 10};
    int sz = getUniqueElementsInPlace(arr);
    for (int i = 0; i < sz; i++) {
        cout << arr[i] << " ";
    }
}
