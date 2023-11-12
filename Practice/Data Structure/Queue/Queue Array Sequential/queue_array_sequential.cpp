#include <iostream>
using namespace std;

class QueueArraySequential {
  private:
    int *queue;
    int front, back;
    int capacity;

    void DoubleCapacity() {
        capacity *= 2;
        int *new_queue = new int[capacity];

        int j = -1;
        for (int i = front + 1; i <= back; i++) {
            new_queue[++j] = queue[i];
        }
        front = -1;
        back = j;
        delete[] queue;
        queue = new_queue;
    }

  public:
    QueueArraySequential() {
        this->queue = new int[capacity];
        this->front = -1;
        this->back = -1;
        this->capacity = 1;
    }

    bool IsEmpty() { return (front == back); }

    void GetFront() {
        if (IsEmpty() == true) {
            printf("Queue is empty.\n");
        } else {
            printf("%d\n", queue[front + 1]);
        }
    }

    void GetBack() {
        if (IsEmpty() == true) {
            printf("Queue is empty.\n");
        } else {
            printf("%d\n", queue[back]);
        }
    }

    void GetSize() { printf("%d\n", back - front); }

    void Push(int num) {
        if (back == capacity - 1) {
            DoubleCapacity();
        }
        queue[++back] = num;
    }

    void Pop() {
        if (IsEmpty() == true) {
            printf("Queue is empty.\n");
        } else {
            front++;
        }
    }
};

int main() {
    QueueArraySequential queue;
    string action;

    while (printf("Enter action: ") && getline(cin, action)) {
        if (action == "is empty") {
            printf("%s\n", (queue.IsEmpty() == true) ? "true" : "false");
        } else if (action == "get front") {
            queue.GetFront();
        } else if (action == "get back") {
            queue.GetBack();
        } else if (action == "get size") {
            queue.GetSize();
        } else if (action == "push") {
            int num;

            printf("Enter number: "), scanf("%d", &num), cin.get();
            queue.Push(num);
        } else if (action == "pop") {
            queue.Pop();
        } else if (action == "exit") {
            break;
        } else {
            printf("Invalid action.\n");
        }
    }

    return 0;
}