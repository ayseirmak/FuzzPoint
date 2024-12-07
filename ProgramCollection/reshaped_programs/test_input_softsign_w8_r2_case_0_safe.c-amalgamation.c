#include <stdio.h>
#include <math.h>
#include <keras2c/k2c_include.h>
#include <hopfield_nets/softsign/w8/hop_softsign_w8_r2.h>

void hop_softsign_w8_r2(k2c_tensor* input, k2c_tensor* output);

int main() {
    // Initialize input and output arrays
    float input_array[16] = {0.0f};
    float output_array[16] = {0.0f};

    // Define the input and output tensors
    k2c_tensor input_tensor = {&input_array[0], 2, 16, {2, 8, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 16, {2, 8, 1, 1, 1}};

    // Deterministic input values
    input_array[0] = 0.5f;
    input_array[1] = -0.3f;
    input_array[2] = 0.1f;
    input_array[3] = 1.0f;
    input_array[4] = 1.0f;
    input_array[5] = 1.0f;
    input_array[6] = 1.0f;
    input_array[7] = 1.0f;

    // Apply the softsign function using the hopfield model
    hop_softsign_w8_r2(&input_tensor, &output_tensor);

    // Ensure output meets expectations
    if (isgreaterequal(output_array[8], 0.0f)) {
        printf("Output is correct: %f\n", output_array[8]);
    } else {
        printf("Output is incorrect: %f\n", output_array[8]);
    }

    return 0;
}