#include<bits/stdc++.h>
using namespace std;

// TC: O(k*log(k) + (n-k)*(log(k))) = O((k+n-k)*log(k)) = O(n*log(k))
// AS: O(k)
int kthLargestElement(vector<int> arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minPQ;
    int n = arr.size();

    // Step-1: Insert the first K elements in the min-heap.
    for (int i = 0; i < k; i++) {
        minPQ.push(arr[i]);
    }

    // Step-2:
    // For the rest of the elements:
    // If arr[i] < min-so-far -> skip it
    // If arr[i] > min-so-far -> kick-out the min-so-far and 
    // insert arr[i] to the list of top-k-largest-elements.
    for (int i = k; i < n; i++) {
        if (arr[i] > minPQ.top()) {
            minPQ.pop();
            minPQ.push(arr[i]);
        }
    }

    return minPQ.top();
}

int main() {

    cout << kthLargestElement({3, 5, 4, 2, 9, 10}, 3) << endl;
    cout << kthLargestElement({3, 5, 4, 2, 9, 10}, 1) << endl;
    cout << kthLargestElement({3, 5, 4, 2, 9, 10}, 6) << endl;
}
