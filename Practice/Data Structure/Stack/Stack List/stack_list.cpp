#include <iostream>
using namespace std;

class StackList;
class StackNode {
  private:
    int num;
    StackNode *next;

  public:
    StackNode(int num) {
        this->num = num;
        this->next = nullptr;
    }

    friend class StackList;
};
class StackList {
  private:
    StackNode *top;
    int size;

  public:
    StackList() {
        this->top = nullptr;
        this->size = 0;
    }

    bool IsEmpty() { return (size == 0); }

    void Top() {
        if (IsEmpty() == true) {
            printf("Stack is empty.\n");
        } else {
            printf("%d\n", top->num);
        }
    }

    void GetSize() { printf("%d\n", size); }

    void Push(int num) {
        StackNode *new_node = new StackNode(num);

        if (IsEmpty() == false) {
            new_node->next = top;
        }
        top = new_node;
        size++;
    }

    void Pop() {
        if (IsEmpty() == true) {
            printf("Stack is empty.\n");
        } else {
            StackNode *current = top;

            top = top->next;
            delete current;
            size--;
        }
    }
};

int main() {
    StackList stack;
    string action;

    while (printf("Enter action: ") && getline(cin, action)) {
        if (action == "is empty") {
            printf("%s\n", (stack.IsEmpty() == true) ? "true" : "false");
        } else if (action == "top") {
            stack.Top();
        } else if (action == "get size") {
            stack.GetSize();
        } else if (action == "push") {
            int num;

            printf("Enter number: "), scanf("%d", &num), cin.get();
            stack.Push(num);
        } else if (action == "pop") {
            stack.Pop();
        } else if (action == "exit") {
            break;
        } else {
            printf("Invalid action.\n");
        }
    }

    return 0;
}