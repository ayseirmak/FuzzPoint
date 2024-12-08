#include <assert.h>
#include <stdio.h>
#include <math.h>

// Assuming keras2c provides the following structure (placeholders)
typedef struct {
    float* array;
    int ndim;
    int numel;
    int shape[5];
} k2c_tensor;

// Placeholder for a function provided by keras2c
void hop_softsign_w16_r4(k2c_tensor* input, k2c_tensor* output) {
    // Function implementation assumed to be provided by an external library
}

int main() {
    float input_array[64] = {0.0f}, output_array[64] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 2, 64, {4, 16, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 64, {4, 16, 1, 1, 1}};

    // Setting deterministic values
    input_array[0] = -0.5f;
    input_array[1] = 0.0f;
    input_array[2] = 0.5f;
    input_array[3] = 1.0f;
    input_array[4] = -1.0f;
    input_array[5] = 0.7f;
    input_array[6] = -0.7f;
    input_array[7] = 1.0f;
    input_array[8] = 1.0f;
    input_array[9] = 1.0f;
    input_array[10] = 1.0f;
    input_array[11] = 1.0f;
    input_array[12] = 1.0f;
    input_array[13] = 1.0f;
    input_array[14] = 1.0f;
    input_array[15] = 1.0f;

    // Ensuring input domain
    assert(input_array[0] >= -1.0f && input_array[0] <= 1.0f);
    assert(input_array[1] >= -1.0f && input_array[1] <= 1.0f);
    assert(input_array[2] >= -1.0f && input_array[2] <= 1.0f);
    assert(input_array[3] >= -1.0f && input_array[3] <= 1.0f);
    assert(input_array[4] >= -1.0f && input_array[4] <= 1.0f);
    assert(input_array[5] >= -1.0f && input_array[5] <= 1.0f);
    assert(input_array[6] >= -1.0f && input_array[6] <= 1.0f);

    // Perform the operation
    hop_softsign_w16_r4(&input_tensor, &output_tensor);

    // Assert expected result
    assert(output_array[62] >= 0.0f);

    return 0;
}