
#include <stdio.h>
#include <math.h>

// Define a structure to represent a voxel in a 3D medical image
typedef struct {
    double intensity;  // Intensity value of the voxel
    double x, y, z;    // Position in 3D space
} Voxel;

// Function to compute the intensity gradient magnitude of a voxel
double compute_gradient_magnitude(Voxel v1, Voxel v2) {
    // Calculate differences in intensity and position
    double intensity_diff = v2.intensity - v1.intensity;
    double x_diff = v2.x - v1.x;
    double y_diff = v2.y - v1.y;
    double z_diff = v2.z - v1.z;

    return sqrt(pow(intensity_diff, 2) + pow(x_diff, 2) + pow(y_diff, 2) + pow(z_diff, 2));
}

// Function to perform a complex computation on a series of voxels
void process_voxels(const Voxel voxels[], int count) {
    for (int i = 0; i < count - 1; i++) {
        double gradient_magnitude = compute_gradient_magnitude(voxels[i], voxels[i + 1]);
        printf("Gradient magnitude between voxel %d and voxel %d: %f\n", i, i + 1, gradient_magnitude);
    }
}

int main() {
    // Define a small fixed set of voxels
    Voxel voxels[] = {
        {75.0, 1.0, 1.0, 1.0},  // Voxel 1
        {80.0, 2.0, 1.0, 1.0},  // Voxel 2
        {82.0, 2.0, 2.0, 1.0},  // Voxel 3
        {77.0, 3.0, 2.0, 2.0},  // Voxel 4
        {79.0, 3.0, 3.0, 3.0},  // Voxel 5
    };
    int num_voxels = sizeof(voxels) / sizeof(voxels[0]);

    // Process the voxels
    process_voxels(voxels, num_voxels);

    return 0;
}
