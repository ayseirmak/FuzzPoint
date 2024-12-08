#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define CLIP(X, L) (MAX(MIN((X), (L)), -(L)))

void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main() {
    float tensor_input[1][8];
    float tensor_output[1][4];

    // Deterministic inputs replacing nondeterministic behavior
    tensor_input[0][0] = -0.85f;
    tensor_input[0][1] = 0.0f;
    tensor_input[0][2] = 0.0f;
    tensor_input[0][3] = 0.06f;
    tensor_input[0][4] = -0.35f;
    tensor_input[0][5] = 0.01f;
    tensor_input[0][6] = 1.0f;
    tensor_input[0][7] = 0.0f;

    // Manual assumptions based on the given ranges
    assert(tensor_input[0][0] >= -0.8582691990432433f && tensor_input[0][0] <= -0.7844292009567567f);
    assert(tensor_input[0][1] >= -0.019623174043243274f && tensor_input[0][1] <= 0.05421682404324327f);
    assert(tensor_input[0][2] >= -0.014536076043243272f && tensor_input[0][2] <= 0.05930392204324327f);
    assert(tensor_input[0][3] >= 0.02294316595675673f && tensor_input[0][3] <= 0.09678316404324327f);
    assert(tensor_input[0][4] >= -0.3752377790432433f && tensor_input[0][4] <= -0.30139778095675673f);
    assert(tensor_input[0][5] >= -0.02960876904324327f && tensor_input[0][5] <= 0.044231229043243274f);
    assert(tensor_input[0][6] >= 0.9630800009567567f && tensor_input[0][6] <= 1.0369199990432432f);
    assert(tensor_input[0][7] >= -0.03691999904324327f && tensor_input[0][7] <= 0.03691999904324327f);

    entry(tensor_input, tensor_output);

    // Verify the output constraint
    assert(!(tensor_output[0][3] <= tensor_output[0][2]));

    return 0;
}