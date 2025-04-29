#pragma once

#include <sys/stat.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool checkFileExist(const string &checkFile);
int configure(vector<string> &inputFiles, vector<string> &outputFiles,
              const string configureName);
bool checkAnswer(const string &filename1, const string &filename2);

bool checkFileExist(const string &checkFile) {
    struct stat fileInfo;
    return (stat(checkFile.c_str(), &fileInfo) == 0);
}

int configure(vector<string> &inputFiles, vector<string> &outputFiles,
              const string configureName) {
    ifstream conf(configureName);
    if (!conf.is_open()) {
        fprintf(stderr, "configure error\n");
        return -1;
    }

    string inputPath, outputPath;
    while (conf >> inputPath && conf >> outputPath) {
        inputFiles.push_back(inputPath);
        outputFiles.push_back(outputPath);
    }
    conf.close();
    return 0;
}

string normalizeLine(const string &line) {
    string result;
    for (size_t i = 0; i < line.length(); ++i) {
        char c = line[i];
        if (!isspace(c)) result += c;
    }
    return result;
}

bool checkAnswer(const string &output, const string &sample_output) {
    ifstream outFile(output);
    ifstream ansFile(sample_output);

    if (!outFile.is_open() || !ansFile.is_open()) {
        cerr << "Error: Unable to open one or both files.\n";
        return false;
    }

    string outLine, ansLine;
    getline(outFile, outLine);
    getline(ansFile, ansLine);

    outFile.close();
    ansFile.close();

    outLine = normalizeLine(outLine);
    ansLine = normalizeLine(ansLine);

    return outLine == ansLine;
}