#include <fstream>
#include <iostream>
#include <sstream>

#include "BST.h"
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
    int numOper;
    char oper;
    string dataStr;
    istringstream iss;
    ifstream data;
    ofstream out;
    BST bst;

    cout << "Input Index: ";
    while (cin >> fileIndex) {
        if (checkFileExist(inputPath[fileIndex - 1]) &&
            checkFileExist(outputPath[fileIndex - 1])) {
            data.open(inputPath[fileIndex - 1]);
            out.open("output.txt");

            data >> numOper;
            data.ignore();
            if (getline(data, dataStr)) {
                istringstream iss(dataStr);
                while (iss >> num) {
                    bst.InsertNode(num);
                }
            }

            while (numOper--) {
                data >> oper;
                data >> num;
                switch (oper) {
                    case '+':
                        bst.InsertNode(num);
                        break;
                    case '-':
                        bst.DeleteNode(num);
                        break;
                    default:
                        cout << "Error\n";
                        break;
                }
            }
            bst.Output(out);

            data.close();
            out.close();
            dataStr.clear();
            bst.clear();
            checkAnswer("output.txt", outputPath[fileIndex - 1]);
        }

        cout << "Input Index: ";
    }
}