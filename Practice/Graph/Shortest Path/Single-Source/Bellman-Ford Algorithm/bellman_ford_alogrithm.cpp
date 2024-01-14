#include <iostream>
#include <list>
using namespace std;

const int kMaxDistance = 100;

class SingleSource {
  private:
    int num_vertex;
    vector<list<pair<int, int>>> adjacency_list;
    int *distance, *predecessor;

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

    bool BellmanFord(int start) {
        distance = new int[num_vertex];
        predecessor = new int[num_vertex];

        for (int i = 0; i < num_vertex; i++) {
            distance[i] = kMaxDistance;
            predecessor[i] = -1;
        }

        distance[start] = 0;
        for (
            int i = 0; i < num_vertex - 1;
            i++) {  // 跑num_vertex-1次是因為最多只有num_vertex-1條路徑，全部走過是最壞的情況，這樣是為了避免進入negative
                    // cycle
            for (int j = 0; j < num_vertex; j++) {
                for (list<pair<int, int>>::iterator it =
                         adjacency_list[j].begin();
                     it != adjacency_list[j].end(); it++) {
                    Relax(j, it->first, it->second);
                }
            }
        }

        for (int i = 0; i < num_vertex; i++) {
            for (list<pair<int, int>>::iterator it = adjacency_list[i].begin();
                 it != adjacency_list[i].end(); it++) {
                if (distance[it->first] > distance[i] + it->second) {
                    return false;
                };
            }
        }

        printf("Distance: "), PrintArray(distance);
        printf("Predecessor: "), PrintArray(predecessor);

        return true;
    }
};

int main() {
    SingleSource graph(6);

    graph.AddEdge(0, 1, 5);
    graph.AddEdge(1, 2, 6), graph.AddEdge(1, 4, -4);
    graph.AddEdge(2, 4, -3), graph.AddEdge(2, 5, -2);
    graph.AddEdge(3, 2, 4);
    graph.AddEdge(4, 3, 1), graph.AddEdge(4, 5, 6);
    graph.AddEdge(5, 0, 3), graph.AddEdge(5, 1, 7);

    if (graph.BellmanFord(0)) {
        printf("There is no negative cycle.\n");
    } else {
        printf("There is negative cycle.\n");
    }

    return 0;
}
