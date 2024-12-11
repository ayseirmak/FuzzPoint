
#include <stdio.h>
#include <math.h>
#include <fenv.h>
#include <float.h>

// Simple Machine Learning model structure
typedef struct {
    long double weight; // Model weight
    double learning_rate; // Learning rate for gradient updates
} Model;

// Function to update the model using gradient descent
void update_model(Model* model, int iterations) {
    const double initial_weight = 0.5;
    const double grad_factor = 0.002;

    // Set different rounding modes
    fesetround(FE_TONEAREST);  // Round to nearest

    for (int i = 0; i < iterations; i++) {
        // Simulate gradient calculation (negative gradient)
        long double gradient = -grad_factor * model->weight;

        // Update the weight using various types and handle rounding modes
        if (i % 3 == 0) {
            // Round toward zero
            fesetround(FE_TOWARDZERO);
            model->weight += (long double)((float)gradient);
        } else if (i % 3 == 1) {
            // Round toward infinity
            fesetround(FE_UPWARD);
            model->weight += (double)gradient;
        } else {
            // Round to nearest
            fesetround(FE_TONEAREST);
            model->weight += gradient;
        }

        // Ensure we return to round-to-nearest after the operation
        fesetround(FE_TONEAREST);

        // Prevent underflow and gradual underflow
        if (fabsl(model->weight) < LDBL_MIN) {
            model->weight = LDBL_MIN;
        }

        // Simulate precision loss through repetitive small updates
        for (int j = 0; j < 5; j++) {
            model->weight += powl(1e-16L * initial_weight, 2);
            model->weight -= 1e-16L * initial_weight;
        }
    }
}

int main() {
    // Initialize the model with a specific weight and learning rate
    Model model = {
        1.0L,    // Initial weight
        0.1      // Learning rate
    };

    // Perform model updates over a fixed number of iterations
    update_model(&model, 1000);

    // Evaluate model success with a threshold
    int result = (fabsl(model.weight) < 0.2L) ? 1 : 0;

    return result;
}
