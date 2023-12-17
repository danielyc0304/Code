#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

class BinaryTree;
class TreeNode {
  private:
    char data;
    TreeNode *parent;
    TreeNode *left_child, *right_child;

  public:
    TreeNode() {
        this->data = 'x';
        this->parent = nullptr;
        this->left_child = nullptr, this->right_child = nullptr;
    }
    TreeNode(char data) {
        this->data = data;
        this->parent = nullptr;
        this->left_child = nullptr, this->right_child = nullptr;
    }

    friend class BinaryTree;
};
class BinaryTree {
  private:
    TreeNode *LeftMost(TreeNode *current) {  // 從current往下找到最左邊的節點
        while (current->left_child != nullptr) {
            current = current->left_child;
        }

        return current;
    }
    TreeNode *InOrderSuccessor(TreeNode *current) {  // 找到中序遍歷的下一個節點
        if (current->right_child != nullptr) {
            return LeftMost(
                current
                    ->right_child);  // 把右子樹當作根節點往下找出最左邊的節點
        }

        TreeNode *successor = current->parent;
        while (
            successor != nullptr &&
            current ==
                successor
                    ->right_child) {  // 如果current是successor的右子樹，就代表這條分支已經走完了
            current = successor;
            successor = successor->parent;
        }
        return successor;
    }

    TreeNode *RightMost(TreeNode *current) {
        while (current->right_child != nullptr) {
            current = current->right_child;
        }

        return current;
    }
    TreeNode *InOrderPredecessor(TreeNode *current) {
        if (current->left_child != nullptr) {
            return RightMost(current->left_child);
        }

        TreeNode *predecessor = current->parent;
        while (predecessor != nullptr && current == predecessor->left_child) {
            current = predecessor;
            predecessor = predecessor->parent;
        }
        return predecessor;
    }

  public:
    TreeNode *root;

    BinaryTree(string data) {
        stringstream ss(data);

        root = new TreeNode;
        ss >> root->data;

        LevelOrderConstruct(ss);
    }
    void LevelOrderConstruct(stringstream &ss) {
        char data = 'x';
        TreeNode *current = root;
        queue<TreeNode *> node;

        while (ss >> data) {
            if (data != 'x') {
                TreeNode *new_node = new TreeNode(data);

                new_node->parent = current, current->left_child = new_node;

                node.push(new_node);
            }

            if (!(ss >> data)) {
                break;
            }

            if (data != 'x') {
                TreeNode *new_node = new TreeNode(data);

                new_node->parent = current, current->right_child = new_node;

                node.push(new_node);
            }

            current = node.front(), node.pop();
        }
    }

    void PreOrder(TreeNode *current) {
        if (current != nullptr) {
            printf("%c ", current->data);

            PreOrder(current->left_child);
            PreOrder(current->right_child);
        }
    }
    void InOrder(TreeNode *current) {
        if (current != nullptr) {
            InOrder(current->left_child);

            printf("%c ", current->data);

            InOrder(current->right_child);
        }
    }
    void PostOrder(TreeNode *current) {
        if (current != nullptr) {
            PostOrder(current->left_child);
            PostOrder(current->right_child);

            printf("%c ", current->data);
        }
    }
    void LevelOrder() {
        queue<TreeNode *> node;

        node.push(root);
        while (node.empty() == false) {
            TreeNode *current = node.front();
            node.pop();

            printf("%c ", current->data);

            if (current->left_child != nullptr) {
                node.push(current->left_child);
            }
            if (current->right_child != nullptr) {
                node.push(current->right_child);
            }
        }
    }

    void InOrderByParent(TreeNode *root) {
        TreeNode *current = new TreeNode;

        current = LeftMost(root);
        while (current != nullptr) {
            printf("%c ", current->data);

            current = InOrderSuccessor(current);
        }
    }
    void InOrderReverseByParent(TreeNode *root) {
        TreeNode *current = new TreeNode;

        current = RightMost(root);
        while (current != nullptr) {
            printf("%c ", current->data);

            current = InOrderPredecessor(current);
        }
    }

    void InsertLevelOrder(char data) {
        TreeNode *current = root;
        queue<TreeNode *> node;

        while (current != nullptr) {
            if (current->left_child != nullptr) {
                node.push(current->left_child);
            } else {
                TreeNode *new_node = new TreeNode(data);

                new_node->parent = current, current->left_child = new_node;

                break;
            }

            if (current->right_child != nullptr) {
                node.push(current->right_child);
            } else {
                TreeNode *new_node = new TreeNode(data);

                new_node->parent = current, current->right_child = new_node;

                break;
            }

            current = node.front(), node.pop();
        }
    }
};

int main() {
    string data = "A B C D E F x x x G H x I";
    BinaryTree tree(data);

    printf("Pre-Order Traversal:   "), tree.PreOrder(tree.root), printf("\n");
    printf("In-Order Traversal:    "), tree.InOrder(tree.root), printf("\n");
    printf("Post-Order Traversal:  "), tree.PostOrder(tree.root), printf("\n");
    printf("Level-Order Traversal: "), tree.LevelOrder(), printf("\n");
    printf("\n");

    printf("In-Order Traversal by Parent:         "),
        tree.InOrderByParent(tree.root), printf("\n");
    printf("In-Order Reverse Traversal by Parent: "),
        tree.InOrderReverseByParent(tree.root), printf("\n");
    printf("\n");

    tree.InsertLevelOrder('K');
    tree.InsertLevelOrder('L');
    tree.InsertLevelOrder('M');
    tree.InsertLevelOrder('N');

    printf("--- After Insert Level Order ---\n");
    printf("\n");

    printf("Pre-Order Traversal:   "), tree.PreOrder(tree.root), printf("\n");
    printf("In-Order Traversal:    "), tree.InOrder(tree.root), printf("\n");
    printf("Post-Order Traversal:  "), tree.PostOrder(tree.root), printf("\n");
    printf("Level-Order Traversal: "), tree.LevelOrder(), printf("\n");
    printf("\n");

    printf("In-Order Traversal by Parent:         "),
        tree.InOrderByParent(tree.root), printf("\n");
    printf("In-Order Reverse Traversal by Parent: "),
        tree.InOrderReverseByParent(tree.root), printf("\n");

    return 0;
}
