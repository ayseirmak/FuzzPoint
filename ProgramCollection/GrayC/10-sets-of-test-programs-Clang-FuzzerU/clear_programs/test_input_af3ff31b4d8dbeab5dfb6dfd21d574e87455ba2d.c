#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Declare external string length function
extern size_t strlen(const char *);

// Union to represent a double using two int parts
__extension__ union {
    double d;
    int i[2];
} u = { -0.25 };

// Counter for the number of failed tests
unsigned int nfails = 0;

// Index used in various test functions
int idx = 0;

// Macro for test assertions
#define A(expr, N)                                      \
  do {                                                  \
    const char *s = (expr);                             \
    unsigned n = (unsigned)strlen(s);                   \
    if (n != N) {                                       \
      printf("line %i: strlen(%s = \"%s\") == %u failed\n", \
             __LINE__, #expr, s, n);                    \
      ++nfails;                                         \
    }                                                   \
  } while (0)

// Global static content arrays
const char ca[][4] = {
  {'1', '2', '3', '4'}, {'5'},
  {'1', '2', '3', '4'}, {'5', '6'},
  {'1', '2', '3', '4'}, {'5', '6', '7'},
  {'1', '2', '3', '4'}, {'5', '6', '7', '8'},
  {'9'}
};

// Test functions
static void test_const_global_arrays(void) {
    int i = 0;
    int j = i;
    A(ca[0], 5);
    A(&ca[0][0], 5);
    A(&ca[0][1], 4);
    A(&ca[0][3], 2);

    A(&ca[i][i], 5);
    A(&ca[i][j + 1], 4);
    A(&ca[i][j + 2], 3);

    A(&ca[idx][i], 5);
    A(&ca[idx][j + 1], 4);
    A(&ca[idx][j + 2], 3);

    A(&ca[0][++j], 4);
    A(&ca[0][++j], 3);
    A(&ca[0][++j], 2);
    if (j != 3) { ++nfails; }
}

// Function to check signbit of a double
int signbit(double x) {
    union {
        double d;
        int i[2];
    } local_u = {x};
    return local_u.i[1] < 0;
}

// Main function for diagnostic testing
int main(void) {
    // Ensure that our assumption on the memory layout of doubles is correct
    if (2 * sizeof(int) != sizeof(double) || u.i[1] >= 0)
        exit(0);

    // Perform a specific test
    if (!signbit(-0.25)) {
        abort();
    }

    // Run test functions
    test_const_global_arrays();

    return 0;
}