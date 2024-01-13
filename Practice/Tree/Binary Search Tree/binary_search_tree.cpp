#include <iostream>
#include <queue>
using namespace std;

class BinarySearchTree;
class TreeNode {
  private:
    int key;
    string value;

    TreeNode *parent;
    TreeNode *left_child, *right_child;

  public:
    TreeNode() {
        this->key = 0, this->value = "";
        this->parent = nullptr;
        this->left_child = nullptr, this->right_child = nullptr;
    }
    TreeNode(int key, string value) {
        this->key = key, this->value = value;
        this->parent = nullptr;
        this->left_child = nullptr, this->right_child = nullptr;
    }

    int GetKey() { return key; }
    string GetValue() { return value; }

    friend class BinarySearchTree;
};
class BinarySearchTree {
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

  public:
    TreeNode *root;

    BinarySearchTree() { root = nullptr; }

    void InOrder(TreeNode *current) {
        if (current != nullptr) {
            InOrder(current->left_child);

            printf("%s(%d) ", current->GetValue().c_str(), current->GetKey());

            InOrder(current->right_child);
        }
    }

    void LevelOrder() {
        queue<TreeNode *> node;

        node.push(root);
        while (node.empty() == false) {
            TreeNode *current = node.front();

            printf("%s(%d) ", current->GetValue().c_str(), current->GetKey());

            if (current->left_child != nullptr) {
                node.push(current->left_child);
            }
            if (current->right_child != nullptr) {
                node.push(current->right_child);
            }

            node.pop();
        }
    }

    TreeNode *Search(int key) {
        TreeNode *current = root;

        while (current != nullptr && key != current->key) {
            if (key < current->key) {
                current = current->left_child;
            } else {
                current = current->right_child;
            }
        }

        return current;
    }

    void Insert(int key, string value) {
        TreeNode *x = root, *y = nullptr;  // y是x的父節點
        TreeNode *new_node = new TreeNode(key, value);

        while (x != nullptr) {
            y = x;

            if (new_node->key < x->key) {
                x = x->left_child;
            } else {
                x = x->right_child;
            }
        }

        new_node->parent = y;
        if (y == nullptr) {
            root = new_node;
        } else if (new_node->key < y->key) {
            y->left_child = new_node;
        } else {
            y->right_child = new_node;
        }
    }

    void Delete(int key) {
        TreeNode *delete_node = Search(key);
        if (delete_node == nullptr) {
            printf("Data not found.\n");

            return;
        }

        TreeNode *
            x = nullptr,
           *y =
               nullptr;  // x是記憶體真正要被釋放的節點的子節點，y是記憶體真正要被釋放的節點

        if (delete_node->left_child == nullptr ||
            delete_node->right_child == nullptr) {
            y = delete_node;
        } else {  // 如果要刪除的節點下面有兩個子節點，就找到比要刪除的節點大的第一個節點
            y = InOrderSuccessor(delete_node);
        }
        // 經過上面的處理，y節點下最多只會有一個右子節點

        if (y->right_child != nullptr) {
            x = y->right_child;
        }

        if (x != nullptr) {  // 如果y下面有子節點
            x->parent = y->parent;
        }

        if (y->parent == nullptr) {  // y節點是根節點的的情況
            root = x;
        } else if (y == y->parent->left_child) {
            y->parent->left_child = x;
        } else {
            y->parent->right_child = x;
        }

        if (y !=
            delete_node) {  // 針對要刪除的節點有兩個子節點的情況，實際上是把y的資料複製到要刪除的節點上，且刪除y節點
            delete_node->key = y->key, delete_node->value = y->value;
        }
        // 最後變成是y的記憶體位置被刪除，x帶著原資料取代y的位置，y把原資料複製到delete_node的位置，所以delete_node的資料就消失了

        delete y;
    }
};

int main() {
    BinarySearchTree tree;

    tree.Insert(8, "龜仙人");
    tree.Insert(1000, "悟空");
    tree.Insert(2, "克林");
    tree.Insert(513, "比克");

    printf("In-Order Traversal:    "), tree.InOrder(tree.root), printf("\n");
    printf("Level-Order Traversal: "), tree.LevelOrder(), printf("\n");
    printf("\n");

    TreeNode *node = tree.Search(1000);
    if (node != nullptr) {
        printf("There is %s(%d).\n", node->GetValue().c_str(), node->GetKey());
    } else {
        printf("There is no value with key(1000).\n");
    }
    node = tree.Search(73);
    if (node != nullptr) {
        printf("There is %s(%d).\n", node->GetValue().c_str(), node->GetKey());
    } else {
        printf("There is no value with key(73).\n");
    }
    printf("\n");

    tree.Delete(8);

    printf("--- After delete 8 ---\n");
    printf("\n");

    printf("In-Order Traversal:    "), tree.InOrder(tree.root), printf("\n");
    printf("Level-Order Traversal: "), tree.LevelOrder(), printf("\n");
    printf("\n");

    node = tree.Search(8);
    if (node != nullptr) {
        printf("There is %s(%d).\n", node->GetValue().c_str(), node->GetKey());
    } else {
        printf("There is no value with key(8).\n");
    }

    return 0;
}
