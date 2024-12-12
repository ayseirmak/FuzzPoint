
#include <stdio.h>
#include <math.h>
#include <fenv.h>

// Structure to represent a simple Neuron with weights and bias
typedef struct {
    long double weights[3];
    long double bias;
} Neuron;

// Activation function (ReLU)
long double relu(long double z) {
    return fmaxl(0.0, z);
}

// Compute the output of a neuron for given input
long double neuron_output(Neuron neuron, long double inputs[3]) {
    long double sum = 0.0;

    // Pragma for loop unrolling optimization
    #pragma GCC optimize ("unroll-loops")
    for (int i = 0; i < 3; i++) {
        sum += neuron.weights[i] * inputs[i];
    }

    long double z = sum + neuron.bias;
    return relu(z);  // Apply ReLU activation
}

// Trigger floating-point exceptions by creating edge case operations
void edge_case_operations() {
    volatile long double small_value = 1.0e-308L;
    volatile long double large_value = 1.0e308L;
    volatile long double zero = 0.0L;
    volatile long double nan_value = NAN;

    volatile long double result;

    // Underflow example
    result = small_value / large_value;

    // Overflow example
    result = large_value * large_value;

    // Division by zero example
    result = small_value / zero;

    // NaN propagation example
    result = nan_value + 1.0L;
}

int main() {
    // Enable floating-point exceptions (handling)
    feenableexcept(FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW);

    // Define a neuron with some weights and a bias
    Neuron my_neuron = {
        {0.3L, -0.7L, 0.2L},  // weights
        0.1L                   // bias
    };

    // Example fixed inputs
    long double inputs[3] = {0.5L, -1.2L, 0.1L};

    // Compute neuron output
    long double output = neuron_output(my_neuron, inputs);
    printf("Neuron Output: %Lf\n", output);

    // Perform edge case floating-point operations
    edge_case_operations();

    return 0;
}
