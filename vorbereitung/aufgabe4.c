#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <numbers>\n", argv[0]);
        return 1;
    }

    int sum = 0;

    char a = argv[0];

    printf(a);

    for (int i = 1; i < argc; i++) {
        sum += atoi(argv[i]);
    }

    printf("Sum: %d\n", sum);

    return 0;
}