#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int a[], int n) {
    for (int i = n; i > 1; --i){
        for (int j = 0; j < i - 1; ++j) {
            if (a[j] > a[j+1]) {
                int tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
    return;
}

int main(int argc, const char *argv[]){
    // Seeding random
    srand(time(NULL));

    if (argc < 1) {
        printf("Usage: %s <number_of_elements\n", argv[0]);
        return 1;
    }

    // Arraygroesse
    int n = atoi(argv[1]);
    if(n <= 0) {
        printf("Number of Elements must be positive.\n");
        return 1;
    }

    // Allocate memory
    int *a = malloc(n * sizeof(int));
    if(a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Bitte %d ganze Zahlen eingeben: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            for (int j = i; j < n; j++) {
                a[j] = rand();
            }
            break;
        }
    }


    bubblesort(a, n);

    printf("Sortierte Zahlenfolge:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }

    free(a);
    return 0;
}