#include <fcntl.h> // open() system call is defined in this header file
#include <stdio.h>
#include <unistd.h> // close() system call is defined in this header file

int main() {
    int fd;
    fd = open("THEORY.md", O_RDONLY); 
    //! open() system call returns a file descriptor. O_RDONLY is a flag which specifies that the file is opened in read-only mode.
    //? Other flags are O_WRONLY, O_RDWR, O_APPEND, O_CREAT, O_TRUNC, etc.
    if (fd == -1) {
        printf("Error opening file\n");
    } else {
        printf("File opened successfully\n");
    }
    close(fd);
    return 0;
}