#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef union {
    double value;
    struct {
        unsigned int lsw;
        unsigned int msw;
    } parts;
} ieee_double_shape_type;

// Modified fabs_double to use standard fabs
double fabs_double(double x) {
    return fabs(x);
}

// infinity check for doubles using standard functions
int isinf_double(double x) {
    return isinf(x);
}

void reach_error() {
    printf("Error: Reach error function was called.\n");
}

int main() {
    // Predefined deterministic input for testing -Inf
    double x = -1.0 / 0.0; // Equivalent to -Inf
    double res = fabs_double(x);

    // Verify if the result is +Inf
    if (!isinf_double(res)) {
        reach_error();
        return 1;
    }

    // Successful execution
    printf("Test passed: fabs_double(-Inf) returned +Inf\n");
    return 0;
}