#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> // wait() system call is defined in this header file
#include <unistd.h>

int main() {
    pid_t pid; // pid_t is a signed integer type which is capable of representing a process ID
    int status; // status is an integer variable which will store the status of the child process
    pid = fork();
    if (pid == 0) {
        printf("Child process\n"); // Child process
        exit(0);
    } else if (pid > 0) {
        printf("Parent process\n"); // Parent process
        wait(&status); //? Here parent process is waiting for child process to finish
        printf("Child process exited with status %d\n", status); // Child process exited with status 0
    } else {
        printf("Fork failed\n"); // Fork failed because pid is -1
    }
    return 0;
}


/*Why is wait() system call used?*/
/*wait() system call is used to make the parent process wait for the child process to finish.*/
/*If the parent process does not wait for the child process to finish, then the child process becomes a zombie process.*/
/*A zombie process is a process which has finished execution but still has an entry in the process table.*/
/*The zombie process is not removed from the process table until the parent process reads the 
exit status of the child process using wait() system call.*/
