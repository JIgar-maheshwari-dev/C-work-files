#include <stdio.h>
#include <stdlib.h>

int main() {
    char *user = getenv("PWD");
    if (user != NULL) {
        printf("PWD is =  %s!\n", user);
    } else {
        printf("Hello, unknown user!\n");
    }
    return 0;
}

