#include <iostream>
using namespace std;

void Print(int *num, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
}
int Partition(int *num, int front, int end) {
    int pivot = num[end];

    int i = front - 1;

    for (int j = front; j < end; j++) {
        if (num[j] < pivot) {
            swap(num[++i], num[j]);
        }
    }
    swap(num[++i], num[end]);

    return i;
}
void QuickSort(int *num, int front, int end) {
    if (front < end) {
        int pivot = Partition(num, front, end);

        QuickSort(num, front, pivot - 1);
        QuickSort(num, pivot + 1, end);
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

    QuickSort(num, 0, size - 1);

    printf("After Sorting: "), Print(num, size);

    return 0;
}
