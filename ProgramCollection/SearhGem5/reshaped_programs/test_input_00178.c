#include <stdio.h>

int main() {
    char a = 0;
    int b = 0;
    double c = 0.0;

    printf("%lu\n", sizeof(a));
    printf("%lu\n", sizeof(b));
    printf("%lu\n", sizeof(c));

    printf("%lu\n", sizeof(!a));

    return 0;
}