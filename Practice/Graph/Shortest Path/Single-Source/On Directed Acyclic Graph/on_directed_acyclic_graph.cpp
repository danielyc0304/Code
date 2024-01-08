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

    void GetTopologicalSort(int *array, int start) {
        int color[num_vertex], discover[num_vertex], finish[num_vertex];

        for (int i = 0; i < num_vertex; i++) {
            color[i] = 0;
            discover[i] = 0;
            finish[i] = 0;
            predecessor[i] = -1;
        }

        int i = start;
        int time = 0;
        int k = num_vertex - 1;
        for (int j = 0; j < num_vertex; j++) {
            if (color[i] == 0) {
                DFSVisit(array, color, discover, finish, i, time, k);
            }

            i = j;
        }

        printf("Discover:\n");
        PrintArray(discover);
        printf("Finish:\n");
        PrintArray(finish);
    }
    void DFSVisit(int *array, int *color, int *discover, int *finish,
                  int vertex, int &time, int &k) {
        color[vertex] = 1;
        discover[vertex] = ++time;

        for (list<pair<int, int>>::iterator it = adjacency_list[vertex].begin();
             it != adjacency_list[vertex].end(); it++) {
            if (color[it->first] == 0) {
                predecessor[it->first] = vertex;

                DFSVisit(array, color, discover, finish, it->first, time, k);
            }
        }

        color[vertex] = 2;
        finish[vertex] = ++time;
        array[k--] = vertex;  // Topological Sort讓finish最小的排在最後面
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
        adjacency_list.resize(num_vertex);
    }

    void AddEdge(int from, int to, int weight) {
        adjacency_list[from].push_back(make_pair(to, weight));
    }

    void DirectedAcyclicGraph(int start) {
        distance = new int[num_vertex];
        predecessor = new int[num_vertex];

        for (int i = 0; i < num_vertex; i++) {
            distance[i] = kMaxDistance;
            predecessor[i] = -1;
        }

        int topological_sort[num_vertex];
        GetTopologicalSort(topological_sort, start);

        distance[start] = 0;
        for (int i = 0; i < num_vertex; i++) {
            int vertex = topological_sort[i];

            for (list<pair<int, int>>::iterator it =
                     adjacency_list[vertex].begin();
                 it != adjacency_list[vertex].end(); it++) {
                Relax(vertex, it->first, it->second);
            }
        }

        printf("Distance:\n");
        PrintArray(distance);
        printf("Predecessor:\n");
        PrintArray(predecessor);
    }
};

int main() {
    SingleSource graph(7);

    graph.AddEdge(0, 1, 3), graph.AddEdge(0, 2, -2);
    graph.AddEdge(1, 3, -4), graph.AddEdge(1, 4, 4);
    graph.AddEdge(2, 4, 5), graph.AddEdge(2, 5, 6);
    graph.AddEdge(3, 5, 8), graph.AddEdge(3, 6, 2);
    graph.AddEdge(4, 3, -3), graph.AddEdge(4, 6, -2);
    graph.AddEdge(5, 6, 2);

    graph.DirectedAcyclicGraph(0), printf("\n");
    graph.DirectedAcyclicGraph(2);

    return 0;
}
