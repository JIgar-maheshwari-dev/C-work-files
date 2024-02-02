#include <stdio.h>

int main() {
    // Redirect stdin to a file
    freopen("input.txt", "r", stdin);

    // Now, scanf will read from input.txt
    int num;
    scanf("%d", &num);
    printf("Read from file: %d\n", num);

    return 0;
}

