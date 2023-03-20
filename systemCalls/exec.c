#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before exec\n");
    execl("/bin/ls", "ls", "-a", "/home", NULL); //? The first argument is the path to the executable file, the second argument is the name of the executable file,
        //? the third argument is the first argument to the executable file, the fourth argument is the second argument to 
        //? the executable file and the last argument is NULL.
    printf("After exec\n");
    return 0;
}