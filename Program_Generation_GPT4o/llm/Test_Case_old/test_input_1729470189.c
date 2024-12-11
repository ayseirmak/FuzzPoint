
#include <stdio.h>
#include <math.h>
#include <arm_neon.h> // Use ARM NEON for SIMD vectorization

// Function to compute lift coefficient with possible anomalies
void compute_lift(float *velocities, float *pressures, float *lift_coeff, int size) {
#ifdef __ARM_NEON
    for (int i = 0; i < size; i += 4) {
        float32x4_t vec_velocities = vld1q_f32(&velocities[i]);
        float32x4_t vec_pressures = vld1q_f32(&pressures[i]);

        // Compute lift coefficient: Cl = 2 * P / (rho * V^2) with V^2 potentially creating extremities
        float32x4_t vec_squared_velocities = vmulq_f32(vec_velocities, vec_velocities);
        float32x4_t vec_lift = vmlaq_f32(vdupq_n_f32(0), vrecpeq_f32(vec_squared_velocities), vec_pressures);

        vst1q_f32(&lift_coeff[i], vec_lift);

        // Handle and flag special cases
        for (int j = 0; j < 4; j++) {
            if (isnan(lift_coeff[i + j])) {
                printf("NaN detected in lift coefficient at index %d\n", i + j);
            }
            if (isinf(lift_coeff[i + j])) {
                printf("Infinity detected in lift coefficient at index %d\n", i + j);
            }
        }
    }
#else
    for (int i = 0; i < size; i++) {
        lift_coeff[i] = 2 * pressures[i] / (1.225 * powf(velocities[i], 2));
        
        // Check NaN and infinity manually
        if (isnan(lift_coeff[i])) {
            printf("NaN detected in lift coefficient at index %d\n", i);
        }
        if (isinf(lift_coeff[i])) {
            printf("Infinity detected in lift coefficient at index %d\n", i);
        }
    }
#endif
}

int main() {
    // Given velocities (m/s) and pressures (Pa) involving edge cases
    float velocities[] = {100.0, 0.001, HUGE_VALF, nanf(""), 250.0, 15.0, 0.0, -50.0};
    float pressures[] = {101325.0, -99999, 5000.0, 5000.0, FLT_MAX, FLT_MIN, -0.0, NAN};
    
    // Length based on input arrays
    int size = sizeof(velocities) / sizeof(velocities[0]);

    float lift_coeff[size];

    // Calculate lift coefficients
    compute_lift(velocities, pressures, lift_coeff, size);

    // Display results
    printf("Lift coefficients:\n");
    for (int i = 0; i < size; i++) {
        printf("Lift coefficient at index %d: %f\n", i, lift_coeff[i]);
    }

    return 0;
}
