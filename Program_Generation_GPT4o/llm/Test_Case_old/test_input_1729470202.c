
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <arm_neon.h> // For SIMD vectorization

// Function to perform Monte Carlo simulation for portfolio value prediction
void monte_carlo_simulation(float *initial_values, float *returns, float *simulated_values, int num_assets, int num_years) {
#ifdef __ARM_NEON
    for (int year = 0; year < num_years; year++) {
        for (int i = 0; i < num_assets; i += 4) {
            float32x4_t vec_initial = vld1q_f32(&initial_values[i]);
            float32x4_t vec_returns = vld1q_f32(&returns[i]);
            float32x4_t vec_multiplier = vaddq_f32(vdupq_n_f32(1.0f), vec_returns);
            vec_initial = vmulq_f32(vec_initial, vec_multiplier);
            vst1q_f32(&simulated_values[i], vec_initial);

            // NaN and inf handling check
            for (int j = 0; j < 4; j++) {
                if (isnan(simulated_values[i + j])) {
                    printf("NaN detected in simulated value at index %d, year %d\n", i + j, year);
                }
                if (isinf(simulated_values[i + j])) {
                    printf("Infinity detected in simulated value at index %d, year %d\n", i + j, year);
                }
            }
        }
    }
#else
    for (int year = 0; year < num_years; year++) {
        for (int i = 0; i < num_assets; i++) {
            simulated_values[i] *= (1.0f + returns[i]);

            if (isnan(simulated_values[i])) {
                printf("NaN detected in simulated value at index %d, year %d\n", i, year);
            }
            if (isinf(simulated_values[i])) {
                printf("Infinity detected in simulated value at index %d, year %d\n", i, year);
            }
        }
    }
#endif
}

int main() {
    const int num_assets = 8;
    const int num_years = 5;

    // Initial asset values and expected return rates
    float initial_values[] = {1000.0, 1500.0, 2000.0, HUGE_VALF, 2500.0, 3000.0, 3500.0, 4000.0};
    float returns[] = {0.05, 0.07, -0.01, 0.00, 0.03, -HUGE_VALF, NAN, 0.02};

    float final_values[num_assets];

    // Initialize final values for simulation
    for (int i = 0; i < num_assets; i++) {
        final_values[i] = initial_values[i];
    }

    // Perform Monte Carlo simulation
    monte_carlo_simulation(initial_values, returns, final_values, num_assets, num_years);
    
    // Output the calculated final values
    printf("Final simulated values after %d years:\n", num_years);
    for (int i = 0; i < num_assets; i++) {
        printf("Asset %d: %f\n", i, final_values[i]);
    }

    return 0;
}
