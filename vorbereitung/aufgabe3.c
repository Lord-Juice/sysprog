#include <stdio.h>

struct Klausur
{
    char geb;
    int raum;
};

int main() {
    double *a = malloc(2 * sizeof(char));

    a[0] = 1.2;
    a[1] = 3.4;

    struct Klausur p;
    p.geb = 'G';
    p.raum = 149;

    return 0;
}
