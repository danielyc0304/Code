#include "Graph.h"

Node* Graph::addNode(int value) {
    // TODO
    // Hint: use findNode() to check if the node exists
    Node* node = findNode(value);

    if (node != nullptr) {
        return node;
    }

    Node* newNode = new Node(value);

    nodes.push_back(newNode);

    return newNode;
}

Node* Graph::findNode(int value) {
    // TODO
    // Return the node if it exists, otherwise return nullptr
    for (Node* node : nodes) {
        if (node->value == value) {
            return node;
        }
    }

    return nullptr;
}

Edge* Graph::addEdge(Node* node1, Node* node2) {
    // TODO
    // Hint: use findEdge() to check if the edge exists
    Edge* edge = findEdge(node1, node2);

    if (edge != nullptr) {
        return edge;
    }

    Edge* newEdge = new Edge(node1, node2);

    edges.push_back(newEdge);

    return newEdge;
}

Edge* Graph::findEdge(Node* node1, Node* node2) {
    // TODO
    // Return the edge if it exists, otherwise return nullptr
    for (Edge* edge : edges) {
        if ((edge->node1 == node1 && edge->node2 == node2) ||
            (edge->node1 == node2 && edge->node2 == node1)) {
            return edge;
        }
    }

    return nullptr;
}

void Graph::BFS(vector<int>& answer) {
    // TODO
    // Implement BFS using a queue
    // Hint: Node* startNode = nodes[0];
    // Hint: Use a queue
    queue<Node*> qu;

    qu.push(nodes[0]);

    while (qu.empty() == false) {
        Node* curr = qu.front();
        qu.pop();

        if (visited.find(curr) != visited.end()) {
            continue;
        }

        visited[curr] = true;
        answer.push_back(curr->value);

        for (Edge* edge : edges) {
            if (edge->node1 == curr &&
                visited.find(edge->node2) == visited.end()) {
                qu.push(edge->node2);
            } else if (edge->node2 == curr &&
                       visited.find(edge->node1) == visited.end()) {
                qu.push(edge->node1);
            }
        }
    }
}
