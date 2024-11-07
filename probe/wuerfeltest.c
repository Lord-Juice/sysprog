#include <stdio.h>
#include<stdlib.h>
#include "wuerfel.h"

int main(int argc, char const *argv[])
{
    double k;
    if(sscanf(argv[1], "%lf", &k) < 0) {
        return 1;
    }

    double f = oberflaeche(k);
    double v = voloumen(k);
    printf("Kantenlänge %lf, Oberfläche: %lf, Volumen: %lf\n", k, f, v);


    return 0;
}
