
#include <stdio.h>
#include <math.h>

#define LINK1_LENGTH 1.0 // Length of the first arm link
#define LINK2_LENGTH 1.0 // Length of the second arm link

typedef struct {
    double joint1; // Angle of the first joint in radians
    double joint2; // Angle of the second joint in radians
} JointAngles;

// Function to compute inverse kinematics for a 2D robotic arm
JointAngles compute_inverse_kinematics(double target_x, double target_y) {
    JointAngles angles;
    
    // Calculate distance from base to target
    double distance = sqrt(target_x * target_x + target_y * target_y);
    
    // Check if the target is reachable
    if (distance > LINK1_LENGTH + LINK2_LENGTH) {
        angles.joint1 = angles.joint2 = NAN; // Return NaN if out of reach
        return angles;
    }
    
    // Compute the inverse kinematic solution
    double cos_angle2 = (target_x * target_x + target_y * target_y - LINK1_LENGTH * LINK1_LENGTH - LINK2_LENGTH * LINK2_LENGTH) / (2.0 * LINK1_LENGTH * LINK2_LENGTH);
    angles.joint2 = acos(cos_angle2);

    double k1 = LINK1_LENGTH + LINK2_LENGTH * cos(angles.joint2);
    double k2 = LINK2_LENGTH * sin(angles.joint2);
    angles.joint1 = atan2(target_y, target_x) - atan2(k2, k1);
    
    return angles;
}

int main() {
    // Define the target point
    double target_x = 1.0;
    double target_y = 1.0;
    
    // Compute the joint angles
    JointAngles angles = compute_inverse_kinematics(target_x, target_y);

    // Print the calculated joint angles
    if (isnan(angles.joint1) || isnan(angles.joint2)) {
        printf("Target (%.2f, %.2f) is out of reach.\n", target_x, target_y);
    } else {
        printf("Joint angles to reach target (%.2f, %.2f):\n", target_x, target_y);
        printf("  Joint 1: %.2f radians\n", angles.joint1);
        printf("  Joint 2: %.2f radians\n", angles.joint2);
    }

    return 0;
}
