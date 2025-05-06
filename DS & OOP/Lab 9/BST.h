#ifndef __BST_H__
#define __BST_H__

#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(int value)
        : value(value), leftChild(nullptr), rightChild(nullptr) {}
};

class BST {
  private:
    TreeNode* root;
    vector<int> preOrderAnswer;
    vector<int> inOrderAnswer;
    vector<int> postOrderAnswer;

    void destroyTree(TreeNode* node);

  public:
    BST() { root = nullptr; }
    BST(int value) { root = new TreeNode(value); }
    BST(TreeNode* node) { root = node; }
    ~BST() { clear(); }
    void clear();

    void InsertNode(int value);
    void DeleteNode(int value);
    TreeNode* SearchNode(int value);

    void Output(ofstream&);
    void PreOrder(TreeNode* root);
    void InOrder(TreeNode* root);
    void PostOrder(TreeNode* root);
};

#endif