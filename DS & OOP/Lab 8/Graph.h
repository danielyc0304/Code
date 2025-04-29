#pragma once
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int value;
    vector<Node*> neighbors;
    Node(int val) : value(val) {}
};

struct Edge {
    Node* node1;
    Node* node2;
    Edge(Node* n1, Node* n2) : node1(n1), node2(n2) {}
};
class Graph {
  private:
    vector<Node*> nodes;
    vector<Edge*> edges;
    map<Node*, bool> visited;

  public:
    Graph() {}
    ~Graph() {
        for (Node* node : nodes) {
            delete node;
        }
        for (Edge* edge : edges) {
            delete edge;
        }
        answer.clear();
    }

    vector<int> answer;

    Node* addNode(int value);
    Node* findNode(int value);
    Edge* addEdge(Node* node1, Node* node2);
    Edge* findEdge(Node* node1, Node* node2);

    void BFS(vector<int>& answer);
};