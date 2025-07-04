#include <iostream>
#include <list>
using namespace std;

class Graph {
  private:
    vector<list<int>> adjacency_list;

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

  public:
    int num_vertex;
    int *color,     // 0->白，還沒被找到過, 1->灰，已經被找到過,
                    // 2->黑，已經從遞迴中結束
        *discover,  // 發現的時間點
        *finish,    // 從i點出發的探索結束的時間點
        *predecessor;  // 前一個節點，-1表示沒有前一個節點

    Graph(int num_vertex) {
        this->num_vertex = num_vertex;
        this->adjacency_list.resize(num_vertex);
    }

    void AddEdge(int from, int to) { adjacency_list[from].push_back(to); }

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
        for (int j = 0; j < num_vertex;
             j++) {  // 寫迴圈是為了考慮圖形內不是所有節點都在同一個集合裡
            if (color[i] == 0) {
                DFSVisit(i, time);
            }

            i = j;
        }
    }
};

int main() {
    Graph graph(8);

    graph.AddEdge(0, 1), graph.AddEdge(0, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 1), graph.AddEdge(2, 5);
    graph.AddEdge(3, 4), graph.AddEdge(3, 5);
    graph.AddEdge(5, 1);
    graph.AddEdge(6, 4), graph.AddEdge(6, 7);
    graph.AddEdge(7, 6);

    graph.DepthFirstSearch(0);

    printf("Color:       ");
    for (int i = 0; i < graph.num_vertex; i++) {
        printf("%d ", graph.color[i]);
    }
    printf("\n");

    printf("Discover:    ");
    for (int i = 0; i < graph.num_vertex; i++) {
        printf("%d ", graph.discover[i]);
    }
    printf("\n");

    printf("Finish:      ");
    for (int i = 0; i < graph.num_vertex; i++) {
        printf("%d ", graph.finish[i]);
    }
    printf("\n");

    printf("Predecessor: ");
    for (int i = 0; i < graph.num_vertex; i++) {
        printf("%d ", graph.predecessor[i]);
    }
    printf("\n");

    return 0;
}
