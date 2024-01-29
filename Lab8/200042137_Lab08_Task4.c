#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
char command[100];

printf("Enter the command to execute: ");
if (scanf("%99s", command) != 1) {
printf("Failed to read the command.\n");
exit(1);
}


pid_t child_pid = fork();

if (child_pid < 0) {
printf("Fork failed");
exit(1);
} 
else if (child_pid == 0) {
printf("Hi, I am a Child Process\n");
exit(0);
} 
else 
{
int status;
waitpid(child_pid, &status, 0);

if (WIFEXITED(status)) {
printf("Child process completed with status: %d\n", WEXITSTATUS(status));
if (execlp(command, command, NULL) == -1) {
perror("Exec failed");
exit(1);
}
} 
else {
printf("Child process did not exit normally.\n");
exit(1);
}
}

return 0;
}
