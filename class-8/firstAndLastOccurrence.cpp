#include<bits/stdc++.h>
using namespace std;

int getFirstOcc(vector<int> &arr, int target) {

    int result = -1;
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            result = mid;
            high = mid - 1;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int getLastOcc(vector<int> &arr, int target) {

    int result = -1;
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            result = mid;
            low = mid + 1;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

// TC: O(log(n))
// AS: O(1)
pair<int, int> getFirstAndLastOcc(vector<int> arr, int target) {
    
    int firstOcc = getFirstOcc(arr, target);

    if (firstOcc == -1) {
        return {-1, -1};
    }
    int lastOcc = getLastOcc(arr, target);

    return {firstOcc, lastOcc};
}

int main() {

    pair<int, int> result = getFirstAndLastOcc({1, 3, 5, 5, 5, 5, 67, 123, 125}, 5);
    pair<int, int> result2 = getFirstAndLastOcc({1, 3, 5, 5, 5, 5, 67, 123, 125}, 67);
    pair<int, int> result3 = getFirstAndLastOcc({1, 3, 5, 5, 5, 5, 67, 123, 125}, 69);

    cout << result.first << " " << result.second << endl;
    cout << result2.first << " " << result2.second << endl;
    cout << result3.first << " " << result3.second << endl;
}
