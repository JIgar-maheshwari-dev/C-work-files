#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Redirect stdout to a file
    printf("Hello, world1\n");
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    printf("Hello, world2\n");
    dup2(fd, STDOUT_FILENO);
    printf("Hello, world3\n");
    close(fd);
    printf("Hello, world4\n");

    // Now, printf will write to output.txt
    printf("Hello, world5\n");

    return 0;
}

