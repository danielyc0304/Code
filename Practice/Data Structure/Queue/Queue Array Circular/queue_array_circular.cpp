#include <iostream>
using namespace std;

class QueueArrayCircular {
  private:
    int *queue;
    int front, back;
    int capacity;

    void DoubleCapacity();

  public:
    QueueArrayCircular() {
        this->queue = new int[capacity];
        this->front = 0, this->back = 0;
        this->capacity = 2;  // 因為index=0的位置捨棄不用，所以初始值要設為2
    }

    bool IsEmpty() { return (front == back); }

    void GetFront() {
        if (IsEmpty() == true) {
            printf("Queue is empty.\n");
        } else {
            printf("%d\n", queue[(front + 1) % capacity]);
        }
    }

    void GetBack() {
        if (IsEmpty() == true) {
            printf("Queue is empty.\n");
        } else {
            printf("%d\n", queue[back]);
        }
    }

    int GetSize() {
        if (front <= back) {
            return back - front;
        } else {
            return capacity - (front - back);
        }
    }

    void Push(int num) {
        if (GetSize() == capacity - 1) {
            DoubleCapacity();
        }
        back = (back + 1) % capacity;
        queue[back] = num;
    }

    void Pop() {
        if (IsEmpty() == true) {
            printf("Queue is empty.\n");
        } else {
            front = (front + 1) % capacity;
        }
    }
};
void QueueArrayCircular::DoubleCapacity() {
    int *new_queue = new int[capacity * 2];

    int j = front, size = GetSize();
    for (int i = 1; i <= size; i++) {
        new_queue[i] = queue[++j % capacity];
    }
    front = 0, back = size;
    capacity *= 2;
    delete[] queue;
    queue = new_queue;
}

int main() {
    QueueArrayCircular queue;
    string action;

    while (printf("Enter action: ") && getline(cin, action)) {
        if (action == "is empty") {
            printf("%s\n", (queue.IsEmpty() == true) ? "true" : "false");
        } else if (action == "get front") {
            queue.GetFront();
        } else if (action == "get back") {
            queue.GetBack();
        } else if (action == "get size") {
            printf("%d\n", queue.GetSize());
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
