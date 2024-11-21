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
    const char* s = "Hallo";

    // Print Address, space, type, name and value
    printf("Adress | space | type | name | value\n");
    printf("%p | %zu | char | c | %d\n", (void*)&c, sizeof(c), c);
    printf("%p | %zu | int | i | %d\n", (void*)&i, sizeof(i), i);
    printf("%p | %zu | float | f | %f\n", (void*)&f, sizeof(f), f);
    printf("%p | %zu | double | d | %lf\n", (void*)&d, sizeof(d), d);
    printf("%p | %zu | short int | si | %d\n", (void*)&si, sizeof(si), si);
    printf("%p | %zu | long int | li | %ld\n", (void*)&li, sizeof(li), li);
    printf("%p | %zu | long long int | lli | %lld\n", (void*)&lli, sizeof(lli), lli);
    printf("%p | %zu | unsigned char | uc | %u\n", (void*)&uc, sizeof(uc), uc);
    printf("%p | %zu | unsigned int | ui | %u\n", (void*)&ui, sizeof(ui), ui);
    printf("%p | %zu | unsigned short int | usi | %u\n", (void*)&usi, sizeof(usi), usi);
    printf("%p | %zu | unsigned long int | uli | %lu\n", (void*)&uli, sizeof(uli), uli);
    printf("%p | %zu | unsigned long long int | ulli | %llu\n", (void*)&ulli, sizeof(ulli), ulli);
    printf("%p | %zu | _Bool | b | %d\n", (void*)&b, sizeof(b), b);
    printf("%p | %zu | const char* | s | %s\n", (void*)&s, sizeof(s), s);

    return 0;
}