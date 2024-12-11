
#include <stdio.h>
#include <math.h>

// Function to compute compound interest with periodic contributions
double compute_future_value(double principal, double rate, int periods, double contribution) {
    double future_value = principal;
    
    for (int i = 0; i < periods; ++i) {
        future_value += contribution; // Add the periodic contribution
        future_value *= (1 + rate);   // Apply interest
    }
    
    return future_value;
}

int main() {
    double initial_investment = 10000.0;   // Initial investment in dollars
    double annual_rate = 0.05;             // Annual interest rate (5%)
    double monthly_rate = pow(1 + annual_rate, 1.0/12) - 1; // Convert to monthly rate
    int total_months = 120;                // Investment period in months (10 years)
    double monthly_contribution = 100.0;   // Monthly contribution in dollars

    double final_value = compute_future_value(initial_investment, monthly_rate, total_months, monthly_contribution);

    printf("The future value of the investment is: $%.2f\n", final_value);

    return 0;
}
