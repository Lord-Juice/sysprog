#include <stdio.h>
#include "quadrat.h"
#include "wuerfel.h"

double oberflaeche(double seitenlaenge) {
    return flaeche(seitenlaenge) * 6;
}

double voloumen(double seitenlaenge) {
    return flaeche(seitenlaenge) * seitenlaenge;
}