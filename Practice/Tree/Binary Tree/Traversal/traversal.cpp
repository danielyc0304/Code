#include <iostream>
#include <queue>
using namespace std;

class BinaryTree;
class TreeNode {
  private:
    char data;

  public:
    TreeNode *parent;
    TreeNode *left_child, *right_child;

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

    BinaryTree(TreeNode *root) { this->root = root; }

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
};

int main() {
    TreeNode *node_a = new TreeNode('A'), *node_b = new TreeNode('B'),
             *node_c = new TreeNode('C'), *node_d = new TreeNode('D'),
             *node_e = new TreeNode('E'), *node_f = new TreeNode('F'),
             *node_g = new TreeNode('G'), *node_h = new TreeNode('H'),
             *node_i = new TreeNode('I');

    node_a->left_child = node_b, node_b->parent = node_a;
    node_a->right_child = node_c, node_c->parent = node_a;

    node_b->left_child = node_d, node_d->parent = node_b;
    node_b->right_child = node_e, node_e->parent = node_b;

    node_c->left_child = node_f, node_f->parent = node_c;
    node_c->right_child = node_g, node_g->parent = node_c;

    node_d->left_child = node_h, node_h->parent = node_d;
    node_d->right_child = node_i, node_i->parent = node_d;

    BinaryTree tree(node_a);

    printf("Pre-Order Traversal: "), tree.PreOrder(tree.root), printf("\n");
    printf("In-Order Traversal: "), tree.InOrder(tree.root), printf("\n");
    printf("Post-Order Traversal: "), tree.PostOrder(tree.root), printf("\n");
    printf("Level-Order Traversal: "), tree.LevelOrder(), printf("\n");

    printf("In-Order Traversal by Parent: "), tree.InOrderByParent(tree.root),
        printf("\n");
    printf("In-Order Reverse Traversal by Parent: "),
        tree.InOrderReverseByParent(tree.root), printf("\n");

    return 0;
}
