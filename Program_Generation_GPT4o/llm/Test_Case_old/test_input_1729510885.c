
#include <stdio.h>
#include <math.h>
#include <fenv.h>

// Model a simple climate system where temperature is influenced by greenhouse gas concentration
double calculate_temperature(double GH_concentration);
void handle_edge_cases();

int main() {
    // Fixed atmospheric greenhouse gas concentration values (in parts per million)
    double GH_concentration[] = {400.0, 450.0, 500.0, 550.0, 600.0}; 

    // Calculate and print the estimated temperature for each concentration
    for (int i = 0; i < 5; ++i) {
        double temperature = calculate_temperature(GH_concentration[i]);
        printf("For GH concentration %f ppm, estimated temperature: %f°C\n", GH_concentration[i], temperature);
    }

    // Handle and demonstrate floating-point edge cases
    handle_edge_cases();

    return 0;
}

// Function to calculate temperature based on a simplified climate model
double calculate_temperature(double GH_concentration) {
    // Applying a simplified linear model for demonstration purposes
    // The concentration is divided by a constant factor; the division can be optimized by GCC
    volatile double rate_factor = 0.03; // Simplified impact factor per ppm
    return 15.0 + (GH_concentration - 280.0) * rate_factor; // 15°C is a base temperature
}

// Function to handle and print edge cases with denormalized numbers, NaN, and infinities
void handle_edge_cases() {
    // Enable floating-point exceptions
    feclearexcept(FE_ALL_EXCEPT);
    
    // Example of generating NaN
    double zero = 0.0;
    double nan_result = zero / zero;

    // Example of generating infinity
    double inf_result = 1.0 / zero;
    double neg_inf_result = -1.0 / zero;

    // Denormalized number example: very small value
    volatile double denormalized = DBL_MIN / 2.0;
    
    // Print the results
    printf("NaN result: %f, Is NaN: %d\n", nan_result, isnan(nan_result));
    printf("Positive Infinity: %f, Negative Infinity: %f\n", inf_result, neg_inf_result);
    printf("Denormalized number: %e\n", denormalized);

    // Check for floating-point exceptions
    if (fetestexcept(FE_INVALID)) {
        printf("Invalid operation detected!\n");
    }
    if (fetestexcept(FE_DIVBYZERO)) {
        printf("Division by zero detected!\n");
    }
    if (fetestexcept(FE_OVERFLOW)) {
        printf("Overflow detected!\n");
    }
    if (fetestexcept(FE_UNDERFLOW)) {
        printf("Underflow detected!\n");
    }
}
