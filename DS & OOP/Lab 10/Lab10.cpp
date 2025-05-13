#include <fstream>
#include <iostream>
#include <string>

#include "HeapSorter.h"
#include "Tools.h"
using namespace std;

int main() {
    vector<string> inputPath, outputPath;
    if (configure(inputPath, outputPath, "./configure.txt") != 0) {
        fprintf(stderr, "configure failed\n");
        return -1;
    }

    int fileIndex;
    string oper;
    ifstream data;
    ofstream out;
    HeapSorter sorter;

    cout << "Input Index: ";
    while (cin >> fileIndex) {
        if (checkFileExist(inputPath[fileIndex - 1]) &&
            checkFileExist(outputPath[fileIndex - 1])) {
            data.open(inputPath[fileIndex - 1]);
            out.open("output.txt");

            while (data >> oper) {
                if (oper == "load") {
                    string line;
                    getline(data, line);
                    sorter.loadData(line);
                } else if (oper == "build_topdown") {
                    sorter.buildMinHeapTopDown();
                } else if (oper == "build_bottomup") {
                    sorter.buildMinHeapBottomUp();
                } else if (oper == "print") {
                    sorter.print(out);
                } else if (oper == "sort") {
                    sorter.heapSortInPlace();
                    sorter.print(out);
                }
            }

            data.close();
            out.close();

            checkAnswer("output.txt", outputPath[fileIndex - 1]);
        }

        cout << "Input Index: ";
    }
}