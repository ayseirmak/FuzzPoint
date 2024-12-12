
#include <stdio.h>
#include <math.h>
#include <float.h>

// Recursive function to compute compound interest and demonstrate floating-point arithmetic
double compound_interest(double principal, double rate, int periods) {
    if (periods == 0) return principal;
    double factor = 1.0 + rate; // Common subexpression
    return compound_interest(principal * factor, rate, periods - 1);
}

// Function to test various edge cases
void test_edge_cases() {
    // Denormalized numbers
    double denorm = DBL_MIN / 2.0;
    printf("Denormalized number: %e\n", denorm);

    // NaN (Not-a-number) and Infinity
    double zero_div = 0.0;
    double nan_val = 0.0/zero_div;
    double inf_val = 1.0/zero_div;

    if (isnan(nan_val)) {
        printf("NaN detected.\n");
    }
    if (isinf(inf_val)) {
        printf("Infinity detected.\n");
    }

    // Underflow and Overflow
    double underflow = DBL_MIN / 1e308;
    double overflow = DBL_MAX * 1e308;
    printf("Underflow result: %e\n", underflow);
    printf("Overflow result: %e\n", overflow);
}

int main() {
    // Define fixed financial parameters
    double principal = 1000.0;
    double rate = 0.05;  // 5% annual interest rate
    int periods = 10;    // Compounded annually for 10 years

    // Calculate the compound interest recursively
    double final_amount = compound_interest(principal, rate, periods);
    printf("Final amount after %d periods is: %.2f\n", periods, final_amount);

    // Test edge cases
    test_edge_cases();

    return 0;
}
