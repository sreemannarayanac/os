#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd, n;
    char buffer[] = "Hello, world!\n"; // This is the data which will be written to the file
    fd = open("file1.txt", O_WRONLY | O_CREAT, 0644); /* O_WRONLY is a flag which specifies that the file is opened in write-only mode 
    and O_CREAT is a flag which specifies that the file will be created if it does not exist.*/
    if (fd == -1) {
        printf("Error opening file\n");
    } else {
        n = write(fd, buffer, sizeof(buffer)); //? write() system call writes the data to the file
        printf("Wrote %d bytes to file\n", n);
    }
    close(fd);
    return 0;
}