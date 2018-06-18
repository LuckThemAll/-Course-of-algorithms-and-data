#include <iostream>
#include <vector>

using namespace std;

vector<int> maxHeap, minHeap;

void insert(int value, vector<int>& heap);
void shiftUp(int value, vector<int>& heap);
void removeFirst(vector<int>& heap);
void heapify(int index, vector<int>& heap);



int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, c;
    cin >> n >> c;
    cout << c << ' ';
    insert(c, maxHeap);
    for (int i = 0; i < n - 1; i++) {
        cin >> c;
        if (maxHeap.size() > 0) {
            if (c > maxHeap[0])
                insert(-1 * c, minHeap);
            else
                insert(c, maxHeap);
            if (maxHeap.size() > minHeap.size()) {
                insert(-1 * maxHeap[0], minHeap);
                removeFirst(maxHeap);
            }
            if (maxHeap.size() < minHeap.size()) {
                insert(-1 * minHeap[0], maxHeap);
                removeFirst(minHeap);
            }
        }
        cout << maxHeap[0] << ' ';
    }
}

void insert(int value, vector<int>& heap) {
    heap.push_back(value);
    shiftUp(heap.size() - 1, heap);
}

void shiftUp(int index, vector<int>& heap) {
    if (index <= 0)
        return;
    if (heap[(index - 1) / 2] < heap[index]) {
        swap(heap[(index - 1) / 2], heap[index]);
        shiftUp((index - 1) / 2, heap);
    }
}

void removeFirst(vector<int>& heap) {
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    heapify(0, heap);
}

void heapify(int index, vector<int>& heap) {
    int temp, left, right;

    temp = index;
    left = 2 * index + 1;
    right = 2 * index + 2;
    if (left < heap.size() && heap[left] > heap[temp])
        temp = left;
    if (right < heap.size() && heap[right] > heap[temp])
        temp = right;
    if (temp != index) {
        swap(heap[index], heap[temp]);
        heapify(temp, heap);
    }
}