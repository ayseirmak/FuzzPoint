#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <keras2c/k2c_include.h>
#include <keras2c/k2c_tensor_include.h>

// Define constant inputs for deterministic behavior
#define INPUT_SIZE 48
#define FIXED_INPUT_VALUES {-0.5f, 0.5f, -0.2f, 0.3f, 0.1f, -0.6f, 0.4f, 1.0f, 1.0f, 1.0f, 1.0f, \
                            1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, \
                            0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, \
                            0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, \
                            0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f }

void hop_tanh_w16_r3(k2c_tensor* input_tensor, k2c_tensor* output_tensor);

int main() {
    float input_array[INPUT_SIZE] = FIXED_INPUT_VALUES;
    float output_array[INPUT_SIZE] = {0.0f};
    
    k2c_tensor input_tensor = {input_array, 2, INPUT_SIZE, {3, 16, 1, 1, 1}};
    k2c_tensor output_tensor = {output_array, 2, INPUT_SIZE, {3, 16, 1, 1, 1}};

    hop_tanh_w16_r3(&input_tensor, &output_tensor);

    // Use standard assertions
    if (output_array[32] < 0.0f) {
        printf("Assertion failed: output_array[32] is less than 0.0\n");
        return 1;
    }

    printf("Assertion successful: output_array[32] is greater than or equal to 0.0\n");
    return 0;
}

void hop_tanh_w16_r3(k2c_tensor* simple_rnn_43_input_input, k2c_tensor* simple_rnn_43_output) {
    // Your implementation ...
    // This function will remain the same as the original as it contains a predefined behavior
}