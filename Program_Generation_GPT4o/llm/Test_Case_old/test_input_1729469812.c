
#include <stdio.h>
#include <math.h>
#include <float.h>

// Function to compute some material property using a hypothetical model
double material_property_model(double density, double elasticity, double temperature) {
    // Hypothetical complex calculation involving floating-point operations
    double result = density * elasticity / temperature;
    // Trigger Reduction of Floating-Point Error by associating terms carefully
    result += (elasticity * 1.0e-9) - (density * 1.0e-9);
    return result;
}

// Test edge cases: Underflow and Overflow
void test_underflow_overflow() {
    double underflow_value = 1.0e-300 * 1.0e-300; // May result in underflow
    double overflow_value = 1.0e+300 * 1.0e+300;  // May result in overflow

    if (underflow_value == 0.0) {
        printf("Underflow detected: %e\n", underflow_value);
    } else {
        printf("No Underflow: %e\n", underflow_value);
    }

    if (overflow_value == INFINITY) {
        printf("Overflow detected: %e\n", overflow_value);
    } else {
        printf("No Overflow: %e\n", overflow_value);
    }
}

int main() {
    // Fixed inputs for the material property model
    double density = 2.8;        // e.g., Aluminum density in g/cm^3
    double elasticity = 70.0e9;  // Young's modulus in Pascals for Aluminum
    double temperature = 300.0;  // Room temperature in Kelvin

    double property = material_property_model(density, elasticity, temperature);
    printf("Material property result: %f\n", property);

    // Run tests for underflow and overflow
    test_underflow_overflow();

    return 0;
}
