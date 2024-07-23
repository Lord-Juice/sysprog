#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int string_comparator(const void *a, const void *b) {
    // Cast the void pointers to char pointers
    const char **str1 = (const char **)a;
    const char **str2 = (const char **)b;

    // Use strcmp to compare the strings
    return strcmp(*str1, *str2);
}

void bubblesort(char **a[], int n) {
    for (int i = n; i > 1; --i){
        for (int j = 0; j < i - 1; ++j) {
            if (strcmp(a[j], a[j + 1]) > 0) {
                char *tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
    return;
}

int equals (char *a, char *b, int n) {
    for (int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv[]){
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

    int max_length = 100;

    // Allocate memory for String array
    char **string_array = malloc(n * sizeof (char *));
    if (string_array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Allocate memory for each string and assign random values between 0 and 9
    for (int i = 0; i < n; i++) {
        string_array[i] = malloc(max_length * sizeof(char));
        if(string_array == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        int random_number = rand() % 10; // Generate a random number between 0 and 9
        snprintf(string_array[i], max_length, "String %d", random_number);
    }

    bubblesort(string_array, n);

    char *out = malloc(n * 2 * sizeof(char *));
    int tmp = n;
    int j = 0;
    for (int i = 1; i < tmp; i++, j++) {
        if(equals(string_array[i], string_array[i - 1] == 0, n)) {
            out[i] = '*';
        } else {
            out[i] = ' ';
            i++;
            tmp++;
            out[i] = string_array[j];
        }
    }
    free(tmp);

    for(int i = 0; i < n; i++) {
        printf("%c", out[i]);
    }

    return 0;
}