#include <stdio.h>
#include <math.h>
#include <keras2c/k2c_include.h>
#include <hopfield_nets/tanh/w16/hop_tanh_w16_r2.h>
#include <assert.h>

int main() {
    // Initialize input and output arrays with fixed values
    float input_array[32] = {0.5f, -0.5f, 0.1f, -0.1f, 0.05f, -0.05f, 0.2f, 1.0f, 
                             1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 
                             0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 
                             0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    float output_array[32] = {0.0f};

    // Define tensors using input and output arrays
    k2c_tensor input_tensor = {&input_array[0], 2, 32, {2, 16, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 32, {2, 16, 1, 1, 1}};

    // Process the tensors
    hop_tanh_w16_r2(&input_tensor, &output_tensor);

    // Assert the output value
    assert(isgreaterequal(output_array[17], 0.91f) && "Verification failed");

    printf("Execution completed. Verification %s.\n",
           isgreaterequal(output_array[17], 0.91f) ? "passed" : "failed");

    return 0;
}