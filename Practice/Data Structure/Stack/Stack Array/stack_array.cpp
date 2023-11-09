#include <iostream>
using namespace std;

class StackArray {
  private:
    int top;
    int capacity;
    int *stack;

    void DoubleCapacity() {
        capacity *= 2;
        int *new_stack = new int[capacity];

        for (int i = 0; i < capacity / 2; i++) {
            new_stack[i] = stack[i];
        }
        delete[] stack;
        stack = new_stack;
    }

  public:
    StackArray() {
        this->top = -1;
        this->capacity = 1;
        this->stack = new int[capacity];
    }

    bool IsEmpty() { return (top == -1); }

    void Top() {
        if (IsEmpty() == true) {
            printf("Stack is empty.\n");
        } else {
            printf("%d\n", stack[top]);
        }
    }

    void GetSize() { printf("%d\n", top + 1); }

    void Push(int num) {
        if (top == capacity - 1) {
            DoubleCapacity();
        }
        stack[++top] = num;
    }

    void pop() {
        if (IsEmpty() == true) {
            printf("Stack is empty.\n");
        } else {
            top--;
        }
    }
};

int main() {
    StackArray stack;
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
            stack.pop();
        } else if (action == "exit") {
            break;
        } else {
            printf("Invalid action.\n");
        }
    }

    return 0;
}
