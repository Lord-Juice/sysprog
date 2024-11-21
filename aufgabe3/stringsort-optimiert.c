#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define m 12

void bubblesort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {
    char *a = (char *)base; // Cast zu char* für Berechnung von Offsets
    char *tmp = malloc(size); // Temporärer Speicher für ein Element
    if (tmp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = nitems; i > 1; --i) {
        for (size_t j = 0; j < i - 1; ++j) {
            // Vergleich über die übergebene Funktion compar
            if (compar(&a[j * size], &a[(j + 1) * size]) > 0) {
                // Elemente tauschen
                memcpy(tmp, &a[(j + 1) * size], size);
                memcpy(&a[(j + 1) * size], &a[j * size], size);
                memcpy(&a[j * size], tmp, size);
            }
        }
    }

    free(tmp);
}


int main(int argc, const char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s Anzahl\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n < 1) {
        fprintf(stderr, "Anzahl muss mindestens 1 sein\n");
        return 1;
    }

    char *a = malloc(n * m * sizeof(char));
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));

    printf("Unsortiertes Array:\n");
    for (int i = 0; i < n; ++i) {
        int r = rand() % n;
        snprintf(&a[i * m], m, "%d", r);
        printf("%s ", &a[i * m]);
    }
    printf("\n");

    bubblesort(a, n, m, (int (*)(const void *, const void *))strcmp);

    printf("Sortiertes Array:\n");
    printf("%s", &a[0]);
    for (int i = 1; i < n; ++i) {
        if (strcmp(&a[i * m], &a[(i - 1) * m]) == 0) {
            printf("*");
        } else {
            printf(" %s", &a[i * m]);
        }
    }
    printf("\n");

    free(a);

    return 0;
}