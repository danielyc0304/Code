#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
  private:
    vector<list<int>> adjacency_list;

  public:
    int num_vertex;
    int *color,  // 0->白，還沒被找到過, 1->灰，已經被找到過,
                 // 2->黑，已經從queue被移除
        *distance,  // 與起始點的距離，0表示起始點，等於num_vertex表示不可到達
        *predecessor;  // 前一個節點，-1表示沒有前一個節點

    Graph(int num_vertex) {
        this->num_vertex = num_vertex;
        adjacency_list.resize(num_vertex);
    }

    void AddEdge(int from, int to) { adjacency_list[from].push_back(to); }

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
        for (int j = 0; j < num_vertex;
             j++) {  // 寫迴圈是為了考慮圖形內不是所有節點都在同一個集合裡
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
};

int main() {
    Graph graph(9);

    graph.AddEdge(0, 1), graph.AddEdge(0, 2), graph.AddEdge(0, 3);
    graph.AddEdge(1, 0), graph.AddEdge(1, 4);
    graph.AddEdge(2, 0), graph.AddEdge(2, 4), graph.AddEdge(2, 5),
        graph.AddEdge(2, 6), graph.AddEdge(2, 7);
    graph.AddEdge(3, 0), graph.AddEdge(3, 7);
    graph.AddEdge(4, 1), graph.AddEdge(4, 2), graph.AddEdge(4, 5);
    graph.AddEdge(5, 2), graph.AddEdge(5, 4), graph.AddEdge(5, 8);
    graph.AddEdge(6, 2), graph.AddEdge(6, 7), graph.AddEdge(6, 8);
    graph.AddEdge(7, 2), graph.AddEdge(7, 3), graph.AddEdge(7, 6);
    graph.AddEdge(8, 5), graph.AddEdge(8, 6);

    graph.BreadthFirstSearch(0);

    printf("Color:        ");
    for (int i = 0; i < graph.num_vertex; i++) {
        printf("%d ", graph.color[i]);
    }
    printf("\n");

    printf("Distance:     ");
    for (int i = 0; i < graph.num_vertex; i++) {
        printf("%d ", graph.distance[i]);
    }
    printf("\n");

    printf("Predecessor: ");
    for (int i = 0; i < graph.num_vertex; i++) {
        printf("%d ", graph.predecessor[i]);
    }
    printf("\n");

    return 0;
}
