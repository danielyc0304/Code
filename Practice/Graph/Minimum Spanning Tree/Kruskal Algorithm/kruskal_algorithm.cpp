#include <iostream>
using namespace std;

struct Edge {
    int from, to, weight;

    Edge() {}
    Edge(int from, int to, int weight) {
        this->from = from, this->to = to;
        this->weight = weight;
    }
};
class MinimumSpanningTree {
  private:
    int num_vertex;
    vector<vector<int>> adjacency_matrix;

    static bool WeightCmp(Edge a, Edge b) { return a.weight < b.weight; }
    void GetSortedEdge(vector<Edge> &increase_weight) {
        for (int i = 0; i < num_vertex - 1; i++) {
            for (int j = i + 1; j < num_vertex; j++) {
                if (adjacency_matrix[i][j] != 0) {
                    increase_weight.push_back(
                        Edge(i, j, adjacency_matrix[i][j]));
                }
            }
        }

        sort(increase_weight.begin(), increase_weight.end(), WeightCmp);
    }

    int FindSetCollapsing(int *parent, int i) {
        int root;
        for (root = i; parent[root] >= 0; root = parent[root])
            ;

        while (i != root) {
            int preceding = parent[i];
            parent[i] = root;
            i = preceding;
        }

        return root;
    }
    void UnionSet(int *parent, int i, int j) {
        int i_root = FindSetCollapsing(parent, i),
            j_root = FindSetCollapsing(parent, j);

        if (parent[i_root] <=
            parent[j_root]) {  // i_root下面的元素比較多或一樣多
            parent[i_root] += parent[j_root];
            parent[j_root] = i_root;
        } else {  // j_root下面的元素比較多
            parent[j_root] += parent[i_root];
            parent[i_root] = j_root;
        }
    }

  public:
    MinimumSpanningTree(int num_vertex) {
        this->num_vertex = num_vertex;
        adjacency_matrix.resize(num_vertex);
        for (int i = 0; i < num_vertex; i++) {
            adjacency_matrix[i].resize(num_vertex);
        }
    }

    void AddEdge(int from, int to, int weight) {
        adjacency_matrix[from][to] = weight;
    }

    void KruskalMST() {
        vector<Edge> increase_weight;
        int parent[num_vertex];
        Edge *edge_set_MST = new Edge[num_vertex - 1];

        for (int i = 0; i < num_vertex; i++) {
            parent[i] = -1;
        }

        GetSortedEdge(increase_weight);

        int j = 0;
        for (int i = 0; i < increase_weight.size(); i++) {
            if (FindSetCollapsing(parent, increase_weight[i].from) !=
                FindSetCollapsing(parent, increase_weight[i].to)) {
                edge_set_MST[j++] = increase_weight[i];
                UnionSet(parent, increase_weight[i].from,
                         increase_weight[i].to);
            }
        }

        printf("v1 - v2 : weight\n");
        for (int i = 0; i < num_vertex - 1; i++) {
            printf(" %d - %d  :   %d\n", edge_set_MST[i].from,
                   edge_set_MST[i].to, edge_set_MST[i].weight);
        }
    }
};

int main() {
    MinimumSpanningTree graph(7);

    graph.AddEdge(0, 1, 5), graph.AddEdge(0, 5, 3);
    graph.AddEdge(1, 0, 5), graph.AddEdge(1, 2, 10),
        graph.AddEdge(1, 4, 1), graph.AddEdge(1, 6, 4);
    graph.AddEdge(2, 1, 10), graph.AddEdge(2, 3, 5),
        graph.AddEdge(2, 6, 8);
    graph.AddEdge(3, 2, 5), graph.AddEdge(3, 4, 7),
        graph.AddEdge(3, 6, 9);
    graph.AddEdge(4, 1, 1), graph.AddEdge(4, 3, 7),
        graph.AddEdge(4, 5, 6), graph.AddEdge(4, 6, 2);
    graph.AddEdge(5, 0, 3), graph.AddEdge(5, 4, 6);
    graph.AddEdge(6, 1, 4), graph.AddEdge(6, 2, 8),
        graph.AddEdge(6, 3, 9), graph.AddEdge(6, 4, 2);

    printf("MST found by Kruskal:\n");
    graph.KruskalMST();

    return 0;
}
