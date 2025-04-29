#include <fstream>
#include <iostream>
#include <vector>

#include "Graph.h"
#include "Tools.h"

using namespace std;

int main() {
    vector<string> inputPath, outputPath;
    if (configure(inputPath, outputPath, "./configure.txt") != 0) {
        fprintf(stderr, "configure failed\n");
        return -1;
    }

    int fileIndex;
    int num;
    int value1, value2;
    ifstream data;
    ofstream out;

    cout << "Input Index: ";
    while (cin >> fileIndex) {
        Graph graph;
        if (checkFileExist(inputPath[fileIndex - 1]) &&
            checkFileExist(outputPath[fileIndex - 1])) {
            data.open(inputPath[fileIndex - 1]);
            out.open("output.txt");

            data >> num;
            for (int i = 0; i < num; i++) {
                data >> value1 >> value2;
                Node* node1 = graph.addNode(value1);
                Node* node2 = graph.addNode(value2);
                Edge* edge = graph.addEdge(node1, node2);
            }

            graph.BFS(graph.answer);
            for (int i = 0; i < graph.answer.size(); i++) {
                out << graph.answer[i] << " ";
            }

            data.close();
            out.close();
            if (checkAnswer("output.txt", outputPath[fileIndex - 1])) {
                cout << "True\n";
            } else {
                cout << "False\n";
            }
        }
        cout << "Input Index: ";
    }
}