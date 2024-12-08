#include <stdio.h>
#include <assert.h>
#include <stdint.h>

// Example deterministic input values
#define INPUT_0_0 -0.85f
#define INPUT_0_1 0.05f
#define INPUT_0_2 1.2f
#define INPUT_0_3 -0.35f
#define INPUT_0_4 -0.4f
#define INPUT_0_5 0.0f
#define INPUT_0_6 1.0f
#define INPUT_0_7 1.0f

void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main() {
    // Initialize inputs with deterministic values
    float tensor_input[1][8] = {{INPUT_0_0, INPUT_0_1, INPUT_0_2, INPUT_0_3, INPUT_0_4, INPUT_0_5, INPUT_0_6, INPUT_0_7}};
    float tensor_output[1][4];

    // Call the function
    entry(tensor_input, tensor_output);

    // Assert to check the specific condition
    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    // Print result for verification
    printf("Output tensor: %f, %f, %f, %f\n", tensor_output[0][0], tensor_output[0][1], tensor_output[0][2], tensor_output[0][3]);
    
    return 0;
}