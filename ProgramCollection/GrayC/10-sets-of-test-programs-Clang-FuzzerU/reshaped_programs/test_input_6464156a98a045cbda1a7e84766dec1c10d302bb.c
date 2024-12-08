#include <stdio.h>
#include <string.h>

unsigned nfails = 0;
int idx = 0;

#define A(expr, N)                                        \
    do {                                                  \
        const char *s = (expr);                           \
        unsigned n = strlen(s);                           \
        ((n == (N))                                       \
             ? 0                                          \
             : (printf("line %d: strlen(%s = \"%s\") == %u failed\n", \
                       __LINE__, #expr, s, n),            \
                ++nfails));                               \
    } while (0)

const char ca[][4] = {
    {'1', '2', '3', '4'}, {'5'},
    {'1', '2', '3', '4'}, {'5', '6'},
    {'1', '2', '3', '4'}, {'5', '6', '7'},
    {'1', '2', '3', '4'}, {'5', '6', '7', '8'},
    {'9'}};

static void test_const_global_arrays(void)
{
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

    A(&ca[idx][i], 5);
    A(&ca[idx][j + 1], 4);
    A(&ca[idx][j + 2], 3);

    A(&ca[idx][idx], 5);
    A(&ca[idx][idx + 1], 4);
    A(&ca[idx][idx + 2], 3);

    A(&ca[0][++j], 4);
    A(&ca[0][++j], 3);
    A(&ca[0][++j], 2);

    if (j != 3)
    {
        ++nfails;
    }
}

static void test_const_local_arrays(void)
{
    const char a[][4] = {
        {'1', '2', '3', '4'}, {'5'},
        {'1', '2', '3', '4'}, {'5', '6'},
        {'1', '2', '3', '4'}, {'5', '6', '7'},
        {'1', '2', '3', '4'}, {'5', '6', '7', '8'},
        {'9'}};

    A(a[0], 5);
    A(&a[0][0], 5);
    A(&a[0][1], 4);
    A(&a[0][3], 2);

    int i = 0;
    A(a[i], 5);
    A(&a[i][0], 5);
    A(&a[i][1], 4);
    A(&a[i][3], 2);

    int j = i;
    A(&a[i][i], 5);
    A(&a[i][j + 1], 4);
    A(&a[i][j + 2], 3);

    A(&a[idx][i], 5);
    A(&a[idx][j + 1], 4);
    A(&a[idx][j + 2], 3);

    A(&a[idx][idx], 5);
    A(&a[idx][idx + 1], 4);
    A(&a[idx][idx + 2], 3);

    A(&a[0][++j], 4);
    A(&a[0][++j], 3);
    A(&a[0][++j], 2);

    if (j != 3)
    {
        ++nfails;
    }
}

char va[][4] = {
    {'1', '2', '3', '4'}, {'5'},
    {'1', '2', '3', '4'}, {'5', '6'},
    {'1', '2', '3', '4'}, {'5', '6', '7'},
    {'1', '2', '3', '4'}, {'5', '6', '7', '8'},
    {'9'}};

static void test_nonconst_global_arrays(void)
{
    {
        A(va[0], 5);
        A(&va[0][0], 5);
        A(&va[0][1], 4);
        A(&va[0][3], 2);

        int i = 0;
        A(va[i], 5);
        A(&va[i][0], 5);
        A(&va[i][1], 4);
        A(&va[i][3], 2);

        int j = i;
        A(&va[i][i], 5);
        A(&va[i][j + 1], 4);
        A(&va[i][j + 2], 3);

        A(&va[idx][i], 5);
        A(&va[idx][j + 1], 4);
        A(&va[idx][j + 2], 3);

        A(&va[idx][idx], 5);
        A(&va[idx][idx + 1], 4);
        A(&va[idx][idx + 2], 3);
    }

    {
        A(va[2], 6);
        A(&va[2][0], 6);
        A(&va[2][1], 5);
        A(&va[2][3], 3);

        int i = 2;
        A(va[i], 6);
        A(&va[i][0], 6);
        A(&va[i][1], 5);
        A(&va[i][3], 3);

        int j = i - 1;
        A(&va[i][j - 1], 6);
        A(&va[i][j], 5);
        A(&va[i][j + 1], 4);

        A(&va[idx + 2][i - 1], 5);
        A(&va[idx + 2][j], 5);
        A(&va[idx + 2][j + 1], 4);
    }

    int j = 0;

    A(&va[0][++j], 4);
    A(&va[0][++j], 3);
    A(&va[0][++j], 2);

    if (j != 3)
    {
        ++nfails;
    }
}

static void test_nonconst_local_arrays(void)
{
    char a[][4] = {
        {'1', '2', '3', '4'}, {'5'},
        {'1', '2', '3', '4'}, {'5', '6'},
        {'1', '2', '3', '4'}, {'5', '6', '7'},
        {'1', '2', '3', '4'}, {'5', '6', '7', '8'},
        {'9'}};

    A(a[0], 5);
    A(&a[0][0], 5);
    A(&a[0][1], 4);
    A(&a[0][3], 2);

    int i = 0;
    A(a[i], 5);
    A(&a[i][0], 5);
    A(&a[i][1], 4);
    A(&a[i][3], 2);

    int j = i;
    A(&a[i][i], 5);
    A(&a[i][j + 1], 4);
    A(&a[i][j + 2], 3);

    A(&a[idx][i], 5);
    A(&a[idx][j + 1], 4);
    A(&a[idx][j + 2], 3);

    A(&a[idx][idx], 5);
    A(&a[idx][idx + 1], 4);
    A(&a[idx][idx + 2], 3);

    A(&a[0][++j], 4);
    A(&a[0][++j], 3);
    A(&a[0][++j], 2);

    if (j != 3)
    {
        ++nfails;
    }
}

struct MemArrays
{
    char a[4];
    char b[4];
};

void test_structs_with_unions(void)
{
    double results = f(&(union u){{.d = 0.0}}.x, &(union u){{.d = 0.0}}.y);
    printf("Test with unions and structs: %lf\n", results);
}

double f(struct s1 *a, struct s2 *b)
{
    a->d = 1.0;
    return b->d + 1.0;
}

int main()
{
    test_const_global_arrays();
    test_const_local_arrays();
    test_nonconst_global_arrays();
    test_nonconst_local_arrays();
    test_structs_with_unions();

    printf("Number of failed tests: %u\n", nfails);
    return 0;
}