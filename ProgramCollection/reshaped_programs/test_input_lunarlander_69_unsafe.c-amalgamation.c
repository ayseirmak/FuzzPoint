#include <stdio.h>
#include <math.h>
#include <assert.h>

// Function prototypes
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main() {
    // Initialize input and output tensors
    float tensor_input[1][8] = {
        {-0.75f, 0.07f, 0.02f, 3.5f, 0.07f, -0.04f, 1.0f, 1.0f}
    };
    float tensor_output[1][4] = {0};

    // Call the entry function
    entry(tensor_input, tensor_output);

    // Assert condition must be checked that was previously verified by __VERIFIER_assert
    // The Verifier assertion to be checked
    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    // If everything is fine
    printf("Program executed successfully.\n");

    return 0;
}

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

// Define MAX, MIN, and CLIP macros
#define MAX(X,Y) ( X > Y ? X : Y)
#define MIN(X,Y) ( X < Y ? X : Y)
#define CLIP(X,L) ( MAX(MIN(X,L), -L) )

// Add function definitions and required computations here from the original code.