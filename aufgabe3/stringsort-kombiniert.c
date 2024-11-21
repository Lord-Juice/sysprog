#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STRING_LENGTH 12 // Maximale Länge eines Strings inklusive Nullterminator

void bubblesort(char **a, size_t nitems, int (*compar)(const void *, const void *)) {
    for (size_t i = nitems; i > 1; --i) {
        for (size_t j = 0; j < i - 1; ++j) {
            if (compar(a[j], a[j + 1]) > 0) {
                char *tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
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

    // Speicher für alle Strings in einem Block
    char *string_block = malloc(n * STRING_LENGTH * sizeof(char));
    if (string_block == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Speicher für das Array von String-Zeigern
    char **a = malloc(n * sizeof(char *));
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(string_block);
        return 1;
    }

    srand(time(NULL));

    // Initialisierung des Arrays
    printf("Unsortiertes Array:\n");
    for (int i = 0; i < n; ++i) {
        int r = rand() % n;
        snprintf(&string_block[i * STRING_LENGTH], STRING_LENGTH, "%d", r);
        a[i] = &string_block[i * STRING_LENGTH]; // Zeiger setzen
        printf("%s ", a[i]);
    }
    printf("\n");

    // Sortieren des Arrays
    bubblesort(a, n, (int (*)(const void *, const void *))strcmp);

    // Ausgabe des sortierten Arrays
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

    // Speicher freigeben
    free(a);
    free(string_block);

    return 0;
}
