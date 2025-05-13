#ifndef __HEAPSORTER_H__
#define __HEAPSORTER_H__

#include <iostream>
#include <vector>

using namespace std;

class HeapSorter {
  private:
    vector<int> data;

    void heapifyUp(std::vector<int>& heap, int i);
    void heapifyUp(int index);
    void heapifyDown(int index);

  public:
    void loadData(const string& line);
    void buildMinHeapTopDown();
    void buildMinHeapBottomUp();
    void heapSortInPlace();
    void print(ofstream& out) const;

    const vector<int>& getHeap() const;
};

#endif