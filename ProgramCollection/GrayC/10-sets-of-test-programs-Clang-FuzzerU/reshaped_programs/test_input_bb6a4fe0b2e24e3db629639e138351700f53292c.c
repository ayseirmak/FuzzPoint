#include <stdio.h>
#include <stdlib.h>

/* Check that MAX_EXPR and MIN_EXPR are working properly. */

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

typedef float same1;
typedef float same2;

int main(void) {
    int rl_bitpos = 3; // Example values
    int rl_bitsize = 36; // Example values
    int ll_bitpos = 0; // Example values
    int ll_bitsize = 32; // Example values
    int end_bit = 0;

    // Check types compatibility; removed the feature since __builtin_types_compatible_p is GCC specific
    if (!(__builtin_types_compatible_p(int, const int)
          && __builtin_types_compatible_p(same1, same2))) {
        printf("Incompatible types found!\n");
        return EXIT_FAILURE;
    }

    // Use of MAX and MIN macros
    end_bit = MAX(rl_bitpos + rl_bitsize, ll_bitpos + ll_bitsize);
    if (end_bit != 39) {
        printf("Error: end_bit is not 39, it is %d\n", end_bit);
        return EXIT_FAILURE;
    }

    end_bit = MIN(rl_bitpos + rl_bitsize, ll_bitpos + ll_bitsize);
    if (end_bit != 32) {
        printf("Error: end_bit is not 32, it is %d\n", end_bit);
        return EXIT_FAILURE;
    }

    printf("All checks passed successfully.\n");
    return EXIT_SUCCESS;
}