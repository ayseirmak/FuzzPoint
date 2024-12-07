#include <stdio.h>
#include <math.h>

// Replaces the custom assertion error handling with standard error handling
void reach_error() {
    printf("Reach error occurred.\n");
    abort();  // Using standard abort to terminate the program if an error is reached
}

// Nan check for doubles
int isnan_double(double x) {
    return x != x;
}

static const double huge_ceil = 1.0e300;

double ceil_double(double x) {
    unsigned int i0, i1;
    int j0;
    unsigned int i, j;

    // Extract the double components
    union {
        double value;
        struct {
            unsigned int lsw;
            unsigned int msw;
        } parts;
    } ew_u;

    ew_u.value = x;
    i0 = ew_u.parts.msw;
    i1 = ew_u.parts.lsw;

    j0 = ((i0 >> 20) & 0x7ff) - 0x3ff;

    if (j0 < 20) {
        if (j0 < 0) {
            if (huge_ceil + x > 0.0) {
                if (i0 < 0) {
                    i0 = 0x80000000;
                    i1 = 0;
                } else if ((i0 | i1) != 0) {
                    i0 = 0x3ff00000;
                    i1 = 0;
                }
            }
        } else {
            i = (0x000fffff) >> j0;
            if (((i0 & i) | i1) == 0)
                return x;
            if (huge_ceil + x > 0.0) {
                if (i0 > 0)
                    i0 += (0x00100000) >> j0;
                i0 &= (~i);
                i1 = 0;
            }
        }
    } else if (j0 > 51) {
        if (j0 == 0x400)
            return x + x;
        else
            return x;
    } else {
        i = ((unsigned int) (0xffffffff)) >> (j0 - 20);
        if ((i1 & i) == 0)
            return x;
        if (huge_ceil + x > 0.0) {
            if (i0 > 0) {
                if (j0 == 20)
                    i0 += 1;
                else {
                    j = i1 + (1 << (52 - j0));
                    if (j < i1)
                        i0 += 1;
                    i1 = j;
                }
            }
            i1 &= (~i);
        }
    }

    // Convert back to double
    union {
        double value;
        struct {
            unsigned int lsw;
            unsigned int msw;
        } parts;
    } result_u;

    result_u.parts.msw = i0;
    result_u.parts.lsw = i1;
    x = result_u.value;

    return x;
}

int main() {
    double x = -0.0;
    double res = ceil_double(x);

    // x is -0, the result shall be x
    if (res != x) {
        reach_error();
        return 1;
    }

    printf("Test passed.\n");
    return 0;
}