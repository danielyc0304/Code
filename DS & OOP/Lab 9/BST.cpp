#include "BST.h"

void BST::InsertNode(int value) {
    // TODO: Implement this function to add a new node while maintaining BST
    // properties.

    TreeNode* newNode = new TreeNode(value);

    if (root == nullptr) {
        root = newNode;

        return;
    }

    TreeNode* curr = root;

    while (curr != nullptr) {
        if (value < curr->value) {
            if (curr->leftChild == nullptr) {
                curr->leftChild = newNode;

                return;
            } else {
                curr = curr->leftChild;
            }
        } else {
            if (curr->rightChild == nullptr) {
                curr->rightChild = newNode;

                return;
            } else {
                curr = curr->rightChild;
            }
        }
    }
}

void BST::DeleteNode(int value) {
    // TODO: Implement this function to remove a node and rearrange the tree
    // correctly. If the node has both a left and right child, the node should
    // be replaced with the maximum value node from its left subtree. Hint: Use
    // SearchNode()

    TreeNode *prev, *curr = root;

    while (curr != nullptr && curr->value != value) {
        prev = curr;

        if (curr->value > value) {
            curr = curr->leftChild;
        } else {
            curr = curr->rightChild;
        }
    }

    if (curr->leftChild == nullptr &&
        curr->rightChild == nullptr) {  // 是葉節點
        if (curr == root) {
            root = nullptr;
        } else if (prev->leftChild == curr) {
            prev->leftChild = nullptr;
        } else {
            prev->rightChild = nullptr;
        }

        delete curr;
    } else if ((curr->leftChild != nullptr) !=
               (curr->rightChild != nullptr)) {  // 有一個子節點
        TreeNode* tmp =
            (curr->leftChild != nullptr) ? curr->leftChild : curr->rightChild;

        if (curr == root) {
            root = tmp;
        } else if (prev->leftChild == curr) {
            prev->leftChild = tmp;
        } else {
            prev->rightChild = tmp;
        }
    } else {  // 有兩個子節點
        // 找左子樹的最大值
        TreeNode *maxLeftPrev = curr, *maxLeft = curr->leftChild;

        while (maxLeft->rightChild != nullptr) {
            maxLeftPrev = maxLeft;
            maxLeft = maxLeft->rightChild;
        }

        curr->value = maxLeft->value;  // 取代curr的值

        if (maxLeftPrev->leftChild ==
            maxLeft) {  // 只有沒有在左子樹找到最大值才符合這個條件
            maxLeftPrev->leftChild = maxLeft->leftChild;
        } else {
            maxLeftPrev->rightChild = maxLeft->leftChild;
        }

        delete maxLeft;
    }
}

TreeNode* BST::SearchNode(int value) {
    // TODO: Implement search function to find and return the node with the
    // given value.

    TreeNode* curr = root;

    while (curr != nullptr) {
        if (curr->value == value) {
            return curr;
        } else if (curr->value > value) {
            curr = curr->leftChild;
        } else {
            curr = curr->rightChild;
        }
    }

    return nullptr;
}

void BST::PreOrder(TreeNode* node) {
    // TODO: Implement preorder traversal and store result to preOrderAnswer.

    preOrderAnswer.push_back(node->value);

    if (node->leftChild != nullptr) {
        PreOrder(node->leftChild);
    }
    if (node->rightChild != nullptr) {
        PreOrder(node->rightChild);
    }
}

void BST::InOrder(TreeNode* node) {
    // TODO: Implement inorder traversal and store result to inOrderAnswer.

    if (node->leftChild != nullptr) {
        InOrder(node->leftChild);
    }

    inOrderAnswer.push_back(node->value);

    if (node->rightChild != nullptr) {
        InOrder(node->rightChild);
    }
}

void BST::PostOrder(TreeNode* node) {
    // TODO: Implement postorder traversal and store result to postOrderAnswer.

    if (node->leftChild != nullptr) {
        PostOrder(node->leftChild);
    }
    if (node->rightChild != nullptr) {
        PostOrder(node->rightChild);
    }

    postOrderAnswer.push_back(node->value);
}

// Do not modify those function.
void BST::destroyTree(TreeNode* node) {
    if (!node) return;
    destroyTree(node->leftChild);
    destroyTree(node->rightChild);
    delete node;
}

// Do not modify those function.
void BST::clear() {
    preOrderAnswer.clear();
    inOrderAnswer.clear();
    postOrderAnswer.clear();
    destroyTree(root);
    root = nullptr;
}

// Do not modify those function.
void BST::Output(ofstream& out) {
    // Execute.
    PreOrder(root);
    InOrder(root);
    PostOrder(root);

    // Output the reuslt of traversals.
    out << "PreOrder traversal:";
    for (unsigned int i = 0; i < preOrderAnswer.size(); i++) {
        out << preOrderAnswer[i];
        if (i < preOrderAnswer.size() - 1)
            out << ",";
        else
            out << "\n";
    }

    out << "InOrder traversal:";
    for (unsigned int i = 0; i < inOrderAnswer.size(); i++) {
        out << inOrderAnswer[i];
        if (i < inOrderAnswer.size() - 1)
            out << ",";
        else
            out << "\n";
    }

    out << "PostOrder traversal:";
    for (unsigned int i = 0; i < postOrderAnswer.size(); i++) {
        out << postOrderAnswer[i];
        if (i < postOrderAnswer.size() - 1)
            out << ",";
        else
            out << "\n";
    }
}