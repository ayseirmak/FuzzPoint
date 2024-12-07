#include <math.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <keras2c/k2c_include.h>
#include <hopfield_nets/tanh/w32/hop_tanh_w32_r4.h>

// Hard-coded deterministic inputs
const float DETERMINISTIC_INPUTS[15] = {
    0.1f, -0.9f, 0.5f, 0.7f, -0.5f, 0.3f, -0.2f, 0.4f, 0.6f, -0.4f,
    0.2f, -0.6f, 0.3f, 0.7f, -0.5f
};

int main() {
    float input_array[128] = {0.0f};
    float output_array[128] = {0.0f};

    k2c_tensor input_tensor = {&input_array[0], 2, 128, {4, 32, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 128, {4, 32, 1, 1, 1}};

    // Initialize specific elements of the input array
    for (int i = 0; i < 15; i++) {
        input_array[i] = DETERMINISTIC_INPUTS[i];
    }

    for (int i = 15; i < 32; i++) {
        input_array[i] = 1.0f;
    }

    // Validate assumptions with assertions
    for (int i = 0; i < 15; i++) {
        assert(input_array[i] >= -1.0f && input_array[i] <= 1.0f);
    }

    // Process the input with the hopfield network
    hop_tanh_w32_r4(&input_tensor, &output_tensor);

    // Assert the expected result
    assert(isgreaterequal(output_array[126], 0.0f));

    printf("Assertion passed. Output value at index 126 is greater than or equal to 0.0f.\n");
    
    return 0;
}