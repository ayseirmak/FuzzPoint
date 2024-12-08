#include <stdio.h>
#include <string.h>

unsigned nfails = 0;

#define A(expr, N)                             \
    do {                                       \
        const char *s = (expr);                \
        unsigned n = strlen(s);                \
        if (n != N)                            \
        {                                      \
            printf("line %d: strlen(%s = \"%s\") == %u failed\n", \
                   __LINE__, #expr, s, n);     \
            ++nfails;                          \
        }                                      \
    } while (0)

const char ca[][4] = {
    {'1', '2', '3', '4'}, {'5'},
    {'1', '2', '3', '4'}, {'5', '6'},
    {'1', '2', '3', '4'}, {'5', '6', '7'},
    {'1', '2', '3', '4'}, {'5', '6', '7', '8'},
    {'9'}
};

void test_const_global_arrays(void) {
    int idx = 0;
    int i = 0, j;

    A(ca[0], 4);
    A(&ca[0][0], 4);
    A(&ca[0][1], 3);
    A(&ca[0][3], 1);

    A(ca[i], 4);
    A(&ca[i][0], 4);
    A(&ca[i][1], 3);
    A(&ca[i][3], 1);

    j = i;
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

struct MemArrays {
    char a[4];
    char b[4];
};

const struct MemArrays cma[] = {
    {{'1', '2', '3', '4'}, {'5'}},
    {{'1', '2', '3', '4'}, {'5', '6'}},
    {{'1', '2', '3', '4'}, {'5', '6', '7'}}
};

void test_nonconst_local_member_arrays(void) {
    int idx = 0;
    int i = 0, j;

    A(cma[0].a, 4);
    A(&cma[0].a[0], 4);
    A(&cma[0].a[1], 3);
    A(&cma[0].a[2], 2);

    j = i;
    A(&cma[i].a[j], 4);
    A(&cma[i].a[j + 1], 3);
    A(&cma[i].a[j + 2], 2);

    A(&cma[idx].a[i], 4);
    A(&cma[idx].a[j + 1], 3);
    A(&cma[idx].a[j + 2], 2);

    A(&cma[idx].a[idx], 4);
    A(&cma[idx].a[idx + 1], 3);
    A(&cma[idx].a[idx + 2], 2);

    A(&cma[0].a[++j], 3);
    A(&cma[0].a[++j], 2);
    A(&cma[0].a[++j], 1);

    if (j != 3) {
        ++nfails;
    }
}

int main() {
    test_const_global_arrays();
    test_nonconst_local_member_arrays();

    printf("Number of failures: %u\n", nfails);
    return nfails != 0;
}