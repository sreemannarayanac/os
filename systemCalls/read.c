#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd, n;
    char buffer[150];
    fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error opening file\n");
    } else {
        n = read(fd, buffer, sizeof(buffer)); //! read() system call reads the data from the file
        printf("Read %d bytes from file: \n%s", n, buffer);
        printf("\n");
    }
    close(fd);
    return 0;
}