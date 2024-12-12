
#include <stdio.h>
#include <math.h>

#define WIDTH 5
#define HEIGHT 5
#define KERNEL_SIZE 3
#define SIGMA 1.0

// Function to initialize a 2D Gaussian kernel
void initialize_gaussian_kernel(double kernel[KERNEL_SIZE][KERNEL_SIZE], double sigma) {
    double sum = 0.0;
    int half_size = KERNEL_SIZE / 2;

    for (int x = -half_size; x <= half_size; ++x) {
        for (int y = -half_size; y <= half_size; ++y) {
            double exponent = -(x * x + y * y) / (2 * sigma * sigma);
            kernel[x + half_size][y + half_size] = exp(exponent) / (2 * M_PI * sigma * sigma);
            sum += kernel[x + half_size][y + half_size];
        }
    }

    // Normalize the kernel
    for (int x = 0; x < KERNEL_SIZE; ++x) {
        for (int y = 0; y < KERNEL_SIZE; ++y) {
            kernel[x][y] /= sum;
        }
    }
}

// Function to apply Gaussian smoothing filter to 2D image data
void apply_gaussian_filter(double input[WIDTH][HEIGHT], double output[WIDTH][HEIGHT], double kernel[KERNEL_SIZE][KERNEL_SIZE]) {
    int half_size = KERNEL_SIZE / 2;

    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            double sum = 0.0;
            for (int ki = -half_size; ki <= half_size; ++ki) {
                for (int kj = -half_size; kj <= half_size; ++kj) {
                    int x = i + ki;
                    int y = j + kj;
                    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
                        sum += input[x][y] * kernel[ki + half_size][kj + half_size];
                    }
                }
            }
            output[i][j] = sum;
        }
    }
}

int main() {
    // Example input image (5x5 matrix with dummy values)
    double input_image[WIDTH][HEIGHT] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    double output_image[WIDTH][HEIGHT] = {0};
    double kernel[KERNEL_SIZE][KERNEL_SIZE];

    // Initialize the Gaussian kernel
    initialize_gaussian_kernel(kernel, SIGMA);

    // Apply the Gaussian filter
    apply_gaussian_filter(input_image, output_image, kernel);

    // Print the smoothed output image
    printf("Smoothed image:\n");
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            printf("%6.2f ", output_image[i][j]);
        }
        printf("\n");
    }

    return 0;
}
