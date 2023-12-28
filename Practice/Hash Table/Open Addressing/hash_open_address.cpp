#include <iostream>
using namespace std;

struct Dict {
    int key;
    string value;

    Dict() { this->key = 0, this->value = ""; }
    Dict(int key, string value) { this->key = key, this->value = value; }
};
class HashOpenAddress {
  private:
    Dict *table;
    int size, count;

    int QuadraticProbing(int key, int i) {
        return (int)(key % size + 0.5 * i + 0.5 * i * i) % size;
    }

  public:
    HashOpenAddress(int size) {
        this->table = new Dict[size];
        this->size = size, this->count = 0;
    }

    void DisplayTable() {
        for (int i = 0; i < size; i++) {
            printf("slot#%d: (%d,%s)\n", i, table[i].key,
                   table[i].value.c_str());
        }
        printf("\n");
    }

    string Search(int key) {
        int i = 0;

        while (i != size) {
            int j = QuadraticProbing(key, i);

            if (table[j].key == key) {
                return table[j].value;
            } else {
                i++;
            }
        }

        return "No such data.";
    }

    void Insert(int key, string value) {
        int i = 0;

        while (i != size) {
            int j = QuadraticProbing(key, i);

            if (table[j].value == "") {
                table[j].key = key;
                table[j].value = value;
                count++;

                return;
            } else {
                i++;
            }
        }

        printf("Hash table overflow.\n");
    }

    void Delete(int key) {
        int i = 0;

        while (i != size) {
            int j = QuadraticProbing(key, i);

            if (table[j].key == key) {
                table[j].key = 0;
                table[j].value = "";
                count--;

                return;
            } else {
                i++;
            }
        }

        printf("No such data.\n");
    }
};

int main() {
    HashOpenAddress hash(8);

    hash.Insert(33, "blue");
    hash.Insert(10, "yellow");
    hash.Insert(77, "red");
    hash.Insert(2, "white");
    hash.DisplayTable();

    hash.Insert(8, "black");
    hash.Insert(47, "gray");
    hash.Insert(90, "purple");
    hash.Insert(1, "deep purple");
    hash.DisplayTable();

    hash.Insert(15, "green"), printf("\n");

    printf("Search key(90): %s\n", hash.Search(90).c_str()), printf("\n");

    hash.Delete(90);
    printf("--- After delete key(90) ---\n");
    printf("Search key(90): %s\n", hash.Search(90).c_str()), printf("\n");

    hash.Insert(12, "orange");
    hash.DisplayTable();

    return 0;
}