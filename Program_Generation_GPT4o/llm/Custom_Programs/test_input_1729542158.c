
#include <stdio.h>
#include <math.h>
#include <fenv.h>

// Function to calculate gravitational forces between two bodies
double calculate_gravitational_force(double mass1, double mass2, double distance) {
    const double G = 6.67430e-11;  // Gravitational constant
    if (distance == 0) return INFINITY;  // Handle division by zero
    return G * ((mass1 * mass2) / (distance * distance));
}

// Calculate lift coefficient using a Mach number (simplified)
double calculate_lift_coefficient(double mach_number) {
    return mach_number < 1 ? 0.5 : 0.3;  // Simplified linear approximation
}

// Example of operations triggering floating-point exceptions
void perform_critical_operation() {
    volatile double small_value = 1.0e-308;
    volatile double large_value = 1.0e308;
    volatile double zero = 0.0;
    volatile double result;
    
    // Underflow example
    result = small_value / large_value;

    // Overflow example
    result = large_value * large_value;

    // Division by zero example
    result = small_value / zero;
}

int main() {
    // Enable floating-point exceptions (handling)
    feenableexcept(FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW);

    // Example input values (fixed and predefined)
    double mass1 = 1000;  // Mass of the first body in kg
    double mass2 = 500;   // Mass of the second body in kg
    double distance = 10; // Distance between the bodies in meters

    // Calculating gravitational force between two masses
    double force = calculate_gravitational_force(mass1, mass2, distance);
    printf("Gravitational Force: %e N\n", force);

    // Calculate lift coefficient at a given Mach number
    double mach_number = 1.2;
    double lift_coefficient = calculate_lift_coefficient(mach_number);
    printf("Lift Coefficient (Mach %f): %f\n", mach_number, lift_coefficient);

    // Perform operations that handle floating-point exceptions
    perform_critical_operation();

    return 0;
}
