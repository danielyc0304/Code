#include <iostream>
using namespace std;

class QueueList;
class QueueNode {
  private:
    int num;
    QueueNode *next;

  public:
    QueueNode(int num) {
        this->num = num;
        this->next = nullptr;
    }

    friend class QueueList;
};
class QueueList {
  private:
    QueueNode *front;
    QueueNode *back;
    int size;

  public:
    QueueList() {
        this->front = nullptr;
        this->back = nullptr;
        this->size = 0;
    }

    bool IsEmpty() { return (size == 0); }

    void GetFront() {
        if (IsEmpty() == true) {
            printf("Queue is empty.\n");
        } else {
            printf("%d\n", front->num);
        }
    }

    void GetBack() {
        if (IsEmpty() == true) {
            printf("Queue is empty.\n");
        } else {
            printf("%d\n", back->num);
        }
    }

    void GetSize() { printf("%d\n", size); }

    void Push(int num) {
        QueueNode *new_node = new QueueNode(num);

        if (IsEmpty() == true) {
            front = new_node;
        } else {
            back->next = new_node;
        }
        back = new_node;
        size++;
    }

    void Pop() {
        if (IsEmpty() == true) {
            printf("Queue is empty.\n");
        } else {
            QueueNode *current = front;

            front = front->next;
            delete current;
            size--;
        }
    }
};

int main() {
    QueueList queue;
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
