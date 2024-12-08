#include <stdio.h>
#include <string.h>

unsigned nfails = 0; // Initialize global variable
int idx = 0; // Initialize index to 0, can be adjusted to any required fixed value

#define A(expr, N)                                   \
    do {                                              \
        const char *s = (expr);                      \
        unsigned n = strlen(s);                      \
        if (n != (N)) {                              \
            printf("line %i: strlen(%s = \"%s\") == %u failed\n", \
                   __LINE__, #expr, s, n);          \
            ++nfails;                                \
        }                                            \
    } while (0)

const char ca[][4] = {
    { '1', '2', '3', '4' }, { '5' },
    { '1', '2', '3', '4' }, { '5', '6' },
    { '1', '2', '3', '4' }, { '5', '6', '7' },
    { '1', '2', '3', '4' }, { '5', '6', '7', '8' },
    { '9' }
};

static void test_const_global_arrays(void) {
    A(ca[0], 4);
    A(&ca[0][0], 4);
    A(&ca[0][1], 3);
    A(&ca[0][3], 1);

    int i = 0;
    A(ca[i], 4);
    A(&ca[i][0], 4);
    A(&ca[i][1], 3);
    A(&ca[i][3], 1);

    int j = i;
    A(&ca[i][i], 4);
    A(&ca[i][j + 1], 3);
    A(&ca[i][j + 2], 2);

    A(&ca[idx][i], 4);
    A(&ca[idx][j + 1], 3);
    A(&ca[idx][j + 2], 2);

    A(&ca[idx][idx], 4);
    A(&ca[idx][idx + 1], 3);
    A(&ca[idx][idx + 2], 2);

    A(&ca[0][++j], 3);
    A(&ca[0][++j], 2);
    A(&ca[0][++j], 1);

    if (j != 3) {
        ++nfails;
    }
}

int main() {
    test_const_global_arrays();
    printf("Number of failures: %u\n", nfails);
    return 0;
}