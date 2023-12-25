#include <iostream>
using namespace std;

struct Node {
    int key;
    string value;
    Node *next;

    Node(int key, string value) {
        this->key = key, this->value = value;
        this->next = nullptr;
    }
};
class HashChainNode {
  private:
    Node **table;
    int size, count;

    int HashFunction(int key) {
        double A = 0.6180339887, frac = key * A - floor(key * A);

        return floor(size * frac);
    }

    void TableDoubling() {
        int size_orig = size;

        size *= 2;
        ReHashing(size_orig);
    }
    void TableShrinking() {
        int size_orig = size;

        size /= 2;
        ReHashing(size_orig);
    }
    void ReHashing(int size_orig) {
        Node **new_table = new Node *[size];
        for (int i = 0; i < size; i++) {
            new_table[i] = nullptr;
        }

        for (int i = 0; i < size_orig; i++) {
            Node *curr_orig = table[i], *prev_orig = nullptr;

            while (curr_orig != nullptr) {
                prev_orig = curr_orig->next;

                int i = HashFunction(curr_orig->key);

                if (new_table[i] == nullptr) {
                    new_table[i] = curr_orig;
                    new_table[i]->next = nullptr;
                } else {
                    // push_front的操作
                    Node *next = new_table[i]->next;

                    new_table[i]->next = curr_orig;
                    curr_orig->next = next;
                }
                curr_orig = prev_orig;
            }
        }

        delete[] table;
        table = new_table;
    }

  public:
    HashChainNode(int size) {
        this->table = new Node *[size];
        for (int i = 0; i < size; i++) {
            table[i] = nullptr;
        }

        this->size = size, this->count = 0;
    }

    void DisplayTable() {
        for (int i = 0; i < size; i++) {
            printf("slot#%d: ", i);

            Node *current = table[i];
            while (current != nullptr) {
                printf("(%d,%s) ", current->key, current->value.c_str());

                current = current->next;
            }
            printf("\n");
        }
    }

    string Search(int key) {
        int i = HashFunction(key);
        Node *current = table[i];

        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }

            current = current->next;
        }

        return "No such data.";
    }

    void Insert(Node data) {
        count++;
        if (count > size) {
            TableDoubling();
        }

        int i = HashFunction(data.key);
        Node *new_node = new Node(data);

        if (table[i] == nullptr) {
            table[i] = new_node;
        } else {
            // push_front的操作
            Node *next = table[i]->next;

            table[i]->next = new_node;
            new_node->next = next;
        }
    }

    void Delete(int key) {
        int i = HashFunction(key);
        Node *current = table[i], *previous = nullptr;

        while (current != nullptr && current->key != key) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            printf("Data not found.\n");

            return;
        } else {
            if (previous == nullptr) {  // current在第一個
                table[i] = current->next;
            } else {
                previous->next = current->next;
            }

            delete current;
        }

        count--;
        if (count < size / 4) {
            TableShrinking();
        }
    }
};

int main() {
    HashChainNode hash(2);

    hash.Insert(Node(12, "post rock"));
    hash.Insert(Node(592, "shoegaze"));
    hash.DisplayTable(), printf("\n");

    hash.Insert(Node(6594, "blues"));
    printf("--- After insert key(6594) ---\n");
    hash.DisplayTable(), printf("\n");

    hash.Insert(Node(7, "folk"));
    printf("--- After insert key(7) ---\n");
    hash.DisplayTable(), printf("\n");

    hash.Insert(Node(123596, "hiphop"));
    printf("--- After insert key(123596) ---\n");
    hash.DisplayTable(), printf("\n");

    hash.Insert(Node(93, "soul"));
    hash.Insert(Node(2288, "indie"));
    hash.Insert(Node(793, "jazz"));
    printf("--- After insert key(93), key(2288), key(793) ---\n");
    hash.DisplayTable(), printf("\n");

    hash.Insert(Node(8491, "electro"));
    printf("--- After insert key(8491) ---\n");
    hash.DisplayTable(), printf("\n");

    hash.Insert(Node(323359, "pop"));
    printf("--- After insert key(323359) ---\n");
    hash.DisplayTable(), printf("\n");

    printf("Searching key(8491): %s\n", hash.Search(8491).c_str());
    printf("Searching key(7): %s\n", hash.Search(7).c_str()), printf("\n");

    hash.Delete(7);
    printf("--- After delete key(7) ---\n");
    hash.DisplayTable(), printf("\n");

    printf("Searching key(7): %s\n", hash.Search(7).c_str()), printf("\n");

    hash.Delete(592);
    printf("--- After delete key(592) ---\n");
    hash.DisplayTable(), printf("\n");

    printf("--- Delete key(592) again ---\n");
    hash.Delete(592), printf("\n");

    hash.Delete(123596);
    hash.Delete(323359);
    hash.Delete(793);
    hash.Delete(93);
    printf(
        "--- After delete key(123596), key(323359), key(793), key(93) ---\n");
    hash.DisplayTable(), printf("\n");

    hash.Delete(6594);
    printf("--- After delete key(6594) ---\n");
    hash.DisplayTable(), printf("\n");

    return 0;
}
