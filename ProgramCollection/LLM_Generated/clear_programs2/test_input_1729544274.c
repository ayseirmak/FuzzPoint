
#include <stdio.h>
#include <math.h>

#define WIDTH 5
#define HEIGHT 5
#define MAX_INTENSITY 255

// Function to normalize the histogram of an image for contrast enhancement
void histogram_equalization(int input[WIDTH][HEIGHT], double output[WIDTH][HEIGHT]) {
    int histogram[MAX_INTENSITY + 1] = {0};
    double cdf[MAX_INTENSITY + 1] = {0.0};
    int total_pixels = WIDTH * HEIGHT;

    // Compute the histogram
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            histogram[input[i][j]]++;
        }
    }

    // Compute the cumulative distribution function (cdf)
    cdf[0] = (double)histogram[0] / total_pixels;
    for (int i = 1; i <= MAX_INTENSITY; ++i) {
        cdf[i] = cdf[i - 1] + (double)histogram[i] / total_pixels;
    }

    // Equalize the histogram
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            output[i][j] = cdf[input[i][j]] * MAX_INTENSITY;
        }
    }
}

int main() {
    // Example input image (5x5 matrix with intensity values)
    int input_image[WIDTH][HEIGHT] = {
        {52, 55, 61, 59, 79},
        {62, 59, 55, 104, 94},
        {63, 65, 66, 113, 144},
        {54, 52, 58, 109, 126},
        {49, 49, 49, 100, 109}
    };

    double output_image[WIDTH][HEIGHT] = {0};

    // Apply histogram equalization
    histogram_equalization(input_image, output_image);

    // Print the resulting contrast-enhanced image
    printf("Contrast-enhanced image:\n");
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            printf("%6.2f ", output_image[i][j]);
        }
        printf("\n");
    }

    return 0;
}
