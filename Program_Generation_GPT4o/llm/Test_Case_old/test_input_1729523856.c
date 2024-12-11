
#include <stdio.h>
#include <math.h>
#include <float.h>

// Function to perform a simple linear regression
void linear_regression(const double *x, const double *y, int n, double *slope, double *intercept) {
    double sum_x = 0.0, sum_y = 0.0, sum_x2 = 0.0, sum_xy = 0.0;
    for (int i = 0; i < n; ++i) {
        sum_x += x[i];
        sum_y += y[i];
        sum_x2 += x[i] * x[i];
        sum_xy += x[i] * y[i];
    }
    *slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    *intercept = (sum_y - *slope * sum_x) / n;
}

int main() {
    // Input data (x, y) for linear regression
    const int n = 5;
    double x[n] = {0, 1, 2, 3, 4};
    double y[n] = {0, 2, 4.1, 6, 8}; // introducing a slight deviation for testing

    // Calculate slope and intercept
    double slope = 0.0, intercept = 0.0;
    linear_regression(x, y, n, &slope, &intercept);

    // Output results
    printf("Linear regression model: y = %f * x + %f\n", slope, intercept);

    // Floating-point edge cases
    double zero = 0.0;
    double inf = 1.0 / zero;  // Infinity
    double nan = sqrt(-1.0);  // Not-a-Number (NaN)
    double neg_inf = -1.0 / zero; // Negative Infinity
    double tiny = DBL_MIN / 2.0;  // Underflow example

    printf("Infinity: %f\n", inf);
    printf("NaN: %f\n", nan);
    printf("Negative Infinity: %f\n", neg_inf);
    printf("Underflow (tiny number): %e\n", tiny);

    // Handling denormalized numbers
    double denorm = tiny / 2.0;
    printf("Denormalized number: %e\n", denorm);

    // Handling rounding behavior
    double rounded_value = rint(2.6);
    printf("Rounding 2.6: %f\n", rounded_value);

    // Large numbers that can cause overflow
    double large1 = 1.0e308;
    double large2 = 1.0e308;
    double result = large1 * large2; // This should overflow
    printf("Overflow example: %f\n", result);

    return 0;
}
