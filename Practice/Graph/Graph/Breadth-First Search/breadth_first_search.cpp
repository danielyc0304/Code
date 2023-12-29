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
        *distance,  // 與起始點的距離，0表示起始點，無限大表示不可到達
        *predecessor;  // 前一個節點，-1表示沒有前一個節點

  public:
    Graph(int num_vertex) {
        this->num_vertex = num_vertex;
        adjacency_list.resize(num_vertex);
    }

    void AddEdgeList(int from, int to) { adjacency_list[from].push_back(to); }

    void BreadthFirstSearch(int start) {
        color = new int[num_vertex];
        distance = new int[num_vertex];
        predecessor = new int[num_vertex];

        for (int i = 0; i < num_vertex; i++) {
            color[i] = 0;
            distance[i] = num_vertex + 1;
            predecessor[i] = -1;
        }

        int i = start;
        queue<int> node;
        for (int j = 0; j < num_vertex;
             j++) {  // 需要寫迴圈是為了考慮圖形內不是所有節點都在同一個集合裡
            if (color[i] == 0) {
                color[i] = 1;
                distance[i] = 0;
                predecessor[i] = -1;

                node.push(i);
                while (node.empty() == false) {
                    int new_node = node.front();

                    for (list<int>::iterator it =
                             adjacency_list[new_node].begin();
                         it != adjacency_list[new_node].end(); it++) {
                        if (color[*it] == 0) {
                            color[*it] = 1;
                            distance[*it] = distance[new_node] + 1;
                            predecessor[*it] = new_node;

                            node.push(*it);
                        }
                    }

                    color[new_node] = 2;
                    node.pop();
                }
            }

            i = j;
        }
    }
};

int main() {
    Graph graph(9);

    graph.AddEdgeList(0, 1), graph.AddEdgeList(0, 2), graph.AddEdgeList(0, 3);
    graph.AddEdgeList(1, 0), graph.AddEdgeList(1, 4);
    graph.AddEdgeList(2, 0), graph.AddEdgeList(2, 4), graph.AddEdgeList(2, 5),
        graph.AddEdgeList(2, 6), graph.AddEdgeList(2, 7);
    graph.AddEdgeList(3, 0), graph.AddEdgeList(3, 7);
    graph.AddEdgeList(4, 1), graph.AddEdgeList(4, 2), graph.AddEdgeList(4, 5);
    graph.AddEdgeList(5, 2), graph.AddEdgeList(5, 4), graph.AddEdgeList(5, 8);
    graph.AddEdgeList(6, 2), graph.AddEdgeList(6, 7), graph.AddEdgeList(6, 8);
    graph.AddEdgeList(7, 2), graph.AddEdgeList(7, 3), graph.AddEdgeList(7, 6);
    graph.AddEdgeList(8, 5), graph.AddEdgeList(8, 6);

    graph.BreadthFirstSearch(0);

    return 0;
}
