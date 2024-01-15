#include <iostream>
using namespace std;

const int kMaxWeight = 1000;

class MinimumSpanningTree {
  private:
    int num_vertex;
    vector<vector<int>> adjacency_matrix;

    int MinKeyExtract(int *weight, bool *visited, int size) {
        int min = kMaxWeight, i_min = 0;

        for (int i = 0; i < size; i++) {
            if (visited[i] == false && weight[i] < min) {
                min = weight[i];
                i_min = i;
            }
        }

        return i_min;
    }

  public:
    MinimumSpanningTree(int num_vertex) {
        this->num_vertex = num_vertex;
        this->adjacency_matrix.resize(num_vertex);
        for (int i = 0; i < num_vertex; i++) {
            this->adjacency_matrix[i].resize(num_vertex);
        }
    }

    void AddEdge(int from, int to, int weight) {
        adjacency_matrix[from][to] = weight;
    }

    void Prim(int start) {
        int weight[num_vertex], predecessor[num_vertex];
        bool visited[num_vertex];

        for (int i = 0; i < num_vertex; i++) {
            weight[i] = kMaxWeight;
            predecessor[i] = -1;
            visited[i] = false;
        }

        weight[start] = 0;
        for (int i = 0; i < num_vertex; i++) {
            int j = MinKeyExtract(weight, visited, num_vertex);

            visited[j] = true;

            for (int k = 0; k < num_vertex; k++) {
                if (visited[k] == false && adjacency_matrix[j][k] != 0 &&
                    adjacency_matrix[j][k] < weight[k]) {
                    weight[j] = adjacency_matrix[j][k];
                    predecessor[k] = j;
                }
            }
        }

        printf("v1 - v2 : weight\n");
        for (int i = (start + 1) % num_vertex; i != start;
             i = ++i % num_vertex) {
            printf(" %d - %d  :   %d\n", predecessor[i], i,
                   adjacency_matrix[predecessor[i]][i]);
        }
    }
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

    printf("MST found by Prim:\n");
    graph.Prim(2);

    return 0;
}
