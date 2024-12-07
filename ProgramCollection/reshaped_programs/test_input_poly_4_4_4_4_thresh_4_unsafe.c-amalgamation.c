#include <stdio.h>
#include <math.h>
#include <keras2c/k2c_include.h>

// Mock include for compatibility
#include <keras2c/k2c_tensor_include.h>

// Definitions from the keras2c library are assumed to exist

void poly_4_4_4_4(k2c_tensor* dense_142_input_input, k2c_tensor* dense_146_output);

int main() {
    // Fixed deterministic input
    float x = 2.95f; // Replace with a fixed value within the desired range
    
    // Neural net input and output
    float input_array[1] = {x}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0],1,1,{1,1,1,1,1}};
    k2c_tensor output_tensor = {&output_array[0],1,1,{1,1,1,1,1}};
    
    // Call the neural network
    poly_4_4_4_4(&input_tensor, &output_tensor);
    
    // Compare the network output with an affine approximation of the ground truth
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);
    
    // Assert condition
    if (islessequal(diff, 0.05844081983014954248717610467037f)) {
        printf("Verification succeeded.\n");
    } else {
        printf("Verification failed.\n");
    }
    
    return 0;
}

void poly_4_4_4_4(k2c_tensor* input, k2c_tensor* output) {
    float dense_142_output_array[4] = {0}; 
    k2c_tensor dense_142_output = {&dense_142_output_array[0],1,4,{4,1,1,1,1}}; 
    float dense_142_kernel_array[4] = {
        +5.48384368e-01f, -4.03225034e-01f, -8.22424889e-01f, -4.27254468e-01f
    }; 
    k2c_tensor dense_142_kernel = {&dense_142_kernel_array[0],2,4,{1,4,1,1,1}}; 
    float dense_142_bias_array[4] = {
        -1.83425963e-01f, -5.64127147e-01f, -2.63909972e-03f, +1.38429180e-01f
    }; 
    k2c_tensor dense_142_bias = {&dense_142_bias_array[0],1,4,{4,1,1,1,1}}; 
    float dense_142_fwork[5] = {0};

    // Other layers similar as above
  
    float dense_146_kernel_array[4] = {
        -8.94736111e-01f, -5.19859433e-01f, -1.59474289e+00f, +1.54181862e+00f
    }; 
    k2c_tensor dense_146_kernel = {&dense_146_kernel_array[0],2,4,{4,1,1,1,1}}; 
    float dense_146_bias_array[1] = {
        +3.93292487e-01f
    }; 
    k2c_tensor dense_146_bias = {&dense_146_bias_array[0],1,1,{1,1,1,1,1}}; 
    float dense_146_fwork[8] = {0};  

    k2c_dense(&dense_142_output, input, &dense_142_kernel, &dense_142_bias, k2c_relu, dense_142_fwork);
    // Other dense layers similarly initialized and used

    k2c_dense(output, &dense_142_output, &dense_146_kernel, &dense_146_bias, k2c_linear, dense_146_fwork);
}