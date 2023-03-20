#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid; //? pid_t is a data type which is used to represent process id
    pid = fork(); //! fork() system call creates a new process
    if (pid == 0) {
        printf("Child process\n");
    } else if (pid > 0) {
        printf("Parent process\n");
    } else {
        printf("Fork failed\n");
    }
    // now printing process id
    printf("Process ID: %d\n", getpid()); //? getpid() returns process id
    printf("Parent process ID: %d\n", getppid()); //? getppid() returns parent process id
    return 0;
}