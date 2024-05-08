#include <iostream>
using namespace std;

class RedBlackTree;
class TreeNode {
  private:
    int key;
    string value;
    int color;  // 0->紅, 1->黑

    TreeNode *parent;
    TreeNode *left_child, *right_child;

  public:
    TreeNode(int key, string value) {
        this->key = key, this->value = value;
        this->color = 0;
        this->parent = nullptr;
        this->left_child = nullptr, this->right_child = nullptr;
    }

    int GetKey() { return key; }
    string GetValue() { return value; }

    friend class RedBlackTree;
};
class RedBlackTree {
  private:
    TreeNode *LeftMost(TreeNode *current) {  // 從current往下找到最左邊的節點
        while (current->left_child != neel) {
            current = current->left_child;
        }

        return current;
    }
    TreeNode *InOrderSuccessor(TreeNode *current) {  // 找到中序遍歷的下一個節點
        if (current->right_child != neel) {
            return LeftMost(
                current
                    ->right_child);  // 把右子樹當作根節點往下找出最左邊的節點
        }

        TreeNode *successor = current->parent;
        while (
            successor != neel &&
            current ==
                successor
                    ->right_child) {  // 如果current是successor的右子樹，就代表這條分支已經走完了
            current = successor;
            successor = successor->parent;
        }
        return successor;
    }

    void LeftRotation(TreeNode *x) {
        TreeNode *y = x->right_child;

        // y的左子樹 -> x的右子樹
        x->right_child = y->left_child;
        if (y->left_child != neel) {
            y->left_child->parent = x;
        }

        // y -> x
        y->parent = x->parent;

        // 更改x的父節點的資料
        if (x->parent == neel) {
            root = y;
        } else if (x == x->parent->left_child) {
            x->parent->left_child = y;
        } else {
            x->parent->right_child = y;
        }

        // 更改x與y的資料
        y->left_child = x;
        x->parent = y;
    }
    void RightRotation(TreeNode *y) {
        TreeNode *x = y->left_child;

        // x的右子樹 -> y的左子樹
        y->left_child = x->right_child;
        if (x->right_child != neel) {
            x->right_child->parent = y;
        }

        // x -> y
        x->parent = y->parent;

        // 更改y的父節點的資料
        if (y->parent == neel) {
            root = x;
        } else if (y == y->parent->left_child) {
            y->parent->left_child = x;
        } else {
            y->parent->right_child = x;
        }

        // 更改x與y的資料
        x->right_child = y;
        y->parent = x;
    }

  public:
    TreeNode *root;
    TreeNode *neel;

    RedBlackTree() {
        this->neel = new TreeNode(0, "");
        this->neel->color = 1;
        this->neel->parent = neel;
        this->neel->left_child = neel, this->neel->right_child = neel;

        this->root = neel;
    }

    void InOrder(TreeNode *current) {
        if (current != neel) {
            InOrder(current->left_child);

            printf("%s(%d) ", current->GetValue().c_str(), current->GetKey());

            InOrder(current->right_child);
        }
    }

    TreeNode *Search(int key) {
        TreeNode *current = root;

        while (current != neel && key != current->key) {
            if (key < current->key) {
                current = current->left_child;
            } else {
                current = current->right_child;
            }
        }

        return current;
    }

    void Insert(int key, string value) {
        TreeNode *x = root, *y = neel;  // y是x的父節點
        TreeNode *new_node = new TreeNode(key, value);

        new_node->parent = neel;
        new_node->left_child = neel, new_node->right_child = neel;

        while (x != neel) {
            y = x;

            if (new_node->key < x->key) {
                x = x->left_child;
            } else {
                x = x->right_child;
            }
        }

        new_node->parent = y;
        if (y == neel) {
            root = new_node;
        } else if (new_node->key < y->key) {
            y->left_child = new_node;
        } else {
            y->right_child = new_node;
        }

        InsertFixedUp(new_node);
    }
    void InsertFixedUp(TreeNode *current) {
        while (current->parent->color == 0) {  // 父節點是紅色
            if (current->parent ==
                current->parent->parent->left_child) {  // 父節點在左子樹
                TreeNode *uncle = current->parent->parent->right_child;

                if (uncle->color == 0) {  // Case1: uncle是紅色
                    current->parent->color = 1;
                    uncle->color = 1;
                    current->parent->parent->color = 0;

                    current = current->parent->parent;
                } else {  // uncle是黑色
                    if (current ==
                        current->parent
                            ->right_child) {  // Case2: current在右子樹
                        current = current->parent;

                        LeftRotation(current);
                    }

                    // Case3: current在左子樹
                    current->parent->color = 1;
                    current->parent->parent->color = 0;

                    RightRotation(current->parent->parent);
                }
            } else {  // 父節點在右子樹
                TreeNode *uncle = current->parent->parent->left_child;

                if (uncle->color == 0) {  // Case1: uncle是紅色
                    current->parent->color = 1;
                    uncle->color = 1;
                    current->parent->parent->color = 0;

                    current = current->parent->parent;
                } else {  // uncle是黑色
                    if (current ==
                        current->parent
                            ->left_child) {  // Case2: current在左子樹
                        current = current->parent;

                        RightRotation(current);
                    }

                    // Case3: current在右子樹
                    current->parent->color = 1;
                    current->parent->parent->color = 0;

                    LeftRotation(current->parent->parent);
                }
            }
        }

        root->color = 1;
    }

    void Delete(int key) {
        TreeNode *delete_node = Search(key);
        if (delete_node == neel) {
            printf("Data not found.\n");

            return;
        }

        TreeNode *
            x = neel,
           *y =
               neel;  // x是記憶體真正要被釋放的節點的子節點，y是記憶體真正要被釋放的節點

        if (delete_node->left_child == neel ||
            delete_node->right_child == neel) {
            y = delete_node;
        } else {  // 如果要刪除的節點下面有兩個子節點，就找到比要刪除的節點大的第一個節點
            y = InOrderSuccessor(delete_node);
        }
        // 經過上面的處理，y節點下最多只會有一個右子節點

        x = y->right_child;
        x->parent =
            y->parent;  // 就算x是neel也要將父節點指向有效的記憶體位置，因為DeleteFixedUp時會用到

        if (y->parent == neel) {  // y節點是根節點的的情況
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

        if (y->color == 1) {  // 如果刪除的節點是黑色
            DeleteFixedUp(x);
        }
    }
    void DeleteFixedUp(TreeNode *current) {
        while (current != root && current->color == 1) {
            if (current == current->parent->left_child) {  // 在父節點的左子樹
                TreeNode *sibling = current->parent->right_child;

                if (sibling->color == 0) {  // Case1: sibling是紅色
                    sibling->color = 1;
                    current->parent->color = 0;

                    LeftRotation(current->parent);

                    sibling = current->parent->right_child;
                }
                // sibling是黑色
                if (sibling->left_child->color == 1 &&
                    sibling->right_child->color ==
                        1) {  // Case2: 兩個子節點都是黑色
                    sibling->color = 0;

                    current = current->parent;
                } else {
                    if (sibling->right_child->color ==
                        1) {  // Case3: 右子節點是黑色
                        sibling->left_child->color = 1;
                        sibling->color = 0;

                        RightRotation(sibling);

                        sibling = current->parent->right_child;
                    }
                    // Case4: 右子節點是紅色，經過Case3調整一定會變成這樣
                    sibling->right_child->color = 1;
                    sibling->color = current->parent->color;
                    current->parent->color = 1;

                    LeftRotation(current->parent);

                    current = root;  // 跳出迴圈
                }
            } else {  // 在父節點的右子樹
                TreeNode *sibling = current->parent->left_child;

                if (sibling->color == 0) {  // Case1: sibling是紅色
                    sibling->color = 1;
                    current->parent->color = 0;

                    RightRotation(current->parent);

                    sibling = current->parent->left_child;
                }
                // sibling是黑色
                if (sibling->left_child->color == 1 &&
                    sibling->right_child->color ==
                        1) {  // Case2: 兩個子節點都是黑色
                    sibling->color = 0;

                    current = current->parent;
                } else {
                    if (sibling->left_child->color ==
                        1) {  // Case3: 左子節點是黑色
                        sibling->right_child->color = 1;
                        sibling->color = 0;

                        LeftRotation(sibling);

                        sibling = current->parent->left_child;
                    }
                    // Case4: 左子節點是紅色，經過Case3調整一定會變成這樣
                    sibling->left_child->color = 1;
                    sibling->color = current->parent->color;
                    current->parent->color = 1;

                    RightRotation(current->parent);

                    current = root;  // 跳出迴圈
                }
            }
        }

        current->color = 1;  // 根節點一定是黑色
    }
};

int main() {
    RedBlackTree tree;

    tree.Insert(8, "龜仙人");
    tree.Insert(1000, "悟空");
    tree.Insert(2, "克林");
    tree.Insert(513, "比克");

    printf("In-Order Traversal: "), tree.InOrder(tree.root), printf("\n");
    printf("\n");

    TreeNode *node = tree.Search(1000);
    if (node != tree.neel) {
        printf("There is %s(%d).\n", node->GetValue().c_str(), node->GetKey());
    } else {
        printf("There is no value with key(1000).\n");
    }
    node = tree.Search(73);
    if (node != tree.neel) {
        printf("There is %s(%d).\n", node->GetValue().c_str(), node->GetKey());
    } else {
        printf("There is no value with key(73).\n");
    }
    printf("\n");

    tree.Delete(8);

    printf("--- After delete 8 ---\n");
    printf("\n");

    printf("In-Order Traversal: "), tree.InOrder(tree.root), printf("\n");
    printf("\n");

    node = tree.Search(8);
    if (node != tree.neel) {
        printf("There is %s(%d).\n", node->GetValue().c_str(), node->GetKey());
    } else {
        printf("There is no value with key(8).\n");
    }

    return 0;
}
