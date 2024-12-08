#include <stdio.h>
#include <stdlib.h>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

typedef float same1;
typedef float same2;

int main(void) {
    // Simulate the check for compatible types
    if (!(__builtin_types_compatible_p(int, const int) &&
          __builtin_types_compatible_p(float, same1))) {
        printf("Error: Incompatible types.\n");
        abort();
    }

    // Initializing variables
    int rl_bitpos = 0;
    int rl_bitsize = 33;
    int ll_bitpos = 0;
    int ll_bitsize = 32;
    int end_bit;

    // Perform computations
    end_bit = MAX(rl_bitpos + rl_bitsize, ll_bitpos + ll_bitsize);
    if (end_bit != 33) {
        printf("Error: MAX computation incorrect.\n");
        abort();
    }

    end_bit = MIN(rl_bitpos + rl_bitsize, ll_bitpos + ll_bitsize);
    if (end_bit != 32) {
        printf("Error: MIN computation incorrect.\n");
        abort();
    }

    printf("All checks passed successfully.\n");
    return 0;
}