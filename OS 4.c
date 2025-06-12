#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0)
        printf("Child Process: PID = %d\n", getpid());
    else
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);

    return 0;
}
