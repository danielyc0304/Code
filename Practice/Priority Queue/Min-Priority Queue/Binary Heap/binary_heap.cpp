#include <iostream>
using namespace std;

struct HeapNode {
    int key, value;

    HeapNode() { this->key = 0, this->value = 0; }
    HeapNode(int key, int value) { this->key = key, this->value = value; }
};
class BinaryHeap {
  private:
    vector<HeapNode> heap;

    void MinHeapify(int root, int size) {
        int left = 2 * root, right = 2 * root + 1, smallest;

        if (left <= size && heap[left].key < heap[root].key) {
            smallest = left;
        } else {
            smallest = root;
        }
        if (right <= size && heap[right].key < heap[smallest].key) {
            smallest = right;
        }

        if (smallest != root) {
            swap(heap[root], heap[smallest]);

            MinHeapify(smallest, size);
        }
    }

    int FindPosition(int value) {
        int i = 0;

        for (int j = 1; j < heap.size(); j++) {
            if (heap[j].value == value) {
                i = j;
            }
        }

        return i;
    }

  public:
    BinaryHeap(int size) { heap.resize(size + 1); }

    void BuildMinHeap(vector<int> &key) {
        for (int i = 0; i < key.size(); i++) {
            heap[i + 1].key = key[i];
            heap[i + 1].value = i;
        }

        for (int i = heap.size() / 2; i >= 1; i--) {
            MinHeapify(i, heap.size() - 1);
        }
    }

    bool IsEmpty() { return (heap.size() == 1); }

    int ExtractMin() {
        if (IsEmpty() == true) {
            printf("Heap is empty.\n");

            exit(-1);
        }

        int min = heap[1].value;

        heap[1] = heap[heap.size() - 1];
        heap.erase(heap.end() - 1);

        MinHeapify(1, heap.size());

        return min;
    }

    void DecreaseKey(int value, int new_key) {
        int i = FindPosition(value);

        if (new_key > heap[i].key) {
            printf("New key is larger than current key.\n");

            return;
        }

        heap[i].key = new_key;
        while (i > 1 && heap[i / 2].key > heap[i].key) {
            swap(heap[i], heap[i / 2]);

            i /= 2;
        }
    }

    void MinHeapInsert(int key, int value) {
        heap.push_back(HeapNode(key, value));

        DecreaseKey(value, key);  // DecreaseKey並不會阻止key ==
                                  // new_key的情況，所以直接拿來做插入
    }
};

int main() { return 0; }
