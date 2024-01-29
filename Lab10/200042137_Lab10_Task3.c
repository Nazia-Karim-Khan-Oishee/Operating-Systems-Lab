#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define M 5
#define K 3
#define N 5

int A[M][K] = {{1, 2}, {3, 4}, {5, 6},{4,5},{6,7}};
int B[K][N] = {{7, 8, 9,10,4}, {5,6,10, 11, 12},{4,8,3,9,10}};
int C[M][N];


void* calculateElement(void* arg) {
    int* indices = (int*)arg;
    int row = indices[0];
    int col = indices[1];

    C[row][col] = 0;

    for (int k = 0; k < K; ++k) {
        C[row][col] += A[row][k] * B[k][col];
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[M][N];

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            int* indices = (int*)malloc(2 * sizeof(int));
            indices[0] = i;
            indices[1] = j;

            if (pthread_create(&threads[i][j], NULL, calculateElement, (void*)indices) != 0) {
                perror("pthread_create");
                exit(EXIT_FAILURE);
            }
        }
    }

    
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (pthread_join(threads[i][j], NULL) != 0) {
                perror("pthread_join");
                exit(EXIT_FAILURE);
            }
        }
    }

   
    printf("Matrix A:\n");
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < K; ++j) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("Matrix C (Result of A * B):\n");
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
