/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/large-sub-arrays-5bd8005b/
Title: Large Sub-Arrays
Time: 2024-04-16 08:23:30 Add
*/

/*
TODO TLE，現階段來說太難了
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/large-sub-arrays-5bd8005b/editorial/
*/

#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N, M;
        long int K;
        scanf("%d %d %ld", &N, &M, &K);

        int A[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        int c = 0;
        for (int i = 0; i < N * M; i++) {
            long int sum = A[i % N];
            for (int j = i + 1; sum <= K; j++) {
                c++;

                sum += A[j % N];

                if (j == N * M) {
                    break;
                }
            }
        }

        printf("%d\n", c);
    }

    return 0;
}
