#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void bubblesort(char **a, int n) {
    for (int i = n; i > 1; --i) {
        for (int j = 0; j < i - 1; ++j) {
            if (strcmp(a[j], a[j + 1]) > 0) {
                char *tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s Anzahl\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n < 1) {
        fprintf(stderr, "Anzahl muss mindestens 1 sein\n");
        return 1;
    }

    char **a = malloc(n * sizeof(char *));
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));

    printf("Unsortiertes Array:\n");
    for (int i = 0; i < n; ++i) {
        int r = rand() % n;
        a[i] = malloc(12 * sizeof(char)); // Allocate memory for each string
        if (a[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        snprintf(a[i], 12, "%d", r);
        printf("%s ", a[i]);
    }
    printf("\n");

    bubblesort(a, n);

    printf("Sortiertes Array:\n");
    printf("%s", a[0]);
    for (int i = 1; i < n; ++i) {
        if (strcmp(a[i], a[i - 1]) == 0) {
            printf("*");
        } else {
            printf(" %s", a[i]);
        }
    }
    printf("\n");

    for (int i = 0; i < n; ++i) {
        free(a[i]);
    }
    free(a);

    return 0;
}