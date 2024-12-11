
#include <stdio.h>
#include <math.h>
#include <float.h>

// Macros for constant values
#define GRAVITY 9.81L
#define SMALL_FORCE 1.0e-300L

// Structure to represent a mechanical component
typedef struct {
    long double force;      // Force applied in Newton
    long double area;       // Cross-sectional area in square meters
} MechanicalComponent;

// Function to simulate stress calculations with potential underflow
void calculate_stress(MechanicalComponent* component) {
    // The stress is force per unit area
    if (component->area == 0.0L) {
        printf("Division by zero in stress computation.\n");
        return;
    }
    
    long double stress = component->force / component->area;

    if (stress == -0.0L) {
        printf("Stress resulted in representation of -0.0\n");
    } else if (fpclassify(stress) == FP_SUBNORMAL) {
        printf("Stress resulted in a subnormal value: %.10Le\n", stress);
    } else {
        printf("Computed Stress: %.10Le\n", stress);
    }
}

// Recursive function to simulate gradual underflow conditions
void recursive_underflow(MechanicalComponent* component, int currentDepth, int maxDepth) {
    if (currentDepth >= maxDepth) {
        return;
    }

    component->force *= SMALL_FORCE; // Operation causing potential underflow
    
    if (fpclassify(component->force) == FP_SUBNORMAL) {
        printf("Force became subnormal at iteration %d\n", currentDepth);
    }

    calculate_stress(component);

    // Recurse to the next depth
    recursive_underflow(component, currentDepth + 1, maxDepth);
}

// Function to demonstrate the casting of values
void casting_demo(MechanicalComponent* component) {
    float force_float = (float)component->force;
    double area_double = (double)component->area;
    long long area_ll = (long long)component->area;

    printf("Casting Demonstration:\n");
    printf("Force as float: %.8e\n", force_float);
    printf("Area as double: %.10e\n", area_double);
    printf("Area as long long: %lld\n", area_ll);
}

int main() {
    // Initialize a mechanical component with arbitrary values
    MechanicalComponent component = {SMALL_FORCE, 1.0L};  // Using a very small force to trigger underflow

    printf("Initial Mechanical Component State: (Force: %.10Le, Area: %.10Le)\n", component.force, component.area);

    // Apply recursive underflow simulation
    recursive_underflow(&component, 0, 5);

    // Demonstrate casting between types
    casting_demo(&component);

    return 0;
}
