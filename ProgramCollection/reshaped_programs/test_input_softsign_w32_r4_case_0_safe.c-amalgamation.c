#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <hopfield_nets/softsign/w32/hop_softsign_w32_r4.h>

int main()
{
    // Initialize input and output arrays to zero
    float input_array[128] = {0.0f}, output_array[128] = {0.0f};
    k2c_tensor input_tensor = {input_array, 2, 128, {4, 32, 1, 1, 1}};
    k2c_tensor output_tensor = {output_array, 2, 128, {4, 32, 1, 1, 1}};

    // Set fixed input values instead of nondeterministic ones
    input_array[0] = 0.5f;
    input_array[1] = -0.5f;
    input_array[2] = 0.25f;
    input_array[3] = -0.25f;
    input_array[4] = 0.75f;
    input_array[5] = -0.75f;
    input_array[6] = 0.1f;
    input_array[7] = -0.1f;
    input_array[8] = 0.9f;
    input_array[9] = -0.9f;
    input_array[10] = 0.33f;
    input_array[11] = -0.33f;
    input_array[12] = 0.7f;
    input_array[13] = -0.7f;
    input_array[14] = 0.55f;
    
    // Initialize input array with fixed values within the full input domain
    for(int i = 15; i < 32; i++) {
        input_array[i] = 1.0f;
    }

    // Invoke the hopfield softsign function
    hop_softsign_w32_r4(&input_tensor, &output_tensor);

    // Assert that a condition is met, equivalent to the verification assertion
    assert(output_array[126] >= 0.0f);
    printf("Assertion passed. Output value at index 126 is: %f\n", output_array[126]);

    return 0;
}