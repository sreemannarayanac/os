#include <stdio.h>
#include <unistd.h> // sleep() system call is defined in this header file

int main() {
    printf("Before sleep\n");
    sleep(3); //? here the process will sleep for 5 seconds
    printf("After sleep\n");
    return 0;
}