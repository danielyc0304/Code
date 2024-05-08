#include <iostream>
#include <stack>
using namespace std;

class MinStack {
  private:
    stack<int> num, min;

  public:
    bool IsEmpty() { return num.empty(); }

    void Top() {
        if (IsEmpty() == true) {
            printf("Stack is empty.\n");
        } else {
            printf("%d\n", num.top());
        }
    }

    void GetMin() {
        if (IsEmpty() == true) {
            printf("Stack is empty.\n");
        } else {
            printf("%d\n", min.top());
        }
    }

    void GetSize() { printf("%lu\n", num.size()); }

    void Push(int num) {
        if (IsEmpty() == true || num < min.top()) {
            min.push(num);
        } else {
            min.push(min.top());
        }
        this->num.push(num);
    }

    void Pop() {
        if (IsEmpty() == true) {
            printf("Stack is empty.\n");
        } else {
            num.pop(), min.pop();
        }
    }
};

int main() {
    MinStack stack;
    string action;

    while (printf("Enter action: ") && getline(cin, action)) {
        if (action == "is empty") {
            printf("%s\n", (stack.IsEmpty() == true) ? "true" : "false");
        } else if (action == "top") {
            stack.Top();
        } else if (action == "get min") {
            stack.GetMin();
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
