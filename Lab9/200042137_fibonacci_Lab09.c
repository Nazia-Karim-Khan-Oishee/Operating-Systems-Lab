#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void generateFibonacci(int n, int *fibonacci) {
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i < n; ++i) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}

int main() {
    
    int n;

    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    // Creating shared memory 
    key_t key = ftok(".", 'A');
    int shmid = shmget(key, n * sizeof(int), IPC_CREAT | 0666);

    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    int *fibonacci = (int *)shmat(shmid, NULL, 0);

    if ((intptr_t)fibonacci == -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Creating child process
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {

        printf("Child process:  Generating Fibonacci Series... \n") ;
        generateFibonacci(n, fibonacci);

        
        if (shmdt(fibonacci) == -1) {
            perror("shmdt in child");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }
     else {
       
        wait(NULL);

        printf("Parent process \n"); 
        printf("Fibonacci sequence: ");
        for (int i = 0; i < n; ++i) {
            printf("%d ", fibonacci[i]);
        }
        printf("\n");

        // Detach and remove shared memory
        if (shmdt(fibonacci) == -1) {
            perror("shmdt in parent");
            exit(EXIT_FAILURE);
        }

        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
