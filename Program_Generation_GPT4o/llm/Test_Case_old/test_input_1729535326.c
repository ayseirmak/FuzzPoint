
#include <stdio.h>
#include <math.h>
#include <float.h>

typedef struct {
    long double pixelValue;
    int x;  // x-coordinate in the image
    int y;  // y-coordinate in the image
} ImagePixel;

void processImagePixels(ImagePixel image[], int size) {
    for (int i = 0; i < size; i++) {
        long double value = image[i].pixelValue;

        // Handle NaN and infinity values
        if (isnan(value)) {
            printf("Pixel at (%d, %d) is NaN\n", image[i].x, image[i].y);
            image[i].pixelValue = 0.0;
        } else if (isinf(value)) {
            printf("Pixel at (%d, %d) is %s infinity\n", image[i].x, image[i].y, (value > 0) ? "positive" : "negative");
            image[i].pixelValue = (value > 0) ? LDBL_MAX : -LDBL_MAX;
        }

        // Example long double operations: square and reciprocal with underflow handling
        long double squared = value * value;
        long double reciprocal = iszero(value) ? LDBL_MAX : 1.0 / value;

        // Conditionals to handle special float values
        switch (fpclassify(value)) {
            case FP_ZERO:
                printf("Zero found at (%d, %d)\n", image[i].x, image[i].y);
                break;
            case FP_SUBNORMAL:
                printf("Subnormal value at (%d, %d)\n", image[i].x, image[i].y);
                break;
            default:
                break;
        }

        // Store computed results back to the struct
        image[i].pixelValue = squared + reciprocal;
    }
}

int main() {
    // Define an example image with problematic pixel values
    ImagePixel image[] = {
        {NAN, 0, 0},
        {INFINITY, 0, 1},
        {-INFINITY, 1, 0},
        {1.0e-4950L, 1, 1},  // Subnormal value
        {0.0, 2, 0},
        {2.5, 2, 1}
    };

    int numPixels = sizeof(image) / sizeof(image[0]);
    processImagePixels(image, numPixels);

    // Print results after processing
    printf("\nProcessed image pixel values:\n");
    for (int i = 0; i < numPixels; i++) {
        printf("Pixel at (%d, %d): %.5Lf\n", image[i].x, image[i].y, image[i].pixelValue);
    }

    return 0;
}
