#include <iostream>
#include <queue>
using namespace std;

class FlowNetworks {
  private:
    int num_vertex;
    vector<vector<int>> adjacency_matrix;

    bool BFSFindExistingPath(vector<vector<int>> &residual_graph,
                             int *predecessor, int source, int termination) {
        bool visited[num_vertex];

        for (int i = 0; i < num_vertex; i++) {
            visited[i] = false;
            predecessor[i] = -1;
        }

        queue<int> vertex;

        vertex.push(source);
        visited[source] = true;
        while (vertex.empty() == false) {
            int exploring = vertex.front();

            for (int i = 0; i < num_vertex; i++) {
                if (residual_graph[exploring][i] != 0 && visited[i] == false) {
                    vertex.push(i);
                    visited[i] = true;
                    predecessor[i] = exploring;
                }
            }

            vertex.pop();
        }

        return (visited[termination] == true);
    }

    int MinCapacity(vector<vector<int>> &residual_graph, int *predecessor,
                    int termination) {
        int min = 100;

        for (int j = termination; predecessor[j] != -1;
             j = predecessor[j]) {  // 用上面BFS存的predecessor去找出路徑
            int i = predecessor[j];
            if (residual_graph[i][j] != 0 && residual_graph[i][j] < min) {
                min = residual_graph[i][j];
            }
        }

        return min;
    }

  public:
    FlowNetworks(int num_vertex) {
        this->num_vertex = num_vertex;
        this->adjacency_matrix.resize(num_vertex);
        for (int i = 0; i < num_vertex; i++) {
            this->adjacency_matrix[i].resize(num_vertex);
        }
    }

    void AddEdge(int from, int to, int capacity) {
        adjacency_matrix[from][to] = capacity;
    }

    void FordFulkerson(int source, int termination) {
        vector<vector<int>> residual_graph(adjacency_matrix);
        int max_flow = 0;
        int predecessor[num_vertex];

        while (BFSFindExistingPath(residual_graph, predecessor, source,
                                   termination)) {
            int min_capacity =
                MinCapacity(residual_graph, predecessor, termination);

            max_flow += min_capacity;

            for (int j = termination; j != source; j = predecessor[j]) {
                int i = predecessor[j];

                residual_graph[i][j] -= min_capacity;
                residual_graph[j][i] +=
                    min_capacity;  // TODO
                                   // skew-symmetry，不加這行也不會影響，目前不知道這樣寫的意義是什麼
            }
        }

        printf("Possible max flow: %d\n", max_flow);
    }
};

int main() {
    FlowNetworks graph(6);

    graph.AddEdge(0, 1, 9), graph.AddEdge(0, 3, 9);
    graph.AddEdge(1, 2, 3), graph.AddEdge(1, 3, 8);
    graph.AddEdge(2, 4, 2), graph.AddEdge(2, 5, 9);
    graph.AddEdge(3, 2, 7), graph.AddEdge(3, 4, 7);
    graph.AddEdge(4, 2, 4), graph.AddEdge(4, 5, 8);

    graph.FordFulkerson(0, 5);

    return 0;
}
