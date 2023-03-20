#include <fcntl.h> // This header file contains the definitions of the flags used in the open() system call
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd, n; // n is the number of bytes read and fd is the file descriptor which is returned by the open() system call
    char buffer[100]; // This is the data which will be read from the file
    fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error opening file\n");
    } else {
        lseek(fd, 2, SEEK_SET); //? moves the file pointer to the 3rd byte from the beginning of the file
        n = read(fd, buffer, sizeof(buffer)); // read() system call reads the data from the file
        printf("Read %d bytes from file:\n%s", n, buffer); // The data read from the file is stored in the buffer
        printf("\n");
    }
    close(fd);
    return 0;
}