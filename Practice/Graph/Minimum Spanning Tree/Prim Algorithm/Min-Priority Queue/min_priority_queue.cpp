#include <iostream>
#include <list>
using namespace std;

const int kMaxWeight = 100;

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
        while (i > 1 && heap[i].key < heap[i / 2].key) {
            swap(heap[i], heap[i / 2]);

            i /= 2;
        }
    }
};
class MinimumSpanningTree {
  private:
    int num_vertex;
    vector<list<pair<int, int>>> adjacency_list;
    int *weight, *predecessor;
    bool *visited;

  public:
    MinimumSpanningTree(int num_vertex) {
        this->num_vertex = num_vertex;
        this->adjacency_list.resize(num_vertex);
    }

    void AddEdge(int from, int to, int weight) {
        adjacency_list[from].push_back(make_pair(to, weight));
    }

    void PrimMinPriorityQueue(int start) {
        weight = new int[num_vertex];
        predecessor = new int[num_vertex];
        visited = new bool[num_vertex];

        for (int i = 0; i < num_vertex; i++) {
            weight[i] = kMaxWeight;
            predecessor[i] = -1;
            visited[i] = false;
        }

        weight[start] = 0;

        BinaryHeap min_priority_queue(num_vertex);
        min_priority_queue.BuildMinHeap(weight, num_vertex);

        while (min_priority_queue.IsEmpty() == false) {
            int i = min_priority_queue.ExtractMin();

            visited[i] = true;

            for (list<pair<int, int>>::iterator it = adjacency_list[i].begin();
                 it != adjacency_list[i].end(); it++) {
                if (visited[it->first] == false &&
                    it->second < weight[it->first]) {
                    weight[it->first] = it->second;
                    predecessor[it->first] = i;

                    min_priority_queue.DecreaseKey(it->first,
                                                   weight[it->first]);
                }
            }
        }

        printf("v1 - v2 : weight\n");
        for (int i = (start + 1) % num_vertex; i != start;
             i = ++i % num_vertex) {
            printf(" %d - %d  :   %d\n", predecessor[i], i, weight[i]);
        }
    }

    friend class BinaryHeap;
};

int main() {
    MinimumSpanningTree graph(7);

    graph.AddEdge(0, 1, 5), graph.AddEdge(0, 5, 3);
    graph.AddEdge(1, 0, 5), graph.AddEdge(1, 2, 10), graph.AddEdge(1, 4, 1),
        graph.AddEdge(1, 6, 4);
    graph.AddEdge(2, 1, 10), graph.AddEdge(2, 3, 5), graph.AddEdge(2, 6, 8);
    graph.AddEdge(3, 2, 5), graph.AddEdge(3, 4, 7), graph.AddEdge(3, 6, 9);
    graph.AddEdge(4, 1, 1), graph.AddEdge(4, 3, 7), graph.AddEdge(4, 5, 6),
        graph.AddEdge(4, 6, 2);
    graph.AddEdge(5, 0, 3), graph.AddEdge(5, 4, 6);
    graph.AddEdge(6, 1, 4), graph.AddEdge(6, 2, 8), graph.AddEdge(6, 3, 9),
        graph.AddEdge(6, 4, 2);

    printf("MST found by Prim (Min-Priority Queue):\n");
    graph.PrimMinPriorityQueue(2);

    return 0;
}
