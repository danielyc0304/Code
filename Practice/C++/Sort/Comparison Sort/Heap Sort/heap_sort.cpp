#include <iostream>
using namespace std;

void Print(vector<int> &num) {
    for (int i = 0; i < num.size(); i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
}

void MaxHeapify(vector<int> &num, int root, int size) {
    int left = 2 * root, right = 2 * root + 1, largest;

    if (left <= size && num[left] > num[root]) {
        largest = left;
    } else {
        largest = root;
    }
    if (right <= size && num[right] > num[largest]) {
        largest = right;
    }

    if (largest != root) {
        swap(num[root], num[largest]);

        MaxHeapify(num, largest, size);
    }
}
void BuildMaxHeap(vector<int> &num) {
    for (int i = num.size() / 2; i >= 1; i--) {
        MaxHeapify(num, i, num.size() - 1);
    }
}
void HeapSort(vector<int> &num) {
    num.insert(num.begin(), 0);

    BuildMaxHeap(num);

    int size = num.size() - 1;
    for (int i = num.size() - 1; i >= 2; i--) {
        swap(num[1], num[i]);
        MaxHeapify(num, 1, --size);
    }

    num.erase(num.begin());
}

int main() {
    int size;
    printf("Enter size: "), scanf("%d", &size);

    int num[size];
    printf("Enter %d numbers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &num[i]);
    }
    vector<int> num_vector(num, num + size);

    printf("Before sorting: "), Print(num_vector);

    HeapSort(num_vector);

    printf("After sorting: "), Print(num_vector);

    return 0;
}
