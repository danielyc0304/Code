#include <iostream>
using namespace std;

int FindSetCollapsing(int *parent, int num) {
    int root;

    for (root = num; parent[root] >= 0; root = parent[root])
        ;  // 找到root

    int preceding;
    while (num != root) {  // collapsing
        preceding = parent[num];
        parent[num] = root;
        num = preceding;
    }

    return root;
}
void UnionSet(int *parent, int num1, int num2) {
    int num1_root = FindSetCollapsing(parent, num1),
        num2_root = FindSetCollapsing(parent, num2);

    if (parent[num1_root] <=
        parent[num2_root]) {  // num1_root下面的元素比較多或一樣多
        parent[num1_root] += parent[num2_root];
        parent[num2_root] = num1_root;
    } else {  // num2_root下面的元素比較多
        parent[num2_root] += parent[num1_root];
        parent[num1_root] = num2_root;
    }
}
void Print(int *parent, int size) {
    for (int i = 0; i < size; i++) {
        printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%3d", parent[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter size: "), scanf("%d", &size), cin.get();

    int parent[size];  // parent[a] = b -> a的父節點是b
    for (int i = 0; i < size; i++) {
        parent[i] = -1;
    }

    string action;

    while (printf("Enter action: ") && getline(cin, action)) {
        if (action == "find set") {
            int num;

            printf("Enter number: "), scanf("%d", &num), cin.get();
            printf("%d\n", FindSetCollapsing(parent, num));
        } else if (action == "union set") {
            int num1, num2;

            printf("Enter two numbers: "), scanf("%d %d", &num1, &num2),
                cin.get();
            UnionSet(parent, num1, num2);
        } else if (action == "print") {
            Print(parent, size);
        } else if (action == "exit") {
            break;
        } else {
            printf("Invalid action.\n");
        }
    }

    return 0;
}
