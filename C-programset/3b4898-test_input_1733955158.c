
#include <stdio.h>
#include <math.h>

// Robot arm specifications
#define LINK1_LENGTH 1.0  // Length of the first link (meters)
#define LINK2_LENGTH 1.0  // Length of the second link (meters)
#define TARGET_X 1.5      // Target x-coordinate for the end effector (meters)
#define TARGET_Y 0.5      // Target y-coordinate for the end effector (meters)

// Function to compute inverse kinematics for a 2D 2-link robotic arm
void inverse_kinematics(double x, double y, double *theta1, double *theta2) {
    double r = sqrt(x*x + y*y);
    double angle1 = atan2(y, x);
    double cos_angle2 = (r*r - LINK1_LENGTH*LINK1_LENGTH - LINK2_LENGTH*LINK2_LENGTH) / 
                        (2 * LINK1_LENGTH * LINK2_LENGTH);

    *theta2 = acos(cos_angle2);
    double sin_angle2 = sqrt(1 - cos_angle2*cos_angle2);
    double angle2 = atan2(sin_angle2, cos_angle2);

    double cos_theta1 = (x*(LINK1_LENGTH + LINK2_LENGTH*cos_angle2) + y*LINK2_LENGTH*sin_angle2) / 
                        (r*r);
    double sin_theta1 = (y*(LINK1_LENGTH + LINK2_LENGTH*cos_angle2) - x*LINK2_LENGTH*sin_angle2) / 
                        (r*r);
    *theta1 = atan2(sin_theta1, cos_theta1);
}

int main() {
    double theta1, theta2;
    inverse_kinematics(TARGET_X, TARGET_Y, &theta1, &theta2);

    printf("Robotics Simulation - Inverse Kinematics:\n");
    printf("Target Position: (%.2f, %.2f)\n", TARGET_X, TARGET_Y);
    printf("Calculated Joint Angles:\n");
    printf("Theta1: %.2f radians\n", theta1);
    printf("Theta2: %.2f radians\n", theta2);

    return 0;
}
