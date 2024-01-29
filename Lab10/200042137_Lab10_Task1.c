#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

void* printPrimes(void* arg) {
    int limit = *(int*)arg;

    printf("Prime numbers up to %d: ", limit);

    for (int i = 2; i <= limit; ++i) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }

    printf("\n");

    pthread_exit(NULL);
}

int main() {
    int limit;

    
    printf("Enter the limit for prime numbers: ");
    scanf("%d", &limit);

    if (limit <= 1) {
        fprintf(stderr, "Please enter a number greater than 1.\n");
        exit(EXIT_FAILURE);
    }

    pthread_t tid;

    
    if (pthread_create(&tid, NULL, printPrimes, &limit) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    
    if (pthread_join(tid, NULL) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    return 0;
}
