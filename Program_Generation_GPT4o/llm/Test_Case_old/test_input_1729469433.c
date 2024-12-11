
#include <stdio.h>
#include <math.h>

// Function to calculate deflection and stress in a structural element
typedef struct {
    double length;
    double force;
    double elasticity;
    double moment_of_inertia;
} Beam;

double calculate_deflection(Beam beam, double position) {
    // Formula: δ = (F * x^2 * (3L - x)) / (6 * E * I)
    return (beam.force * pow(position, 2) * (3 * beam.length - position)) / (6 * beam.elasticity * beam.moment_of_inertia);
}

double calculate_stress(Beam beam, double position) {
    // Formula: σ = (M * c) / I where M = F * L with max c (outer fiber)
    double moment = beam.force * beam.length;
    double c = beam.length / 2;
    return (moment * c) / beam.moment_of_inertia;
}

// Reciprocal transformation example
double optimized_reciprocal(double value) {
    return 1.0 / value;
}

int main() {
    // Example beam with fixed inputs
    Beam beam = {10.0, 1000.0, 200000.0, 0.005};

    // Evaluate deflection and stress at mid-point
    double midpoint_position = beam.length / 2;
    double deflection = calculate_deflection(beam, midpoint_position);
    double stress = calculate_stress(beam, midpoint_position);

    // Perform some mathematical operations
    double angle_rad = M_PI / 4; // 45 degrees in radians
    double sine_val = sin(angle_rad);
    double cosine_val = cos(angle_rad);
    double exponential_val = exp(-stress / 1000.0);

    printf("Deflection at midpoint: %f mm\n", deflection);
    printf("Stress at midpoint: %f N/mm^2\n", stress);
    printf("Sine(45°): %f\n", sine_val);
    printf("Cosine(45°): %f\n", cosine_val);
    printf("Exponential(-stress/1000): %f\n", exponential_val);

    // Demonstrate reciprocal transformation
    double reciprocal_deflection = optimized_reciprocal(deflection);
    printf("Reciprocal of deflection: %f\n", reciprocal_deflection);

    return 0;
}
