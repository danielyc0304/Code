#include <iostream>
#include <vector>
using namespace std;

int calculateSum(const vector<int> &numbers) {
    int sum = 0;
    for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }
    return sum;
}
vector<int> findElementIndicesAndCount(const vector<int> &numbers, int target,
                                       int &count) {
    vector<int> index;
    count = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == target) {
            index.push_back(i);
            count++;
        }
    }
    if (index.size() == 0) {
        index.push_back(-1);
        count = 1;
    }
    return index;
};
void removeOddNumbers(vector<int> &numbers) {
    for (int i = numbers.size() - 1; i >= 0; i--) {
        if (numbers[i] % 2 != 0) {
            numbers.erase(numbers.begin() + i);
        }
    }
}
int findMinValue(const vector<int> &numbers) {
    int min_num = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        min_num = min(min_num, numbers[i]);
    }
    return min_num;
};
vector<int> mergeAndSortVectors(const vector<int> &vector1,
                                const vector<int> &vector2) {
    vector<int> merged_vector = vector1;
    for (int i = 0; i < vector2.size(); i++) {
        merged_vector.push_back(vector2[i]);
    }
    sort(merged_vector.begin(), merged_vector.end());
    return merged_vector;
};

int main() {
    int size;
    scanf("%d", &size);
    vector<int> vector1;
    for (int i = 0; i < size; i++) {
        int tmp;
        scanf("%d", &tmp);
        vector1.push_back(tmp);
    }

    scanf("%d", &size);
    vector<int> vector2;
    for (int i = 0; i < size; i++) {
        int tmp;
        scanf("%d", &tmp);
        vector2.push_back(tmp);
    }

    int target;
    scanf("%d", &target);

    printf("%d\n", calculateSum(vector1));

    int c;
    vector<int> index = findElementIndicesAndCount(vector1, target, c);
    if (index[0] == -1) {
        printf("-1\n");
    } else {
        for (int i = 0; i < index.size(); i++) {
            printf("%d ", index[i]);
        }
        printf("%d\n", c);
    }

    removeOddNumbers(vector1);
    for (int i = 0; i < vector1.size(); i++) {
        printf("%d ", vector1[i]);
    }
    printf("\n");

    printf("%d\n", findMinValue(vector1));

    vector<int> merged_vector = mergeAndSortVectors(vector1, vector2);
    for (int i = 0; i < merged_vector.size(); i++) {
        printf("%d ", merged_vector[i]);
    }
    printf("\n");

    return 0;
}
