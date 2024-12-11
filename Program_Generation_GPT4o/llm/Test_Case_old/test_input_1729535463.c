
#include <stdio.h>
#include <math.h>
#include <float.h>

// Structure to represent a robotic joint
typedef struct {
    float position;     // Position of the joint in degrees
    double velocity;    // Velocity of the joint in degrees/s
    long double torque; // Torque applied to the joint in Nm
} RobotJoint;

// Function to simulate joint movement and check for precision loss
void process_joint_movements(RobotJoint* joint) {
    // Simulating some robotic computation
    double computed_velocity = joint->velocity - (joint->velocity / 2 + joint->torque / 1e7 - joint->torque / 1e7); // Catastrophic cancellation

    printf("Computed Velocity (Double): %.10e\n", computed_velocity);

    // Checking for -0.0 representation
    float computed_position = joint->position + 0.0f - 0.0f;
    if (computed_position == -0.0f) {
        printf("Position is represented as -0.0\n");
    }
}

// Function to check special floating-point values
void check_special_values(RobotJoint* joint) {
    long double values[] = {joint->position, joint->velocity, joint->torque};
    const char* labels[] = {"position", "velocity", "torque"};

    for(int i = 0; i < 3; i++) {
        if (fpclassify(values[i]) == FP_ZERO) {
            printf("%s is zero.\n", labels[i]);
        } else if (isinf(values[i])) {
            printf("%s is infinite.\n", labels[i]);
        } else if (isnan(values[i])) {
            printf("%s is NaN.\n", labels[i]);
        } else if (fpclassify(values[i]) == FP_SUBNORMAL) {
            printf("%s is subnormal.\n", labels[i]);
        } else {
            printf("%s is normal.\n", labels[i]);
        }
    }
}

// Function to demonstrate type casting
void casting_demo(RobotJoint* joint) {
    long long torque_ll = (long long)joint->torque;
    printf("Torque as long long: %lld\n", torque_ll);

    float velocity_float = (float)joint->velocity;
    printf("Velocity as float: %.8e\n", velocity_float);
}

int main() {
    // Initialize robotic joint with some values
    RobotJoint joint = {30.0F, 60.0, 1.0e-30L}; // Using a very small torque to simulate subnormal

    printf("Initial Joint State: Position: %.2f degrees, Velocity: %.2f degrees/s, Torque: %.2Le Nm\n", 
           joint.position, joint.velocity, joint.torque);

    // Process joint movements and simulate computations
    process_joint_movements(&joint);

    // Check special floating-point values
    printf("\nChecking Special Values...\n");
    check_special_values(&joint);

    // Demonstrate type casting
    printf("\nCasting Demonstration...\n");
    casting_demo(&joint);

    return 0;
}
