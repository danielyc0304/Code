#include <iostream>
using namespace std;

class LinkedList;
class ListNode {
  private:
    int num;
    ListNode *next;

  public:
    ListNode(int num) {
        this->num = num;
        this->next = nullptr;
    }

    friend class LinkedList;
};
class LinkedList {
  private:
    ListNode *front, *back;
    int size;

  public:
    LinkedList() {
        this->front = nullptr;
        this->back = nullptr;
        this->size = 0;
    }

    bool IsEmpty() { return (size == 0); }

    void PrintList() {
        if (IsEmpty() == true) {
            printf("List is empty.\n");
        } else {
            for (ListNode *current = front; current != nullptr;
                 current = current->next) {
                printf("%d ", current->num);
            }
            printf("\n");
        }
    }

    void GetSize() { printf("%d\n", size); }

    void PushFront(int num) {
        ListNode *new_node = new ListNode(num);

        new_node->next = front;
        front = new_node;
        if (size == 0) {
            back = new_node;
        }
        size += 1;
    }

    void PushBack(int num) {
        ListNode *new_node = new ListNode(num);

        if (size == 0) {
            front = new_node;
        } else {
            back->next = new_node;
        }
        back = new_node;
        size += 1;
    }

    void Delete(int num) {
        ListNode *previous = nullptr, *current = front;

        while (current != nullptr && current->num != num) {
            previous = current;
            current = current->next;
        }
        if (current == nullptr) {
            printf("There is no %d in the list.\n", num);

            return;
        } else if (current == front) {
            front = front->next;
        } else {
            previous->next = current->next;
        }
        delete current;
        size -= 1;
    }

    void Clear() {
        ListNode *current;

        while (front != nullptr) {
            current = front;
            front = front->next;
            delete current;
        }
        back = nullptr;
        size = 0;
    }

    void Reverse() {
        if (size == 0) {
            printf("List is empty.\n");
        } else if (size == 1) {
            printf("List only has one element.\n");
        } else {
            ListNode *previous = nullptr, *current = front,
                     *preceding = front->next;

            while (preceding != nullptr) {
                current->next = previous;
                previous = current;
                current = preceding;
                preceding = preceding->next;
            }
            current->next = previous;
            swap(front, back);
        }
    }
};

int main() {
    LinkedList list;
    string action;

    while (printf("Enter action: ") && getline(cin, action)) {
        if (action == "is empty") {
            printf("%s\n", (list.IsEmpty() == true) ? "true" : "false");
        } else if (action == "print list") {
            list.PrintList();
        } else if (action == "get size") {
            list.GetSize();
        } else if (action == "push front") {
            int num;

            printf("Enter number: "), scanf("%d", &num), cin.get();
            list.PushFront(num);
        } else if (action == "push back") {
            int num;

            printf("Enter number: "), scanf("%d", &num), cin.get();
            list.PushBack(num);
        } else if (action == "delete") {
            int num;

            printf("Enter number: "), scanf("%d", &num), cin.get();
            list.Delete(num);
        } else if (action == "clear") {
            list.Clear();
        } else if (action == "reverse") {
            list.Reverse();
        } else if (action == "exit") {
            break;
        } else {
            printf("Invalid action.\n");
        }
    }

    return 0;
}
