#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void bubblesort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {
    char *a = base;
    char *tmp = malloc(size);
    if (tmp == NULL) {
        fprintf(stderr, "Speicherreservierung fehlgeschlagen\n");
        exit(1);
    }
    for (size_t i = nitems; i > 1; --i) {
        for (size_t j = 0; j < i - 1; ++j) {
            if (compar(a + j * size, a + (j + 1) * size) > 0) {
                memcpy(tmp, a + (j + 1) * size, size);
                memcpy(a + (j + 1) * size, a + j * size, size);
                memcpy(a + j * size, tmp, size);
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

    int m = 12; // maximale String-Länge inklusive Endezeichen
    char *memory = malloc(n * m * sizeof(char));
    if (memory == NULL) {
        fprintf(stderr, "Speicherreservierung fehlgeschlagen\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        int r = rand() % 1000;
        snprintf(memory + i * m, m, "%d", r);
        printf("%s ", memory + i * m);
    }
    printf("\n");

    // bubblesort direkt auf dem Speicherbereich aufrufen
    bubblesort(memory, n, m, compare);

    printf("Sortiertes Array:\n");
    printf("%s", memory);
    for (int i = 1; i < n; ++i) {
        if (strcmp(memory + i * m, memory + (i - 1) * m) == 0) {
            printf("*");
        } else {
            printf(" %s", memory + i * m);
        }
    }
    printf("\n");

    free(memory);

    return 0;
}