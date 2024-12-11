
#include <stdio.h>
#include <math.h>
#include <fenv.h>

// Function to simulate mechanical stress behavior in a component
double compute_stress(double force, double area) {
    return force / area;  // Stress = Force / Area
}

// Function to estimate mechanical fatigue based on some complex model
double estimate_fatigue_life(double stress, double endurance_limit) {
    double life = 1.0e6 / pow(stress / endurance_limit, 2.0);  // Hypothetical fatigue life formula
    return life;
}

// Function to demonstrate conditional statements with floating-point comparisons
void evaluate_safety(double stress, double yield_strength) {
    if (stress > yield_strength) {
        printf("Warning: Stress exceeds yield strength! %f > %f\n", stress, yield_strength);
    } else {
        printf("Safe: Stress is within yield strength. %f <= %f\n", stress, yield_strength);
    }
}

int main() {
    // Fixed inputs for stress calculation
    double force = 1000.0;         // Force in Newtons
    double area = 0.005;           // Area in square meters
    double yield_strength = 250.0; // Material yield strength in MPa
    double endurance_limit = 150.0; // Endurance limit in MPa

    fenv_t fenv; // To change rounding mode
    fegetenv(&fenv);
    // Temporarily set rounding mode to upward for demonstration
    fesetround(FE_UPWARD);

    double stress = compute_stress(force, area);
    evaluate_safety(stress, yield_strength);

    // Reset rounding mode to default
    fesetenv(&fenv);

    double fatigue_life = estimate_fatigue_life(stress, endurance_limit);
    printf("Estimated fatigue life: %f cycles\n", fatigue_life);

    return 0;
}
