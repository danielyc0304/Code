#include "HeapSorter.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void HeapSorter::loadData(const string& line) {
    data.clear();
    stringstream ss(line);
    int x;
    while (ss >> x) data.push_back(x);
}

void HeapSorter::buildMinHeapTopDown() {
    // TODO: Insert elements one by one and adjust upward to build a min-heap
    // Hint: use heapifyUp(std::vector<int>& heap, int i)

    vector<int> heap;

    for (int i = 0; i < data.size(); ++i) {
        heap.push_back(data[i]);
        heapifyUp(heap, i);
    }

    data = heap;
}

void HeapSorter::buildMinHeapBottomUp() {
    // TODO: Adjust each non-leaf node downward from the middle to build a
    // min-heap

    for (int i = data.size() / 2 - 1; i >= 0; --i) {
        heapifyDown(i);
    }
}

void HeapSorter::heapSortInPlace() {
    // TODO: Repeatedly remove the root and rebuild the min-heap to sort the
    // array

    vector<int> sorted;

    while (data.empty() == false) {
        sorted.push_back(data[0]);
        data[0] = data.back();
        data.pop_back();

        heapifyDown(0);
    }

    data = sorted;
}

void HeapSorter::heapifyUp(std::vector<int>& heap, int i) {
    // TODO: Move the value at index i upward if it's smaller than its parent

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[i] < heap[parent]) {  // 葉節點比較小就換到上面
            swap(heap[i], heap[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

void HeapSorter::heapifyDown(int i) {
    // TODO: Move the value at index i downward if it's larger than its children

    int n = data.size();

    while (i < n) {
        int left = 2 * i + 1, right = 2 * i + 2;
        int smallest = i;

        if (left < n && data[left] < data[smallest]) {
            smallest = left;
        }
        if (right < n && data[right] < data[smallest]) {
            smallest = right;
        }

        if (i != smallest) {  // 找到更小的值
            swap(data[i], data[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

void HeapSorter::heapifyUp(int i) { heapifyUp(data, i); }

void HeapSorter::print(ofstream& out) const {
    for (int val : data) out << val << " ";
    out << "\n";
}

const vector<int>& HeapSorter::getHeap() const { return data; }