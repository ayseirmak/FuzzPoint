
#include <stdio.h>
#include <math.h>
#include <float.h>

// Define a 2D array representing a medical image
#define IMAGE_SIZE 5
float image[IMAGE_SIZE][IMAGE_SIZE] = {
    {1.0f, 2.0f, 3.0f, 4.0f, 5.0f},
    {6.0f, 7.0f, 8.0f, 9.0f, 10.0f},
    {11.0f, 12.0f, 13.0f, 14.0f, 15.0f},
    {16.0f, 17.0f, 18.0f, 19.0f, 20.0f},
    {21.0f, 22.0f, 23.0f, 24.0f, 25.0f}
};

// Function to apply a Gaussian filter and compute pixel intensity
void apply_gaussian_filter() {
    float kernel[3][3] = {
        {1.0f/16, 2.0f/16, 1.0f/16},
        {2.0f/16, 4.0f/16, 2.0f/16},
        {1.0f/16, 2.0f/16, 1.0f/16},
    };
    
    for (int i = 1; i < IMAGE_SIZE - 1; ++i) {
        for (int j = 1; j < IMAGE_SIZE - 1; ++j) {
            float intensity = 0.0f;
            for (int ki = 0; ki < 3; ++ki) {
                for (int kj = 0; kj < 3; ++kj) {
                    intensity += image[i + ki - 1][j + kj - 1] * kernel[ki][kj];
                }
            }
            printf("Filtered intensity at (%d, %d): %.7f\n", i, j, intensity);
        }
    }
}

// Function to demonstrate floating-point edge cases
void floating_point_edge_cases() {
    // Handling extreme values - Overflow example
    float large_value = FLT_MAX;
    float result_overflow = large_value * 10.0f; // Intentional overflow

    // Underflow example
    float small_value = FLT_MIN;
    float result_underflow = small_value / 10.0f; // Intentional underflow

    // Infinity arithmetic example
    float infinity_value = large_value * 2.0f; // Infinity due to overflow
    float inf_calc = infinity_value / 2.0f;

    printf("Overflow handling result: %.7e\n", result_overflow);
    printf("Underflow handling result: %.7e\n", result_underflow);
    printf("Infinity arithmetic result: %.7f\n", inf_calc);
}

// Function to compare precision between different types
void compare_precision() {
    float f_value = 1.123456f;
    double d_value = 1.1234567890123;
    long double ld_value = 1.1234567890123456789L;

    printf("Comparing precision of various types:\n");
    printf("  float: %.7f\n", f_value);
    printf("  double: %.15f\n", d_value);
    printf("  long double: %.18Lf\n", ld_value);
}

int main() {
    // Apply a Gaussian filter to the image and process results
    apply_gaussian_filter();

    // Demonstrate floating-point edge cases
    floating_point_edge_cases();

    // Compare precision between float, double, and long double
    compare_precision();

    return 0;
}
