
#include <stdio.h>
#include <fenv.h>
#include <math.h>

// Enable floating-point exceptions
#pragma STDC FENV_ACCESS ON

// Function to model material stress calculations
// Includes handling of floating-point exceptions
double calculate_stress(double force, double area) {
    fesetenv(FE_DFL_ENV);  // Set default floating-point environment
    feclearexcept(FE_ALL_EXCEPT);  // Clear all exceptions

    if (area == 0.0) {
        feraiseexcept(FE_DIVBYZERO);  // Manually raise divide by zero error
        return INFINITY;
    }

    double stress = force / area;

    // Check any floating-point exceptions
    if (fetestexcept(FE_DIVBYZERO)) {
        printf("Division by zero encountered!\n");
    }
    if (fetestexcept(FE_OVERFLOW)) {
        printf("Overflow encountered!\n");
    }
    if (fetestexcept(FE_UNDERFLOW)) {
        printf("Underflow encountered!\n");
    }

    return stress;
}

int main() {
    // Simulate forces and cross-sectional area
    double force = 1e308;  // Large magnitude force, potential overflow source
    double area_under = 1e-308;  // Very small area, potential underflow source
    double area_zero = 0.0;  // Zero area, definite division by zero

    printf("Stress calculation results (with floating-point exception handling):\n");

    // Calculate stress for underflow scenario
    double stress_under = calculate_stress(force, area_under);
    printf("Stress (potential underflow): %e\n", stress_under);

    // Calculate stress for division by zero scenario
    double stress_zero = calculate_stress(force, area_zero);
    printf("Stress (division by zero): %e\n", stress_zero);

    return 0;
}
