#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

//pid_t pid1 = fork();
//pid_t pid2 = fork();
//pid_t pid3 = fork();



for (int i = 0; i < 8; i++) {
pid_t pid = fork();
if ( pid < 0){
printf("Fork failed");
return 1;
}
else if ( pid == 0) {
printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
return 0;
}
else if ( pid > 0){
wait(NULL);
}
}

return 0;
}



