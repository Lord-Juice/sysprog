#include <stdio.h>

int main(void)
{
    char c = 1;
    int i = 2;
    float f = 3.0;
    double d = 4.0;
    short int si = 5;
    long int li = 6;
    long long int lli = 7;
    unsigned char uc = 8;
    unsigned int ui = 9;
    unsigned short int usi = 10;
    unsigned long int uli = 11;
    unsigned long long int ulli = 12;
    _Bool b = 1;
    _Complex float cf = 14.0;
    _Complex double cd = 15.0;
    char* s = "Hallo";

    // Print Adress, space, type, name and value
    // printf("%p %lu char c = %d\n", &c, sizeof(c), c);
    printf("Adresse: %p, Speicherbedarf: %lu bits, Typ: char, name: c, Wert: %d\n", &c, sizeof(c)*4, c);
    printf("Adresse: %p, Speicherbedarf: %lu bits, Typ: int, name: i, Wert: %d\n", &i, sizeof(i)*4, i);
    printf("Adresse: %p, Speicherbedarf: %lu bits, Typ: float, name: f, Wert: %f\n", &f, sizeof(f)*4, f);
    printf("Adresse: %p, Speicherbedarf: %lu bits, Typ: double, name: d, Wert: %f\n", &d, sizeof(d)*4, d);
    printf("Adresse: %p, Speicherbedarf: %lu bits, Typ: short int, name: si, Wert: %d\n", &si, sizeof(si)*4, si);
    printf("Adresse: %p, Speicherbedarf: %lu bits, Typ: long int, name: li, Wert: %d\n", &li, sizeof(li)*4, li);
    printf("Adresse: %p, Speicherbedarf: %lu bits, Typ: long long int, name: lli, Wert: %d\n", &lli, sizeof(lli)*4, lli);
    printf("Adresse: %p, Speicherbedarf: %lu bits, Typ: unsigned char, name: uc, Wert: %d\n", &uc, sizeof(uc)*4, uc);
    printf("Adresse: %p, Speicherbedarf: %lu bits, Typ: unsigned int, name: ui, Wert: %d\n", &ui, sizeof(ui)*4, ui);
    printf("Adresse: %p, Speicherbedarf: %lu bits, Typ: unsigned short int, name: usi, Wert: %d\n", &usi, sizeof(usi)*4, usi);
    printf("Adresse: %p, Speicherbedarf: %lu bits, Typ: unsigned long int, name: uli, Wert: %d\n", &uli, sizeof(uli)*4, uli);
    printf("Adresse: %p, Speicherbedarf: %lu bits, Typ: unsigned long long int, name: ulli, Wert: %d\n", &ulli, sizeof(ulli)*4, ulli);
    printf("Adresse: %p, Speicherbedarf: %lu bits, Typ: _Bool, name: b, Wert: %d\n", &b, sizeof(b)*4, b);
    printf("Adresse: %p, Speicherbedarf: %lu bits, Typ: _Complex float, name: cf, Wert: %f\n", &cf, sizeof(cf)*4, cf);
    printf("Adresse: %p, Speicherbedarf: %lu bits, Typ: _Complex double, name: cd, Wert: %f\n", &cd, sizeof(cd)*4, cd);
    printf("Adresse: %p, Speicherbedarf: %lu bits, Typ: char*, name: s, Wert: %s\n", &s, sizeof(s)*4, s);

    printf("Hier wird ein LP32 Modell verwendet, da int, long und pointer 4 Byte groß sind, char 1 Byte und float 4 Byte\n");
    
    return 0;
}