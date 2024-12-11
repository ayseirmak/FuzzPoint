
#include <stdio.h>
#include <math.h>
#include <float.h>

// Structure to represent material properties
typedef struct {
    double initial_length;  // Initial length of the material (in meters)
    double thermal_expansion_coefficient;  // Coefficient of thermal expansion
    double max_temperature;  // Maximum temperature (in Kelvin) for simulations
} Material;

// Recursive function to compute final length after thermal expansion
double compute_expansion(Material* mat, double current_temperature) {
    // Base case: Stop recursive calculations if temperature exceeds max_temperature
    if (current_temperature > mat->max_temperature) {
        return mat->initial_length;
    }

    // Calculate expansion due to one degree increase
    double expansion = mat->initial_length * mat->thermal_expansion_coefficient * current_temperature;

    // Handle potential overflow and special floating-point cases
    if (expansion > DBL_MAX) {
        expansion = DBL_MAX;
    } else if (isnan(expansion) || isinf(expansion)) {
        expansion = mat->initial_length;
    }

    // Recursive call and type casting to control further calculations
    double final_length = compute_expansion(mat, current_temperature + 1.0);

    // Adjust the length incrementally and cast to double for precision adjustment
    return (double)(expansion + final_length);
}

// Function to handle specific edge cases around floating-point anomalies
void manage_floating_point_cases(Material* mat, double expansion) {
    // Handle subnormal numbers by setting a lower bound
    if (fabs(expansion) < DBL_MIN) {
        expansion = DBL_MIN;
    }

    // Manage negative or extreme lengths
    if (expansion < 0 || isinf(expansion)) {
        expansion = mat->initial_length;
    }
}

int main() {
    // Define material properties (example: steel)
    Material steel = {
        1.0,        // Initial length in meters
        1.2e-5,     // Coefficient of thermal expansion (per Kelvin)
        1000.0      // Maximum simulation temperature in Kelvin
    };

    // Compute final expansion using recursive technique
    double final_length = compute_expansion(&steel, 0.0); // Start at 0 Kelvin

    // Handle edge cases for the computed expansion
    manage_floating_point_cases(&steel, final_length);

    // Result evaluates if the final length is reasonably expanded within limits
    int result = ((final_length - steel.initial_length) < (steel.initial_length * 0.05)) ? 1 : 0;

    return result;
}
