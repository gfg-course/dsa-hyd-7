#include<bits/stdc++.h>
using namespace std;

// TC: O(H) -> O(log(n))
// AS: O(1) -> since the fun is tail recursive.
void topDownHeapify(vector<int> &heap, int index) {

    int leftChildIndex = 2*index + 1;
    int rightChildIndex = 2*index + 2;

    int maxValueIndex = index;
    if (leftChildIndex < heap.size() && heap[leftChildIndex] > heap[maxValueIndex]) {
        maxValueIndex = leftChildIndex;
    }
    if (rightChildIndex < heap.size() && heap[rightChildIndex] > heap[maxValueIndex]) {
        maxValueIndex = rightChildIndex;
    }

    if (maxValueIndex != index) {
        swap(heap[index], heap[maxValueIndex]);
        topDownHeapify(heap, maxValueIndex);
    }
}

// TC: O(log(n))
// AS: O(1)
void deleteFromHeap(vector<int> &heap) {

    int n = heap.size();

    // Step-1: Replace root with the last node and delete the last node.
    heap[0] = heap[n - 1];
    heap.pop_back();

    // Step-2: Top-Down Heapify on the root node.
    topDownHeapify(heap, 0);
}


// TC: O(log(n))
// AS: O(1) as it is tail recursive.
void bottomUpHeapify(vector<int> &heap, int index) {
    if (index == 0) {
        return;
    }

    int parentIndex = (index - 1) / 2;

    if (heap[index] > heap[parentIndex]) {
        swap(heap[index], heap[parentIndex]);
        bottomUpHeapify(heap, parentIndex);
    }
}

// TC: O(log(n))
// AS: O(1)
void insertToHeap(vector<int> &heap, int value) {

    // Step-1: Insert the new node as the last node in the tree.
    heap.push_back(value);

    // Step-2: Perform Bottom-Up Heapify on the newly inserted node.
    bottomUpHeapify(heap, heap.size() - 1);
}

int main() {

    vector<int> heap = {100, 50, 30, 40, 15, 30, 20};
    deleteFromHeap(heap);

    for (int i : heap) {
        cout << i << " ";
    }

    cout << endl;

    vector<int> heap2 = {100, 50, 30, 40, 15, 30, 20};
    insertToHeap(heap2, 90);

    for (int i : heap2) {
        cout << i << " ";
    }
}
