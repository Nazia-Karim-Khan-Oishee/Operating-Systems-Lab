#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void* generateFibonacci(void* arg) {
    int* fibonacci = (int*)arg;
    int n = fibonacci[2];  

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i < n; ++i) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    pthread_exit(NULL);
}


int main() {
    int n;

    
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    if (n <= 0) {
        fprintf(stderr, "Please enter a positive integer for the number of Fibonacci numbers.\n");
        exit(EXIT_FAILURE);
    }

    
    int* fibonacci = (int*)malloc(n * sizeof(int));

    if (fibonacci == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    fibonacci[2] = n;

    pthread_t tid;

    if (pthread_create(&tid, NULL, generateFibonacci, (void*)fibonacci) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(tid, NULL) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    printf("Fibonacci sequence: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", fibonacci[i]);
    }
    printf("\n");

    
    free(fibonacci);

    return 0;
}
