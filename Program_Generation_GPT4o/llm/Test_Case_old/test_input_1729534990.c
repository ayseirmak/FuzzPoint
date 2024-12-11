
#include <stdio.h>
#include <math.h>
#include <float.h>

// Define constants for an imaginary imaging grid
#define GRID_SIZE 512
#define INTENSITY_SCALE_FACTOR 1000.0

typedef struct {
    double intensity[GRID_SIZE][GRID_SIZE];
    char label[100]; // Example label for the image
} MedicalImage;

// Simulate processing of a medical image
void process_image(MedicalImage *image) {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            image->intensity[i][j] = sqrt(image->intensity[i][j]) * INTENSITY_SCALE_FACTOR;
        }
    }
}

void demonstrate_casting_operations() {
    float small_value = 1e-45f; // Very small value, subnormal in single precision
    double double_value = small_value; // Promote to double
    long double long_double_value = double_value; // Promote to long double

    long long int_value = (long long)(double_value * 1e5); // Cast double to long long

    printf("Casting small float to double: %e\n", double_value);
    printf("Casting double to long double: %Le\n", long_double_value);
    printf("Casting double to long long: %lld\n", int_value);
}

double recursive_intensity_sum(MedicalImage *image, int i, int j) {
    if (i >= GRID_SIZE || j >= GRID_SIZE) return 0.0;
    return image->intensity[i][j] + recursive_intensity_sum(image, i + 1, j) + recursive_intensity_sum(image, i, j + 1);
}

void demonstrate_arithmetic_operations() {
    double inf_val = INFINITY;
    double underflow_value = DBL_MIN / 2;

    printf("Infinity plus 1000.0: %f\n", inf_val + 1000.0);
    printf("Underflow operation (DBL_MIN / 2): %e\n", underflow_value);
}

int main() {
    MedicalImage sampleImage;

    // Initialize the image with some arbitrary intensities
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            sampleImage.intensity[i][j] = (i * j) % 255; // Example data
        }
    }

    // Process the image
    process_image(&sampleImage);

    // Demonstrate various floating point edge cases
    demonstrate_casting_operations();
    demonstrate_arithmetic_operations();

    // Compute intensity sum using a recursive method
    double total_intensity = recursive_intensity_sum(&sampleImage, 0, 0);
    printf("Total Intensity Sum: %f\n", total_intensity);

    return 0;
}
