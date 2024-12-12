
#include <stdio.h>
#include <math.h>
#include <float.h>

typedef struct {
    double weights[3];
    double bias;
} Neuron;

// Activation function (e.g., sigmoid or tanh)
double activate(double value) {
    if (isnan(value)) return 0.0;  // Example edge case: treating NaN as zero
    return tanh(value);  // Hyperbolic tangent activation function
}

// Compute the neuron output
double compute_neuron_output(Neuron* neuron, double inputs[3]) {
    double linear_combination = 0.0;

    // Calculating weighted sum
    for (int i = 0; i < 3; i++) {
        linear_combination += neuron->weights[i] * inputs[i];
    }
    linear_combination += neuron->bias;

    // Precision manipulation (handling denormalized numbers)
    if (fabs(linear_combination) < DBL_MIN) {
        linear_combination = copysign(0.0, linear_combination);
    }

    return activate(linear_combination);
}

// Evaluate a simple neural network
double evaluate_network(Neuron network[], int num_neurons, double inputs[3]) {
    double output = 0.0;

    for (int i = 0; i < num_neurons; i++) {
        double neuron_output = compute_neuron_output(&network[i], inputs);

        // Precision edge case: handling +/- infinity
        if (isinf(neuron_output)) {
            neuron_output = (neuron_output > 0) ? DBL_MAX : -DBL_MAX;
        }
        output += neuron_output;
    }
    return output;  // Can introduce custom scaling here if needed
}

int main() {
    // Example: Define a three-neuron network
    Neuron network[3] = {
        {{0.5, -0.3, 0.8}, 0.2},
        {{-0.7, 0.9, 0.3}, -0.1},
        {{0.2, -0.5, -0.6}, 0.4}
    };

    // Fixed input values for deterministic behavior
    double inputs[3] = {1.0, -1.0, 0.5};

    // Evaluate the network
    double output = evaluate_network(network, 3, inputs);

    // Edge case demonstration: NaN comparison
    double test_nan = output / 0.0;
    if (test_nan != test_nan) output = 0.0;  // Handle NaN case in evaluation

    // Edge case demonstration: Negative zero representation
    if (output == 0.0 && 1.0/output == -INFINITY) {
        output = 0.0;  // Resolve -0.0 to 0.0
    }

    // Cast the output to float for consistent precision
    float final_output = (float)output;

    return (final_output > 0) ? 1 : 0;
}
