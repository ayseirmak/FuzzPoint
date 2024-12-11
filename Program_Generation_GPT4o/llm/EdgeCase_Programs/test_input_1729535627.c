
#include <stdio.h>
#include <math.h>
#include <fenv.h>

// Define constants using macros
#define REACTION_RATE_CONSTANT 1.0e-3
#define INITIAL_CONCENTRATION 1.0e3
#define TIME_STEP 1.0e-2
#define TOTAL_TIME 10.0

typedef struct {
    long double reactant_concentration;
    long double product_concentration;
    long double time;
} ReactionSystem;

// Function to update reaction system state
void update_reaction(ReactionSystem *system) {
    // Simple first-order decay reaction: A -> B
    // Rate of reaction: -d[A]/dt = k[A]
    long double reactant_change = REACTION_RATE_CONSTANT * system->reactant_concentration * TIME_STEP;
    system->reactant_concentration -= reactant_change;
    system->product_concentration += reactant_change;
    system->time += TIME_STEP;
}

// Function to simulate chemical reaction over time
void simulate_reaction() {
    ReactionSystem system = {INITIAL_CONCENTRATION, 0.0L, 0.0L};

    while (system.time < TOTAL_TIME) {
        update_reaction(&system);
    }

    printf("Final concentrations:");
    printf(" Reactant: %.9Lf", system.reactant_concentration);
    printf(" Product: %.9Lf\n", system.product_concentration);
}

// Function to demonstrate and test floating-point precision and edge cases
void floating_point_edge_cases() {
    float neg_zero = -0.0f;

    printf("Representing -0.0: %f\n", neg_zero);

    float small_value = 1.0e-38f;  // Very small number
    float large_value = 3.4e38f;   // Very large number

    printf("Multiplying small by large: %f\n", small_value * large_value);
    printf("Dividing large by small: %f\n", large_value / small_value);

    // Infinity arithmetic
    float inf = INFINITY;
    printf("Infinity times zero: %f\n", inf * 0.0f);
}

int main() {
    simulate_reaction();
    floating_point_edge_cases();

    return 0;
}
