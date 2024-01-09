#include <iostream>
using namespace std;

const int kMaxDistance = 1000;

class AllPairs {
  private:
    int num_vertex;
    vector<vector<int>> adjacency_matrix;
    vector<vector<int>> distance, predecessor;

    void PrintArray(vector<vector<int>> array) {
        for (int i = 0; i < num_vertex; i++) {
            for (int j = 0; j < num_vertex; j++) {
                printf("%5d", array[i][j]);
            }
            printf("\n");
        }
    }

  public:
    AllPairs(int num_vertex) {
        this->num_vertex = num_vertex;
        adjacency_matrix.resize(num_vertex);
        for (int i = 0; i < num_vertex; i++) {
            adjacency_matrix[i].resize(num_vertex, kMaxDistance);

            adjacency_matrix[i][i] = 0;
        }
    }

    void AddEdge(int from, int to, int weight) {
        adjacency_matrix[from][to] = weight;
    }

    void FloydWarshall() {
        distance.resize(num_vertex);
        predecessor.resize(num_vertex);

        for (int i = 0; i < num_vertex; i++) {
            distance[i].resize(num_vertex);
            predecessor[i].resize(num_vertex, -1);

            for (int j = 0; j < num_vertex; j++) {
                distance[i][j] = adjacency_matrix[i][j];
                if (distance[i][j] != 0 && distance[i][j] != kMaxDistance) {
                    predecessor[i][j] = i;
                }
            }
        }

        printf("Initial Distance:\n");
        PrintArray(distance);
        printf("Initial Predecessor:\n");
        PrintArray(predecessor);
        printf("\n");

        for (int k = 0; k < num_vertex; k++) {  // k是新加入的節點
            for (int i = 0; i < num_vertex; i++) {
                for (int j = 0; j < num_vertex; j++) {
                    if (distance[i][j] > distance[i][k] + distance[k][j] &&
                        distance[i][k] != kMaxDistance &&
                        distance[k][j] !=
                            kMaxDistance) {  // 因為不等式的右邊兩個值有可能一個是無限大一個是很小的負值，導致就算無法到達，相加之後還是有可能會比左值小，所以要加上條件確認兩條路都可以到達
                        distance[i][j] = distance[i][k] + distance[k][j];
                        predecessor[i][j] = predecessor[k][j];
                    }
                }
            }

            printf("Including vertex(%d)\n", k);
            printf("Distance:\n");
            PrintArray(distance);
            printf("Predecessor:\n");
            PrintArray(predecessor);
            printf("\n");
        }
    }
};

int main() {
    AllPairs graph(4);

    graph.AddEdge(0, 1, 2), graph.AddEdge(0, 2, 6), graph.AddEdge(0, 3, 8);
    graph.AddEdge(1, 2, -2), graph.AddEdge(1, 3, 3);
    graph.AddEdge(2, 0, 4), graph.AddEdge(2, 3, 1);

    graph.FloydWarshall();

    return 0;
}
