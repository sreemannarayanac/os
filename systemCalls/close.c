#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd;
    fd = open("file.txt", O_RDONLY); //? open() system call opens the file
    if (fd == -1) {
        printf("Error opening file\n");
    } else {
        printf("File opened successfully\n");
        close(fd); //? close() system call closes the file
        printf("File closed successfully\n");
    }
    return 0;
}