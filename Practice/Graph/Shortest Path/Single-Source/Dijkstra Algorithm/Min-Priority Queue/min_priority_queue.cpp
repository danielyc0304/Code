#include <iostream>
#include <list>
using namespace std;

const int kMaxDistance = 100;

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
class SingleSource {
  private:
    int num_vertex;
    vector<list<pair<int, int>>> adjacency_list;
    int *distance, *predecessor;
    bool *visited;

    void PrintArray(int *array) {
        for (int i = 0; i < num_vertex; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    void Relax(int from, int to, int weight) {
        if (distance[to] > distance[from] + weight) {
            distance[to] = distance[from] + weight;
            predecessor[to] = from;
        }
    }

  public:
    SingleSource(int num_vertex) {
        this->num_vertex = num_vertex;
        this->adjacency_list.resize(num_vertex);
    }

    void AddEdge(int from, int to, int weight) {
        adjacency_list[from].push_back(make_pair(to, weight));
    }

    void Dijkstra(int start) {
        distance = new int[num_vertex];
        predecessor = new int[num_vertex];
        visited = new bool[num_vertex];

        for (int i = 0; i < num_vertex; i++) {
            distance[i] = kMaxDistance;
            predecessor[i] = -1;
            visited[i] = false;
        }

        distance[start] = 0;

        BinaryHeap min_priority_queue(num_vertex);
        min_priority_queue.BuildMinHeap(distance, num_vertex);

        while (min_priority_queue.IsEmpty() == false) {
            int i = min_priority_queue.ExtractMin();

            for (list<pair<int, int>>::iterator it = adjacency_list[i].begin();
                 it != adjacency_list[i].end(); it++) {
                Relax(i, it->first, it->second);

                min_priority_queue.DecreaseKey(it->first, distance[it->first]);
            }
        }

        printf("Distance: "), PrintArray(distance);
        printf("Predecessor: "), PrintArray(predecessor);
    }
};

int main() {
    SingleSource graph(6);

    graph.AddEdge(0, 1, 8), graph.AddEdge(0, 5, 1);
    graph.AddEdge(1, 0, 3), graph.AddEdge(1, 2, 1);
    graph.AddEdge(2, 0, 5), graph.AddEdge(2, 3, 2), graph.AddEdge(2, 4, 2);
    graph.AddEdge(3, 1, 4), graph.AddEdge(3, 2, 6), graph.AddEdge(3, 4, 7),
        graph.AddEdge(3, 5, 3);
    graph.AddEdge(5, 3, 2), graph.AddEdge(5, 4, 8);

    graph.Dijkstra(0);

    return 0;
}
