Here are the implementations of the system calls you asked for using C programming language:

- `fork()` system call: It is used to create a new process by duplicating the calling process. The new process is called the child process, and the calling process is called the parent process. The child process runs concurrently with the parent process. Here is an example of how to use `fork()` system call in C programming language ⁴.

- `exec()` system call: It is used to replace the current process image with a new process image. Here is an example of how to use `exec()` system call in C programming language ¹.

- `wait()` system call: It is used to wait for a child process to terminate. Here is an example of how to use `wait()` system call in C programming language ².

- `sleep()` system call: It is used to suspend execution of the calling process for a specified number of seconds. Here is an example of how to use `sleep()` system call in C programming language ³.

- `open()` system call: It is used to open a file and return a file descriptor. Here is an example of how to use `open()` system call in C programming language ⁸.

- `read()` system call: It is used to read data from a file. Here is an example of how to use `read()` system call in C programming language [^10^].

- `write()` system call: It is used to write data to a file. Here is an example of how to use `write()` system call in C programming language [^10^].

- `seek()` system call: It is used to change the file position of the file descriptor. Here is an example of how to use `seek()` system call in C programming language ⁸.

- `close()` system call: It is used to close a file descriptor. Here is an example of how to use `close()` system call in C programming language ⁸.


Here is an example code for each of the system calls you asked for using C programming language:

- `fork()` system call:
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        printf("Child process\n");
    } else if (pid > 0) {
        printf("Parent process\n");
    } else {
        printf("Fork failed\n");
    }
    return 0;
}
```

- `exec()` system call:
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before exec\n");
    execl("/bin/ls", "ls", "-l", NULL);
    printf("After exec\n");
    return 0;
}
```

- `wait()` system call:
```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0) {
        printf("Child process\n");
        exit(0);
    } else if (pid > 0) {
        printf("Parent process\n");
        wait(&status);
        printf("Child process exited with status %d\n", status);
    } else {
        printf("Fork failed\n");
    }
    return 0;
}
```

- `sleep()` system call:
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before sleep\n");
    sleep(5);
    printf("After sleep\n");
    return 0;
}
```

- `open()` system call:
```c
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd;
    fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error opening file\n");
    } else {
        printf("File opened successfully\n");
    }
    close(fd);
    return 0;
}
```

- `read()` system call:
```c
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd, n;
    char buffer[100];
    fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error opening file\n");
    } else {
        n = read(fd, buffer, sizeof(buffer));
        printf("Read %d bytes from file: %s\n", n, buffer);
    }
    close(fd);
    return 0;
}
```

- `write()` system call:
```c
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd, n;
    char buffer[] = "Hello, world!\n";
    fd = open("file.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        printf("Error opening file\n");
    } else {
        n = write(fd, buffer, sizeof(buffer));
        printf("Wrote %d bytes to file\n", n);
    }
    close(fd);
    return 0;
}
```

- `seek()` system call:
```c
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd, n;
    char buffer[100];
    fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error opening file\n");
    } else {
        lseek(fd, 5, SEEK_SET);
        n = read(fd, buffer, sizeof(buffer));
        printf("Read %d bytes from file: %s\n", n, buffer);
    }
    close(fd);
    return 0;
}
```

- `close()` system call:
```c
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd;
    fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error opening file\n");
    } else {
        printf("File opened successfully\n");
        close(fd);
        printf("File closed successfully\n");
    }
    return 0;
}
```  
