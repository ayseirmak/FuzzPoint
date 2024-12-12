
#include <stdio.h>
#include <math.h>
#include <float.h>

// Inline function to calculate compound interest
inline double calculate_compound_interest(double principal, double rate, int years) {
    return principal * pow(1 + rate, years);
}

// Inline function to calculate net present value of future cash flows
inline double calculate_npv(double cash_flows[], int num_flows, double discount_rate) {
    double npv = 0.0;
    for (int t = 0; t < num_flows; t++) {
        npv += cash_flows[t] / pow(1 + discount_rate, t + 1);
    }
    return npv;
}

// Function to perform floating-point comparison with epsilon
int compare_floating_points(double a, double b, double epsilon) {
    return fabs(a - b) < epsilon;
}

int main() {
    // Scenario: Calculate compound interest on an investment
    double principal = 1000.0;
    double annual_rate = 0.05;
    int years = 10;
    double future_value = calculate_compound_interest(principal, annual_rate, years);
    
    // Scenario: Calculate NPV of a series of cash flows
    double cash_flows[] = {100.0, 200.0, 300.0, 400.0, 500.0};
    int num_cash_flows = sizeof(cash_flows) / sizeof(cash_flows[0]);
    double discount_rate = 0.04;
    double npv = calculate_npv(cash_flows, num_cash_flows, discount_rate);

    // Perform comparisons with floating-point epsilon to handle precision limits
    double epsilon = 1e-9;
    double target_value = 200.0;
    int comparison_result = compare_floating_points(future_value, target_value, epsilon);

    // Output (minimal)
    printf("Future Value of Investment: %.9f\n", future_value);
    printf("Net Present Value of Cash Flows: %.9f\n", npv);
    printf("Future Value close to Target Value (200): %s\n", comparison_result ? "Yes" : "No");

    return 0;
}
