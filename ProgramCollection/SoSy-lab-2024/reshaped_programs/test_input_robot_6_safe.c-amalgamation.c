#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

// Declare necessary functions and constants upfront
void entry(const float tensor_input[1][5], float tensor_output[1][5]);

int main()
{
    // Fixed input tensor with deterministic values within allowed range
    float tensor_input[1][5] = {
         {-1.5f, -1.5f, 0.5f, 1.25f, 1.5f}
    };
    
    // Output tensor initialized to zero
    float tensor_output[1][5] = {{0}};
    
    // Perform model execution
    entry(tensor_input, tensor_output);
    
    // Replace __VERIFIER_assert with standard assertion and check condition is true
    assert(!((tensor_output[0][1] <= 0.04106493029448468) &&
             (tensor_output[0][1] >= -0.04106493029448468) &&
             (tensor_output[0][2] <= 0.04106493029448468) &&
             (tensor_output[0][2] >= -0.04106493029448468) &&
             (tensor_output[0][0] >= 0.23104722700813274)));
    
    // Print output for verification purpose
    printf("Output Tensor: [ %f, %f, %f, %f, %f ]\n", tensor_output[0][0], tensor_output[0][1], tensor_output[0][2], tensor_output[0][3], tensor_output[0][4]);
    return 0;
}

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Define constants
#define MAX(X,Y) ( (X) > (Y) ? (X) : (Y) )
#define MIN(X,Y) ( (X) < (Y) ? (X) : (Y) )
#define CLIP(X,L) ( MAX(MIN(X,L), -L) )

// Include specific weight and bias matrices defined earlier
// Add the model implementation functions
// Example: node_Gemm_0, node_Relu_1, etc. as defined before

// The content of the 'entry()' function from the original program should be placed here with the necessary includes

void entry(const float tensor_input[1][5], float tensor_output[1][5]) {
    // Insert the implementation of the series of model function calls
    // This includes node_Gemm_0, node_Relu_1, and so on, as defined in the original code
    // Implement each function based on the inline functions detailing how each node processes the inputs
}