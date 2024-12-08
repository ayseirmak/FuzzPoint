#include <stdio.h>
#include <stdbool.h>

double foo(double x) {
    double t = 0.0;
    switch ((int)x) {
        case 0:
            t = 2 * x - 1;
            return 0.00070878 + (0.00071234 + (0.000035779 + (0.00000017403 + (0.00000000081710 + (0.000000000036885 + 0.00000000000015917 * t) * t) * t) * t) * t) * t;
        case 1:
            t = 2 * x - 3;
            return 0.0021479 + (0.00072686 + (0.000036843 + (0.00000018071 + (0.00000000085496 + (0.000000000038852 + 0.00000000000016868 * t) * t) * t) * t) * t) * t;
        // (The rest of the cases are omitted for brevity, but you would continue to include them here)
        case 89:
            t = 2 * x - 179;
            return 0.0063178 + (0.0013368 + (0.00016254 + (0.000014695 + (0.000010072 + (0.000000051822 + 0.00000000000019025 * t) * t) * t) * t) * t) * t;
        // Additional cases as defined in the original code
        default:
            return 1.0;
    }
}

int main() {
    // Fixed deterministic input
    double x = 78.4;
    double d = foo(x);

    // Fixed output checking using assertions
    if (d < 0.38 || d > 0.42) {
        printf("Output is out of the expected range: %f\n", d);
        return 1; // Indicate error
    }

    printf("Output is within the expected range: %f\n", d);
    return 0;
}