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
    BinaryHeap(int size) { this->heap.resize(size + 1); }

    void BuildMinHeap(int *key, int size) {
        for (int i = 0; i < size; i++) {
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
            return -1;
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
        while (i > 1 && heap[i].key < heap[i / 2].key) {
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

int main() {
    int size;
    printf("Enter size: "), scanf("%d", &size);
    BinaryHeap min_priority_queue(size);

    int key[size];
    printf("Enter keys: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &key[i]);
    }
    cin.get();
    min_priority_queue.BuildMinHeap(key, size);

    string action;
    while (printf("Enter action: ") && getline(cin, action)) {
        if (action == "is empty") {
            printf("%s\n",
                   (min_priority_queue.IsEmpty() == true) ? "true" : "false");
        } else if (action == "extract min") {
            int num = min_priority_queue.ExtractMin();

            if (num == -1) {
                printf("Heap is empty.\n");
            } else {
                printf("%d\n", num);
            }
        } else if (action == "decrease key") {
            int value, new_key;

            printf("Enter value: "), scanf("%d", &value);
            printf("Enter new key: "), scanf("%d", &new_key);
            min_priority_queue.DecreaseKey(value, new_key);
        } else if (action == "min heap insert") {
            int key, value;

            printf("Enter key: "), scanf("%d", &key);
            printf("Enter value: "), scanf("%d", &value);
            min_priority_queue.MinHeapInsert(key, value);
        } else if (action == "exit") {
            break;
        } else {
            printf("Invalid action.\n");
        }
    }

    return 0;
}
