#include <iostream>
#include <list>
using namespace std;

struct Dict {
    string key, value;

    Dict(string key, string value) { this->key = key, this->value = value; }
};
class HashChainStd {
  private:
    vector<list<Dict>> table;
    int size, count;

    int PreHashing(string key_str) {
        int key_int = 0;
        int exp = 9, s = 1;

        for (int i = key_str.size() - 1; i >= 0; i--) {
            key_int += key_str[i] * s;
            s *= exp;
        }

        return key_int;
    }
    int HashFunction(string key_str) { return PreHashing(key_str) % size; }

  public:
    HashChainStd(int size) {
        this->table.resize(size);
        this->size = size, this->count = 0;
    }

    void DisplayTable() {
        for (int i = 0; i < table.size(); i++) {
            printf("slot#%d: ", i);
            for (list<Dict>::iterator it = table[i].begin();
                 it != table[i].end(); it++) {
                printf("(%s,%s) ", it->key.c_str(), it->value.c_str());
            }
            printf("\n");
        }
    }

    string Search(string key_str) {
        int i = HashFunction(key_str);

        for (list<Dict>::iterator it = table[i].begin(); it != table[i].end();
             it++) {
            if (it->key == key_str) {
                return it->value;
            }
        }

        return "No such data.";
    }

    void Insert(Dict data) {
        int i = HashFunction(data.key);

        table[i].push_front(data);
    }

    void Delete(string key_str) {
        int i = HashFunction(key_str);

        for (list<Dict>::iterator it = table[i].begin(); it != table[i].end();
             it++) {
            if (it->key == key_str) {
                table[i].erase(it);

                return;
            }
        }
    }
};

int main() {
    HashChainStd hash(5);

    hash.Insert(Dict("T-Mac", "Magic"));
    hash.Insert(Dict("Bryant", "Lakers"));
    hash.Insert(Dict("Webber", "Kings"));
    hash.Insert(Dict("Arenas", "Wizards"));
    hash.Insert(Dict("Davis", "Clippers"));
    hash.Insert(Dict("Kidd", "Nets"));

    hash.DisplayTable();
    printf("\n");

    printf("T-Mac is in %s\n", hash.Search("T-Mac").c_str());
    printf("Arenas is in %s\n", hash.Search("Arenas").c_str());
    printf("\n");

    hash.Delete("Kidd");
    hash.Delete("T-Mac");

    printf("--- After delete Kidd and T-Mac ---\n");
    hash.DisplayTable();

    return 0;
}