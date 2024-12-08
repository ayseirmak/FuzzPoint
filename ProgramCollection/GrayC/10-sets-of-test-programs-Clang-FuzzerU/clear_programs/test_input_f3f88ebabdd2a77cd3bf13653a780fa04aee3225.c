#include <stdio.h>
#include <string.h>

// Helper macro to check results
unsigned nfails = 0;

#define CHECK(expr, expected)                                       \
    do {                                                            \
        const char *s = (expr);                                     \
        unsigned n = strlen(s);                                     \
        if (n != expected) {                                        \
            printf("Line %d: strlen(%s = \"%s\") == %u failed\n",   \
                   __LINE__, #expr, s, n);                          \
            ++nfails;                                               \
        }                                                           \
    } while (0)

// Pre-defined test arrays
const char const_global_ca[][4] = {
    {'1', '2', '3', '4'}, {'5'},
    {'1', '2', '3', '4'}, {'5', '6'},
    {'1', '2', '3', '4'}, {'5', '6', '7'},
    {'1', '2', '3', '4'}, {'5', '6', '7', '8'},
    {'9'}
};

char global_va[][4] = {
    {'1', '2', '3', '4'}, {'5'},
    {'1', '2', '3', '4'}, {'5', '6'},
    {'1', '2', '3', '4'}, {'5', '6', '7'},
    {'1', '2', '3', '4'}, {'5', '6', '7', '8'},
    {'9'}
};

// Struct definitions
struct MemArrays { char a[4], b[4]; };

const struct MemArrays const_global_cma[] = {
    {{'1', '2', '3', '4'}, {'5'}},
    {{'1', '2', '3', '4'}, {'5', '6'}},
    {{'1', '2', '3', '4'}, {'5', '6', '7', '8'}},
    {{'9'}, {0}}
};

// Function prototypes
static void test_const_global_arrays(void);
static void test_nonconst_global_arrays(void);
static void test_const_global_member_arrays(void);

// Test implementations
static void test_const_global_arrays(void) {
    CHECK(const_global_ca[0], 5);
    CHECK(&const_global_ca[0][0], 5);
    CHECK(&const_global_ca[0][1], 4);
    CHECK(&const_global_ca[0][3], 2);
}

static void test_nonconst_global_arrays(void) {
    CHECK(global_va[0], 5);
    CHECK(&global_va[0][0], 5);
    CHECK(&global_va[0][1], 4);
    CHECK(&global_va[0][3], 2);
}

static void test_const_global_member_arrays(void) {
    CHECK(const_global_cma[0].a, 5);
    CHECK(&const_global_cma[0].a[0], 5);
    CHECK(&const_global_cma[0].a[1], 4);
    CHECK(&const_global_cma[0].a[2], 3);
}

// Main function
int main(void) {
    test_const_global_arrays();
    test_nonconst_global_arrays();
    test_const_global_member_arrays();

    if (nfails) {
        printf("Number of failures: %u\n", nfails);
        return 1; // Failure
    }
    
    printf("All tests passed!\n");
    return 0; // Success
}