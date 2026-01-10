#include<bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1) - tail recursive.
void topDownHeapify(int index, vector<int> &heap) {
    // Base case - Not required as we are making conditional recursive calls.

    int leftChildIndex = 2*index + 1;
    int rightChildIndex = 2*index + 2;

    // We need the index having the maximum value among [index, leftChildIndex, rightChildIndex]
    int maxValueIndex = index;
    if (leftChildIndex < heap.size() && heap[leftChildIndex] > heap[maxValueIndex]) {
        maxValueIndex = leftChildIndex;
    }
    if (rightChildIndex < heap.size() && heap[rightChildIndex] > heap[maxValueIndex]) {
        maxValueIndex = rightChildIndex;
    }

    if (maxValueIndex != index) {
        swap(heap[index], heap[maxValueIndex]);
        topDownHeapify(maxValueIndex, heap);
    }
}

// TC: O(log(n))
// AS: O(1) - tail recursive.
void deleteFromHeap(vector<int> &heap) {
    int n = heap.size();
    if (n == 0) {
        return;
    }

    // Step-1:
    swap(heap[0], heap[n - 1]);
    heap.pop_back();

    // Step-2:
    topDownHeapify(0, heap);
}

// TC: O(log(n))
// AS: O(1) - tail rec
void bottomUpHeapify(int index, vector<int> &heap) {
    if (index == 0) {
        return;
    }

    int parentIndex = (index - 1) / 2;

    if (heap[index] > heap[parentIndex]) {
        swap(heap[index], heap[parentIndex]);
        bottomUpHeapify(parentIndex, heap);
    }
}

// TC: O(log(n))
// AS: O(1) - tail rec
void insertIntoHeap(vector<int> &heap, int value) {
    // Step-1:
    heap.push_back(value);

    // Step-2:
    bottomUpHeapify(heap.size() - 1, heap);
}

int main() {

    vector<int> heap = {100, 50, 20, 10, 5, 6, 8, 7, 3};
    deleteFromHeap(heap);

    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> heap2 = {10, 5, 3, 2, 4};
    insertIntoHeap(heap2, 15);
    insertIntoHeap(heap2, 14);

    for (int i : heap2) {
        cout << i << " ";
    }
}
