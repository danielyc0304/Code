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

  public:
    Graph(int num_vertex) {
        this->num_vertex = num_vertex;
        adjacency_list.resize(num_vertex);
    }

    void AddEdgeList(int from, int to) { adjacency_list[from].push_back(to); }

    void TopologicalSort(int start) {
        DepthFirstSearch(start);

        int finish_large_to_small[num_vertex];
        for (int i = 0; i < num_vertex; i++) {
            finish_large_to_small[i] = i;
        }
        QuickSort(finish, 0, num_vertex - 1, finish_large_to_small);

        printf("Topological sort:\n");
        for (int i = 0; i < num_vertex; i++) {
            printf("%d ", finish_large_to_small[i]);
        }
        printf("\n");
    }
};

int main() {
    Graph graph(15);
    graph.AddEdgeList(0, 2);
    graph.AddEdgeList(1, 2);
    graph.AddEdgeList(2, 6), graph.AddEdgeList(2, 7);
    graph.AddEdgeList(3, 4);
    graph.AddEdgeList(4, 5);
    graph.AddEdgeList(5, 6), graph.AddEdgeList(5, 14);
    graph.AddEdgeList(6, 8), graph.AddEdgeList(6, 9), graph.AddEdgeList(6, 11),
        graph.AddEdgeList(6, 12);
    graph.AddEdgeList(7, 8);
    graph.AddEdgeList(9, 10);
    graph.AddEdgeList(12, 13);

    graph.TopologicalSort(0);
    graph.TopologicalSort(4);

    return 0;
}
