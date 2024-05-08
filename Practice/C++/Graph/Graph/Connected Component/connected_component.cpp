#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
  private:
    int num_vertex;
    vector<list<int>> adjacency_list;
    int *color,  // 0->白，還沒被找到過, 1->灰，已經被找到過,
                 // 2->黑，已經從queue被移除
        *distance,  // 與起始點的距離，0表示起始點，等於num_vertex表示不可到達
        *discover,     // 發現的時間點
        *finish,       // 從i點出發的探索結束的時間點
        *predecessor;  // 前一個節點，-1表示沒有前一個節點

    void PrintPredecessor() {
        printf("Predecessor: ");
        for (int i = 0; i < num_vertex; i++) {
            printf("%4d", predecessor[i]);
        }
        printf("\n");
    }

    void BreadthFirstSearch(int start) {
        color = new int[num_vertex];
        distance = new int[num_vertex];
        predecessor = new int[num_vertex];

        for (int i = 0; i < num_vertex; i++) {
            color[i] = 0;
            distance[i] = num_vertex;
            predecessor[i] = -1;
        }

        int i = start;
        queue<int> vertex;
        for (int j = 0; j < num_vertex; j++) {
            if (color[i] == 0) {
                color[i] = 1;
                distance[i] = 0;
                predecessor[i] = -1;

                vertex.push(i);
                while (vertex.empty() == false) {
                    int new_vertex = vertex.front();

                    for (list<int>::iterator it =
                             adjacency_list[new_vertex].begin();
                         it != adjacency_list[new_vertex].end(); it++) {
                        if (color[*it] == 0) {
                            color[*it] = 1;
                            distance[*it] = distance[new_vertex] + 1;
                            predecessor[*it] = new_vertex;

                            vertex.push(*it);
                        }
                    }

                    color[new_vertex] = 2;
                    vertex.pop();
                }
            }

            i = j;
        }
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
        this->adjacency_list.resize(num_vertex);
    }

    void AddEdge(int from, int to) { adjacency_list[from].push_back(to); }

    void ConnectedComponentBFS(int vertex) {
        BreadthFirstSearch(vertex);
        PrintPredecessor();

        for (int i = 0; i < num_vertex; i++) {
            SetCollapsing(i);
        }
        PrintPredecessor();

        int num_connected_component = 1;
        for (int i = 0; i < num_vertex; i++) {
            if (predecessor[i] < 0) {
                printf("component#%d: %d ", num_connected_component++, i);
                for (int j = 0; j < num_vertex; j++) {
                    if (predecessor[j] == i) {
                        printf("%d ", j);
                    }
                }
                printf("\n");
            }
        }
    }

    void ConnectedComponentDFS(int vertex) {
        DepthFirstSearch(vertex);
        PrintPredecessor();

        for (int i = 0; i < num_vertex; i++) {
            SetCollapsing(i);
        }
        PrintPredecessor();

        int num_connected_component = 1;
        for (int i = 0; i < num_vertex; i++) {
            if (predecessor[i] < 0) {
                printf("component#%d: %d ", num_connected_component++, i);
                for (int j = 0; j < num_vertex; j++) {
                    if (predecessor[j] == i) {
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

    graph.AddEdge(0, 1);
    graph.AddEdge(1, 0), graph.AddEdge(1, 4), graph.AddEdge(1, 5);
    graph.AddEdge(3, 6);
    graph.AddEdge(4, 1), graph.AddEdge(4, 5);
    graph.AddEdge(5, 1), graph.AddEdge(5, 4), graph.AddEdge(5, 7);
    graph.AddEdge(6, 3), graph.AddEdge(6, 8);
    graph.AddEdge(7, 5);
    graph.AddEdge(8, 6);

    graph.ConnectedComponentBFS(0), printf("\n");
    graph.ConnectedComponentDFS(0);

    return 0;
}
