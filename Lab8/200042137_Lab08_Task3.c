#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
int n;

printf("Enter the number of terms in the Fibonacci sequence: ");
scanf("%d", &n);
    
if (n < 0) { printf("Provide a valid non-negative integer.\n"); 
return 1; 
}

pid_t child_pid = fork();

if (child_pid < 0) {
printf("Fork failed");
return 1;
}
else if (child_pid == 0) {
int first = 0, second = 1, next;

printf("Fibonacci Sequence for %d terms: ", n);

for (int i = 0; i < n; i++) {
if (i <= 1){
next = i;
}
else {
next = first + second;
first = second;
second = next;
}
printf("%d ", next);
}

} 
else {
wait(NULL);
//printf("Parent process.\n");
}

return 0;
}



