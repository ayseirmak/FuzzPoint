
#include <stdio.h>
#include <math.h>
#include <float.h>

// Structure to represent a robot joint with angle values
typedef struct {
    long double jointAngle;  // Joint angle in radians
} RobotJoint;

// Function to simulate the kinematic computation of a robotic arm
long double compute_position(long double angle) {
    long double position = M_PI * angle + M_E;  // Using constants π and e for some computation

    // Handle extreme values and special floating-point cases
    if (isnan(position)) {
        printf("Computation resulted in NaN\n");
        return 0.0L;
    }

    if (isinf(position)) {
        printf("Computation resulted in %s infinity\n", (position > 0) ? "positive" : "negative");
        return (position > 0) ? LDBL_MAX : -LDBL_MAX;
    }

    return position;
}

void adjust_joint_angles(RobotJoint *joints, int numJoints) {
    for (int i = 0; i < numJoints; i++) {
        // Introduce small changes to joint angles to simulate precision effects
        long double originalAngle = joints[i].jointAngle;
        for (int j = 0; j < 5; j++) {
            joints[i].jointAngle += powl(M_E, -j);
            long double position = compute_position(joints[i].jointAngle);

            // Check for subnormal values
            if (fpclassify(position) == FP_SUBNORMAL) {
                printf("Subnormal value encountered: %.10Le at joint %d\n", position, i);
            }

            printf("Joint %d iteration %d: Computed position: %.10Le\n", i, j, position);
        }
        // Reset back to the original angle for next loop iteration
        joints[i].jointAngle = originalAngle;
    }
}

int main() {
    // Define a robotic arm with some initial joint angles
    RobotJoint roboticArm[] = {
        {M_PI / 3.0L},
        {0.0L},   // Zero angle test
        {NAN},    // NaN test
        {1.0e-4950L}  // Subnormal test
    };
    int numJoints = sizeof(roboticArm) / sizeof(roboticArm[0]);

    // Adjust joint angles and compute positions
    adjust_joint_angles(roboticArm, numJoints);

    return 0;
}
