#include <stdio.h>

#define GRUSS_FORMAT "%s %s!\n"

int equals (char *a, char *b, int n) {
    for (int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            return 1;
        }
    }
    return 0;
}

int ausgeben (char *vorname) {
    char *sepp = "Sepp";
    if(!equals(vorname, sepp, 4)) {
        printf(GRUSS_FORMAT, "Servus", vorname);
    } else {
        printf(GRUSS_FORMAT, "Hallo", vorname);
    }
}

int main() {
    ausgeben("Sepp");
    ausgeben("Paul");
}