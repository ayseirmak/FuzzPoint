#include <math.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <keras2c/k2c_tensor_include.h>

// Forward declaration of the neural network function
void poly_16_16(k2c_tensor* input_tensor, k2c_tensor* output_tensor);
// Custom assert function to replace __VERIFIER_assert
void verifier_assert(int condition) {
    if (!condition) {
        printf("Verification failed\n");
        exit(1);
    }
}

int main() {
    // Neural net input and output
    float input_array[1] = {-1.95f}; // Fixed deterministic value within the given range
    float output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};
    
    // Call the neural network with fixed input
    poly_16_16(&input_tensor, &output_tensor);
    
    // Compare the network output with an affine approximation of the ground truth
    float x = input_array[0];
    float y = -2.637375000000004f * (x + 2.0f) - 0.5f;
    float diff = fabsf(y - output_array[0]);
    
    // Verify the difference with a threshold
    verifier_assert(islessequal(diff, 0.02197077996329016308598028549160f));
    
    return 0;
}

void poly_16_16(k2c_tensor* dense_73_input_input, k2c_tensor* dense_75_output) {
    // Definition of internal variables and tensors
    float dense_73_output_array[16] = {0}; 
    k2c_tensor dense_73_output = {&dense_73_output_array[0], 1, 16, {16, 1, 1, 1, 1}};
    float dense_73_kernel_array[16] = {
        -2.91538596e-01f, -4.32328910e-01f, -4.71810281e-01f, -2.36504599e-01f, 6.82376087e-01f,
        -3.31945032e-01f, -2.75035799e-01f, -5.51251411e-01f, 1.44019037e-01f, -1.93018556e-01f,
        -3.66769731e-01f, 5.92754066e-01f, -5.61193764e-01f, 2.43914686e-03f, 2.23800028e-03f,
        -1.04091935e-01f
    }; 
    k2c_tensor dense_73_kernel = {&dense_73_kernel_array[0], 2, 16, {1, 16, 1, 1, 1}};
    float dense_73_bias_array[16] = {
        1.14021912e-01f, -1.05561487e-01f, 2.13974412e-03f, -1.95513800e-01f, 1.48149937e-01f,
        -1.66161492e-01f, -1.93376675e-01f, 7.87953660e-02f, 1.00780594e+00f, 4.02256191e-01f,
        9.28107798e-01f, -6.20670691e-02f, -1.15739748e-01f, -2.22387202e-02f, -1.95850711e-02f,
        1.78294834e-02f
    }; 
    k2c_tensor dense_73_bias = {&dense_73_bias_array[0], 1, 16, {16, 1, 1, 1, 1}};
    float dense_73_fwork[17] = {0}; 

    float dense_74_output_array[16] = {0}; 
    k2c_tensor dense_74_output = {&dense_74_output_array[0], 1, 16, {16, 1, 1, 1, 1}};
    float dense_74_kernel_array[256] = {
        3.97221714e-01f, -1.53746039e-01f, -8.87194052e-02f, -4.03218001e-01f, 3.39828819e-01f,
        //... (remaining 250 initializers)
        -1.39803857e-01f, 1.40811410e-02f,
    }; 
    k2c_tensor dense_74_kernel = {&dense_74_kernel_array[0], 2, 256, {16, 16, 1, 1, 1}};
    float dense_74_bias_array[16] = {
        -7.41083268e-03f, 0.00000000e+00f, -3.36114585e-01f, -1.87887084e-02f, 0.00000000e+00f,
        3.10818572e-02f, -6.06890842e-02f, 3.57743263e-01f, 7.20615536e-02f, 4.60838601e-02f,
        -2.35005021e-02f, 5.93134873e-02f, 3.98602560e-02f, 2.49081075e-01f, 7.14392215e-02f,
        -2.24403828e-01f, 
    }; 
    k2c_tensor dense_74_bias = {&dense_74_bias_array[0], 1, 16, {16, 1, 1, 1, 1}};
    float dense_74_fwork[272] = {0}; 

    float dense_75_kernel_array[16] = {
        -3.39682810e-02f, 5.16815305e-01f, 3.63696039e-01f, 2.41472185e-01f, 5.82090735e-01f,
        9.24791873e-01f, -5.02992451e-01f, -7.26600528e-01f, 8.08877468e-01f, -1.13709188e+00f,
        -2.72554934e-01f, 4.87121969e-01f, -8.09962928e-01f, -7.08599806e-01f, 4.10384506e-01f,
        5.53093255e-01f
    }; 
    k2c_tensor dense_75_kernel = {&dense_75_kernel_array[0], 2, 16, {16, 1, 1, 1, 1}};
    float dense_75_bias_array[1] = {
        -1.76433966e-01f,
    }; 
    k2c_tensor dense_75_bias = {&dense_75_bias_array[0], 1, 1, {1, 1, 1, 1, 1}};
    float dense_75_fwork[32] = {0}; 

    // Execute the neural network
    k2c_dense(&dense_73_output, dense_73_input_input, &dense_73_kernel, 
              &dense_73_bias, k2c_relu, dense_73_fwork);
    k2c_dense(&dense_74_output, &dense_73_output, &dense_74_kernel, 
              &dense_74_bias, k2c_relu, dense_74_fwork);
    k2c_dense(dense_75_output, &dense_74_output, &dense_75_kernel, 
              &dense_75_bias, k2c_linear, dense_75_fwork);
}