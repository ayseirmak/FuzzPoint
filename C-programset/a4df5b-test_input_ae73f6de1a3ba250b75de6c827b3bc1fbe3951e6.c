#include <stdio.h>
#include <string.h>

unsigned nfails;
int idx = 0;

// Macro for assertion and logging
#define A(expr, N) \
    do { \
        const char *s = (expr); \
        unsigned n = strlen(s); \
        if (n != N) { \
            printf("Assertion failed at line %d: strlen(%s) == %u, got %u\n", __LINE__, #expr, N, n); \
            ++nfails; \
        } \
    } while (0)

const char ca[][4] = {
    { '1', '2', '3', '4' }, { '5' },
    { '1', '2', '3', '4' }, { '5', '6' },
    { '1', '2', '3', '4' }, { '5', '6', '7' },
    { '1', '2', '3', '4' }, { '5', '6', '7', '8' },
    { '9' }
};

void test_const_global_arrays(void) {
    A(ca[0], 5);
    A(&ca[0][0], 5);
    A(&ca[0][1], 4);
    A(&ca[0][3], 2);

    int i = 0;
    A(ca[i], 5);
    A(&ca[i][0], 5);
    A(&ca[i][1], 4);
    A(&ca[i][3], 2);

    int j = i;
    A(&ca[i][i], 5);
    A(&ca[i][j + 1], 4);
    A(&ca[i][j + 2], 3);

    if(idx < sizeof(ca)/sizeof(ca[0])) {
        A(&ca[idx][i], 5);
        A(&ca[idx][j + 1], 4);
        A(&ca[idx][j + 2], 3);

        A(&ca[idx][idx], 5);
        A(&ca[idx][idx + 1], 4);
        A(&ca[idx][idx + 2], 3);
    }
    
    A(&ca[0][++j], 4);
    A(&ca[0][++j], 3);
    A(&ca[0][++j], 2);

    if (j != 3) {
        ++nfails;
    }
}

int main(void) {
    test_const_global_arrays();
    if (nfails > 0) {
        printf("Test finished with %u failures.\n", nfails);
    } else {
        printf("Test passed successfully.\n");
    }
    return 0;
}