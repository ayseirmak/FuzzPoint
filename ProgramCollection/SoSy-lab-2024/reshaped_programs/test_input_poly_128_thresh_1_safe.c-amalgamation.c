#include <stdio.h>
#include <math.h>

// Assuming k2c_tensor and poly_128 are defined elsewhere
typedef struct {
    float* array;
    int ndim;
    int numel;
    int shape[5];
} k2c_tensor;

void poly_128(k2c_tensor* input, k2c_tensor* output);

#define ASSERT(expr, msg) if (!(expr)) { printf("Assertion failed: %s\n", msg); return 1; }

int main() {
    // Fixed input value instead of nondeterministic input
    float x = 2.95f; 

    /* Neural net input and output */
    float input_array[1] = { x }, output_array[1] = { 0.0f };
    k2c_tensor input_tensor = { input_array, 1, 1, {1, 1, 1, 1, 1} };
    k2c_tensor output_tensor = { output_array, 1, 1, {1, 1, 1, 1, 1} };

    /* Call the neural network with fixed input */
    poly_128(&input_tensor, &output_tensor);

    /* Compare the network output with an affine approximation of the ground truth */
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    /* Assertion with fixed parameters */
    ASSERT(diff <= 0.41700377912541751927896850769056f, "Verification unsuccessful");

    printf("Output verified successfully!\n");
    return 0;
}

void poly_128(k2c_tensor* input, k2c_tensor* output) {
    // Placeholder for poly_128 logic
    // Assuming a direct mapping for simplification in this fragment
    output->array[0] = input->array[0];  // Mock operation
}

// Additional functions would go here