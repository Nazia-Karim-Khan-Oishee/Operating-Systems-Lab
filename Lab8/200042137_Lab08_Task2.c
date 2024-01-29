#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
int value = 0;
pid_t pid = fork();

if (pid < 0) {
printf("Fork failed\n");
} 
else if (pid == 0) {
value = value + 200042137;
printf("Child process value: %d\n", value);
} 
else if (pid > 0) {
value = value + 137;
wait(NULL);
printf("Parent process value: %d\n", value);
}
return 0;
}

