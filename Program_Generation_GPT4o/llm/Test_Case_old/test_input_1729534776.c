
#include <stdio.h>
#include <math.h>
#include <float.h>

// Define a macro for a small threshold value to test for underflow
#define THRESHOLD 1e-308
#define PI 3.14159265358979323846

// Define a structure representing the position and orientation of a robotic arm
typedef struct {
    double x, y, z; // 3D position
    long double orientation; // Orientation in radians
} RobotArmPose;

// Calculate distance from origin
double calculate_norm(RobotArmPose pose) {
    // Perform a calculation that can test for catastrophic cancellation
    double result = sqrt(pow(pose.x, 2) + pow(pose.y, 2) + pow(pose.z, 2)) - sqrt(pow(pose.x - pose.x, 2) + pow(pose.y - pose.y, 2) + pow(pose.z - pose.z, 2));
    return result;
}

// Recursive function to simulate computational operations and underflow
double recursive_operation(double value, int depth) {
    if (depth <= 0) return value;
    return recursive_operation(value * THRESHOLD, depth - 1);
}

// Function to convert pose to another type, demonstrating casting in floating-point
void convert_pose(RobotArmPose pose) {
    // Casting double to float
    float fx = (float)pose.x;
    float fy = (float)pose.y;
    float fz = (float)pose.z;

    // Casting long double to double
    double orientation = (double)pose.orientation;

    // Outputs
    printf("Converted floats: (%f, %f, %f) Orientation: %f\n", fx, fy, fz, orientation);

    // Conversion to long long (not usually recommended due to precision loss)
    long long int_x = (long long)pose.x;
    long long int_y = (long long)pose.y;
    long long int_z = (long long)pose.z;

    printf("Converted to long long: (%lld, %lld, %lld)\n", int_x, int_y, int_z);
}

int main() {
    // Initialize the robotic arm position
    RobotArmPose pose = {123.456, 789.012, 345.678, PI / 4}; // Example position and orientation

    // Calculate the norm
    double norm = calculate_norm(pose);
    printf("Calculated norm: %e\n", norm);

    // Perform recursive operation demonstrating gradual underflow
    double result = recursive_operation(1.0, 100);
    printf("Recursive operation result: %e\n", result);

    // Convert and display different representations of the same pose
    convert_pose(pose);

    return 0;
}
