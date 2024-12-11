
#include <stdio.h>
#include <math.h>

// Function to calculate bending stress in a beam using standard mechanics formula
double calculate_bending_stress(double moment, double section_modulus) {
    return moment / section_modulus;  // Bending stress = Moment / Section Modulus
}

// Function to perform a variety of floating-point arithmetic operations
void floating_point_operations(double a, double b) {
    double addition = a + b;
    double subtraction = a - b;
    double multiplication = a * b;
    double division = b != 0 ? a / b : 0.0;  // Avoid division by zero
    double modulus = fmod(a, b);  // Floating-point modulus

    printf("Addition: %f\n", addition);
    printf("Subtraction: %f\n", subtraction);
    printf("Multiplication: %f\n", multiplication);
    printf("Division: %f\n", division);
    printf("Modulus: %f\n", modulus);
}

int main() {
    // Fixed values for bending stress calculations and other computations
    double moment = 5000.0;  // Moment in Nm
    double section_modulus = 200.0;  // Section modulus in mm^3

    // Floating-point arithmetic values
    double a = 42.5;
    double b = 7.3;

    // Calculate Bending Stress
    double bending_stress = calculate_bending_stress(moment, section_modulus);
    printf("Bending Stress: %f\n", bending_stress);

    // Explore various floating-point operations
    floating_point_operations(a, b);

    // Fixed Floating-Point Computations (Trigger Constant Folding)
    double c = 3.14159265358979323846;  // Pi
    double d = 2.71828182845904523536;  // e
    double e = c * d;  // Constant folding: Pi * e
    printf("Pi * e (Constant Folding): %f\n", e);

    return 0;
}
