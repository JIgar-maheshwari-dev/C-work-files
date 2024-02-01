#include <stdio.h>

int main() {
    char name[100];

    // Read input from user
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    // Display output
    printf("Hello, %s\n", name);

    // Print to stderr
    fprintf(stderr, "This is an error message\n");

    return 0;
}

