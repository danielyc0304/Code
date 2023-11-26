#include <iostream>
using namespace std;

const int kMax = 1000;

void Print(vector<int> &num) {
    for (int i = 0; i < num.size(); i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
}

void Merge(vector<int> &num, int front, int mid, int end) {
    vector<int> left_sub(num.begin() + front, num.begin() + (mid + 1)),
        right_sub(num.begin() + (mid + 1), num.begin() + (end + 1));

    left_sub.push_back(kMax), right_sub.push_back(kMax);

    int left = 0, right = 0;
    for (int i = front; i <= end; i++) {
        if (left_sub[left] <= right_sub[right]) {
            num[i] = left_sub[left++];
        } else {
            num[i] = right_sub[right++];
        }
    }
}
void MergeSort(vector<int> &num, int front, int end) {
    if (front < end) {
        int mid = (front + end) / 2;

        MergeSort(num, front, mid);
        MergeSort(num, mid + 1, end);

        Merge(num, front, mid, end);
    }
}

int main() {
    int size;
    printf("Enter size: "), scanf("%d", &size);

    int num[size];
    printf("Enter %d numbers (max: %d): ", size, kMax);
    for (int i = 0; i < size; i++) {
        scanf("%d", &num[i]);
    }
    vector<int> num_vector(num, num + size);

    printf("Before sorting: "), Print(num_vector);

    MergeSort(num_vector, 0, size - 1);

    printf("After sorting: "), Print(num_vector);

    return 0;
}