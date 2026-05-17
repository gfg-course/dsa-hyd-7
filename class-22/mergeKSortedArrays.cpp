#include<bits/stdc++.h>
using namespace std;

// TC: O(k^2 * log(k))
// AS: O(k)
vector<int> mergeKSortedArrays(vector<vector<int>> arr) {
    int k = arr.size();
    vector<int> result;

    // Min-Heap containing: {value, {i, j}}
    priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pointersPQ;

    for (int i = 0; i < k; i++) {
        pointersPQ.push({arr[i][0], {i, 0}});
    }

    while (!pointersPQ.empty()) {
        pair<int, pair<int, int>> current = pointersPQ.top();
        pointersPQ.pop();

        result.push_back(current.first);
        int i = current.second.first;
        int j = current.second.second;

        if (j + 1 < k) {
            pointersPQ.push({arr[i][j + 1], {i, j + 1}});
        }
    }

    return result;
}

int main() {

    vector<int> res = mergeKSortedArrays(
        {
            {4, 8, 10, 12},
            {1, 1, 3, 5},
            {23, 25, 30, 100},
            {4, 9, 11, 15}
        }
    );

    for (int i : res) {
        cout << i << " ";
    }
}
