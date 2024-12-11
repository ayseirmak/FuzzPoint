
#include <stdio.h>
#include <math.h>
#include <float.h>

// Define the dimensions of the medical image
#define WIDTH 4
#define HEIGHT 4

// Function declaration for recursive brightness adjustment
double adjust_brightness_recursive(double pixels[WIDTH][HEIGHT], int x, int y, int depth);

int main() {
    // Initialize a 4x4 mock image with some values
    double image[WIDTH][HEIGHT] = {
        {0.0, 0.5, 1.0, 1.5},
        {2.0, 2.5, 3.0, 3.5},
        {4.0, 4.5, 5.0, 5.5},
        {6.0, 6.5, 7.0, INFINITY}
    };

    // Placeholders for NaN and denormalized number
    image[0][0] = NAN;
    double denormalized = DBL_MIN / 2;
    image[3][3] = denormalized;

    printf("Initial Image:\n");
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%0.1f ", image[i][j]);
        }
        printf("\n");
    }

    // Adjust the brightness recursively
    adjust_brightness_recursive(image, 0, 0, 0);

    printf("\nBrightness Adjusted Image:\n");
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%0.1f ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Recursive function to adjust brightness
double adjust_brightness_recursive(double pixels[WIDTH][HEIGHT], int x, int y, int depth) {
    if (x >= WIDTH || y >= HEIGHT) return 0.0;

    double pixel_value = pixels[x][y];

    // Handle edge cases
    if (isnan(pixel_value)) {
        pixel_value = 0;  // Set NaN pixels to 0
    } else if (isinf(pixel_value)) {
        pixel_value = DBL_MAX;  // Set infinity to maximum double value
    } else if (pixel_value < DBL_MIN && pixel_value > 0) {
        pixel_value = 0;  // Handle denormalized numbers
    }

    // Calculate new pixel value & round for demonstration
    pixel_value *= 1.2;
    pixel_value = round(pixel_value);

    // Update pixel value
    pixels[x][y] = pixel_value;

    // Recurse to the next pixel
    if (x < WIDTH - 1) {
        adjust_brightness_recursive(pixels, x + 1, y, depth + 1);
    } else if (y < HEIGHT - 1) {
        adjust_brightness_recursive(pixels, 0, y + 1, depth + 1);
    }

    return pixel_value;
}
