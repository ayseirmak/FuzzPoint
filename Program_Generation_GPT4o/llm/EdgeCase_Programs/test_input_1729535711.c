
#include <stdio.h>
#include <math.h>
#include <float.h>

// Define a simple image buffer for demonstration
#define IMAGE_SIZE 8
float image[IMAGE_SIZE] = {0.0f, 1.0f, 2.0f, 3.5f, -0.0f, -2.0f, INFINITY, NAN};

// Function to process image histogram using various floating-point types
void compute_image_histogram(float* img, int size) {
    long double histogram[5] = {0}; // Since it's a demonstration, we use a fixed size histogram

    for (int i = 0; i < size; ++i) {
        // Conditionals for handling special values
        if (img[i] == -0.0f) {
            printf("Pixel %d is represented as -0.0f\n", i);
        }

        switch (fpclassify(img[i])) {
            case FP_INFINITE:
                printf("Pixel %d has infinite value\n", i);
                break;
            case FP_NAN:
                printf("Pixel %d has NaN value\n", i);
                break;
            case FP_NORMAL:
            case FP_ZERO:
            case FP_SUBNORMAL:
                // Histogram calculation
                int index = (int)img[i];
                if (index >= 0 && index < 5) {
                    histogram[index] += 1;
                }
                break;
            default:
                break;
        }
    }

    for (int i = 0; i < 5; ++i) {
        printf("Histogram bin %d: %.2Lf\n", i, histogram[i]);
    }
}

// Function to illustrate casting and precision issues
void cast_and_compare_precision(float* img, int size) {
    double double_sum = 0.0;
    long double long_double_sum = 0.0L;

    for (int i = 0; i < size; ++i) {
        // Casting between types
        double d_val = (double)img[i];
        long double ld_val = (long double)d_val;

        // Accumulating values to illustrate precision loss
        double_sum += d_val;
        long_double_sum += ld_val;
    }

    printf("Sum with double precision: %.15f\n", double_sum);
    printf("Sum with long double precision: %.18Lf\n", long_double_sum);
}

int main() {
    printf("Begin Medical Imaging Simulation\n");

    printf("\nComputing Histogram...\n");
    compute_image_histogram(image, IMAGE_SIZE);

    printf("\nCasting and Comparing Precision...\n");
    cast_and_compare_precision(image, IMAGE_SIZE);

    return 0;
}
