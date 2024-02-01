#include <stdio.h>

int main() {
    FILE *fp;
    char output[1024];

    // Run the command and capture output
    fp = popen("ls -l", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        return 1;
    }

    // Read the output
    while (fgets(output, sizeof(output), fp) != NULL) {
        printf("%s", output);
    }

    // Close the pipe
    pclose(fp);

    return 0;
}

