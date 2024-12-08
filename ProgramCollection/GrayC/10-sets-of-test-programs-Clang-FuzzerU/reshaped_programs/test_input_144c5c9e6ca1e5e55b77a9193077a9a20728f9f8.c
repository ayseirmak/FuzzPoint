#include <stdio.h>
#include <stdlib.h>

typedef unsigned int UV __attribute__((vector_size(16)));
typedef int SV __attribute__((vector_size(16)));

void uq4444(UV *x, UV *y) {
    *x = *y / ((UV){4U, 4U, 4U, 4U});
}

void ur4444(UV *x, UV *y) {
    *x = *y % ((UV){4U, 4U, 4U, 4U});
}

void sq4444(SV *x, SV *y) {
    *x = *y / ((SV){4, 4, 4, 4});
}

void sr4444(SV *x, SV *y) {
    *x = *y % ((SV){4, 4, 4, 4});
}

int main() {
    UV ur;
    UV u[] = {
        (UV){73U, 65531U, 0U, 174U},
        (UV){1U, 8173U, ~0U, ~0U - 63U}
    };
    int i;

    for (i = 0; i < sizeof(u) / sizeof(u[0]); i++) {
        uq4444(&ur, &u[i]);
        if (ur[0] != u[i][0] / 4U || ur[3] != u[i][3] / 4U) abort();
        
        ur4444(&ur, &u[i]);
        if (ur[0] != u[i][0] % 4U || ur[3] != u[i][3] % 4U) abort();
    }

    SV sr;
    SV s[] = {
        (SV){73, -9123, 32761, 8191},
        (SV){9903, -1, -7323, 0}
    };

    for (i = 0; i < sizeof(s) / sizeof(s[0]); i++) {
        sq4444(&sr, &s[i]);
        if (sr[0] != s[i][0] / 4 || sr[3] != s[i][3] / 4) abort();

        sr4444(&sr, &s[i]);
        if (sr[0] != s[i][0] % 4 || sr[3] != s[i][3] % 4) abort();
    }

    printf("All tests passed.\n");
    return 0;
}