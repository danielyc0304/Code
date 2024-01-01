#include <iostream>
#include <list>
using namespace std;

class Graph {
  private:
    int num_vertex;
    vector<list<int>> adjacency_list;
    int *color,     // 0->白，還沒被找到過, 1->灰，已經被找到過,
                    // 2->黑，已經從遞迴中結束
        *discover,  // 發現的時間點
        *finish,    // 從i點出發的探索結束的時間點
        *predecessor;  // 前一個節點，-1表示沒有前一個節點

    void PrintArray(int *array) {
        for (int i = 0; i < num_vertex; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    void PrintFinish() {
        for (int i = 0; i < num_vertex; i++) {
            printf("%d ", finish[i]);
        }
        printf("\n");
    }
    void PrintPredecessor() {
        for (int i = 0; i < num_vertex; i++) {
            printf("%d ", predecessor[i]);
        }
        printf("\n");
    }

    void DepthFirstSearch(int start) {
        color = new int[num_vertex];
        discover = new int[num_vertex];
        finish = new int[num_vertex];
        predecessor = new int[num_vertex];

        for (int i = 0; i < num_vertex; i++) {
            color[i] = 0;
            discover[i] = 0;
            finish[i] = 0;
            predecessor[i] = -1;
        }

        int i = start;
        int time = 0;
        for (int j = 0; j < num_vertex; j++) {
            if (color[i] == 0) {
                DFSVisit(i, time);
            }

            i = j;
        }
    }
    void DFSVisit(int vertex, int &time) {
        color[vertex] = 1;
        discover[vertex] = ++time;

        for (list<int>::iterator it = adjacency_list[vertex].begin();
             it != adjacency_list[vertex].end(); it++) {
            if (color[*it] == 0) {
                predecessor[*it] = vertex;

                DFSVisit(*it, time);
            }
        }

        color[vertex] = 2;
        finish[vertex] = ++time;
    }

    Graph GraphTranspose() {
        Graph graph_transpose(num_vertex);

        for (int i = 0; i < num_vertex; i++) {
            for (list<int>::iterator it = adjacency_list[i].begin();
                 it != adjacency_list[i].end(); it++) {
                graph_transpose.AddEdgeList(*it, i);
            }
        }

        return graph_transpose;
    }

    int Partition(int *finish, int front, int end, int *finish_large_to_small) {
        int pivot = finish[end];

        int i = front - 1;

        for (int j = front; j < end; j++) {
            if (finish[j] > pivot) {
                swap(finish[++i], finish[j]);
                swap(finish_large_to_small[i], finish_large_to_small[j]);
            }
        }
        swap(finish[++i], finish[end]);
        swap(finish_large_to_small[i], finish_large_to_small[end]);

        return i;
    }
    void QuickSort(int *finish, int front, int end,
                   int *finish_large_to_small) {
        if (front < end) {
            int pivot = Partition(finish, front, end, finish_large_to_small);

            QuickSort(finish, front, pivot - 1, finish_large_to_small);
            QuickSort(finish, pivot + 1, end, finish_large_to_small);
        }
    }

    void VariableInitializeDFS() {
        color = new int[num_vertex];
        discover = new int[num_vertex];
        finish = new int[num_vertex];
        predecessor = new int[num_vertex];

        for (int i = 0; i < num_vertex; i++) {
            color[i] = 0;
            discover[i] = 0;
            finish[i] = 0;
            predecessor[i] = -1;
        }
    }

    void SetCollapsing(int current) {
        int root;
        for (root = current; predecessor[root] >= 0; root = predecessor[root])
            ;

        while (current != root) {
            int parent = predecessor[current];
            predecessor[current] = root;
            current = parent;
        }
    }

  public:
    Graph(int num_vertex) {
        this->num_vertex = num_vertex;
        adjacency_list.resize(num_vertex);
    }

    void AddEdgeList(int from, int to) { adjacency_list[from].push_back(to); }

    void PrintStronlyConnectedComponents(int start) {
        DepthFirstSearch(start);

        printf("First DFS on G, finish time:\n");
        PrintFinish();

        Graph graph_transpose(num_vertex);
        graph_transpose = GraphTranspose();

        int finish_large_to_small[num_vertex];
        for (int i = 0; i < num_vertex; i++) {
            finish_large_to_small[i] = i;
        }
        QuickSort(finish, 0, num_vertex - 1, finish_large_to_small);

        printf("Finish time large to small:\n");
        PrintArray(finish_large_to_small), printf("\n");

        graph_transpose.VariableInitializeDFS();  // 第二次DFS
        int time = 0;
        for (int i = 0; i < num_vertex; i++) {
            if (graph_transpose.color[finish_large_to_small[i]] == 0) {
                graph_transpose.DFSVisit(finish_large_to_small[i], time);
            }
        }

        printf("Second DFS on GT, finish time:\n");
        graph_transpose.PrintFinish();
        printf("Predecessor before SetCollapsing:\n");
        graph_transpose.PrintPredecessor();

        for (int i = 0; i < num_vertex; i++) {
            graph_transpose.SetCollapsing(i);
        }

        printf("Predecessor after SetCollapsing:\n");
        graph_transpose.PrintPredecessor(), printf("\n");

        int num_connected_component = 0;
        for (int i = 0; i < num_vertex; i++) {
            if (graph_transpose.predecessor[i] < 0) {
                printf("component#%d: %d ", ++num_connected_component, i);
                for (int j = 0; j < num_vertex; j++) {
                    if (graph_transpose.predecessor[j] == i) {
                        printf("%d ", j);
                    }
                }
                printf("\n");
            }
        }
    }
};

int main() {
    Graph graph(9);

    graph.AddEdgeList(0, 1);
    graph.AddEdgeList(1, 2), graph.AddEdgeList(1, 4);
    graph.AddEdgeList(2, 0), graph.AddEdgeList(2, 3), graph.AddEdgeList(2, 5);
    graph.AddEdgeList(3, 2);
    graph.AddEdgeList(4, 5), graph.AddEdgeList(4, 6);
    graph.AddEdgeList(5, 4), graph.AddEdgeList(5, 6), graph.AddEdgeList(5, 7);
    graph.AddEdgeList(6, 7);
    graph.AddEdgeList(7, 8);
    graph.AddEdgeList(8, 6);

    printf("Vertex(0) as starting point for the first DFS\n");
    graph.PrintStronlyConnectedComponents(0), printf("\n");

    printf("Vertex(3) as starting point for the first DFS\n");
    graph.PrintStronlyConnectedComponents(3);

    return 0;
}
