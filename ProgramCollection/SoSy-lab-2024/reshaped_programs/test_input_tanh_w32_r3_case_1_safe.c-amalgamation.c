#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <keras2c/k2c_include.h>
#include <keras2c/k2c_tensor_include.h>
#include <keras2c/k2c_recurrent_layers.h>

// Example function that calculates output using hop_tanh_w32_r3
void hop_tanh_w32_r3(k2c_tensor* input_tensor, k2c_tensor* output_tensor);

int main() {
    // Initialize with deterministic values for testing
    
    float input_array[96] = {
        0.5f, 0.3f, -0.7f, 0.1f, -0.6f, 0.8f, -0.5f, 0.9f, 
        -0.3f, 0.7f, 0.2f, -0.1f, 0.4f, -0.8f, 1.0f, 
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f
        // rest are initialized to zero by default
    };
    float output_array[96] = {0.0f};

    k2c_tensor input_tensor = {input_array, 2, 96, {3, 32, 1, 1, 1}};
    k2c_tensor output_tensor = {output_array, 2, 96, {3, 32, 1, 1, 1}};

    // Ensure assumption within the domain
    for (int i = 0; i < 15; ++i) {
        assert(input_array[i] >= -1.0f && input_array[i] <= 1.0f);
    }

    // Call the model function
    hop_tanh_w32_r3(&input_tensor, &output_tensor);

    // Verify the expected output element
    assert(output_array[65] == 1.0f);

    printf("All assertions passed and the program executed successfully.\n");
    return 0;
}