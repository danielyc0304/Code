#include <iostream>
using namespace std;

void Print(int *num, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
}
void InsertionSort(int *num, int size) {
    for (int i = 1; i < size; i++) {
        int tmp = num[i];

        int j = i - 1;
        while (j >= 0 && num[j] > tmp) {
            num[j + 1] = num[j];
            j--;
        }
        num[j + 1] = tmp;
    }
}

int main() {
    int size;
    printf("Enter size: "), scanf("%d", &size);

    int num[size];
    printf("Enter %d numbers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &num[i]);
    }

    printf("Before Sorting: "), Print(num, size);

    InsertionSort(num, size);

    printf("After Sorting: "), Print(num, size);

    return 0;
}
