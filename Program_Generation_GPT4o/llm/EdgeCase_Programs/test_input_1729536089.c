
#include <stdio.h>
#include <math.h>
#include <fenv.h>

// Structure to represent the geophysical wave data at a certain depth
typedef struct {
    double depth;        // Depth in meters
    double wave_amplitude;  // Amplitude of the geophysical wave
    double attenuation;  // Wave attenuation factor
} GeophysicsData;

// Function to simulate wave propagation with meticulous floating-point handling
void simulate_wave_propagation(GeophysicsData* data, int iterations) {
    double frequency = 5.0; // Frequency in Hz
    double speed_of_sound = 1500.0; // Speed of sound in water in m/s

    for (int i = 0; i < iterations; i++) {
        // Change rounding mode occasionally to illustrate effects
        if (i % 3 == 0) {
            fesetround(FE_TONEAREST);  // Round to nearest
        } else if (i % 3 == 1) {
            fesetround(FE_TOWARDZERO); // Round toward zero
        } else {
            fesetround(FE_UPWARD);     // Round toward infinity
        }

        // Calculate wave number and angular frequency
        double wave_number = 2 * M_PI * frequency / speed_of_sound;
        double omega = 2 * M_PI * frequency;
        
        // Compute wave amplitude with exponential decay for attenuation
        data->wave_amplitude *= expl(-data->attenuation * data->depth) * cos(omega * data->depth / speed_of_sound);
        
        // Gradual underflow and precision management
        if (fabs(data->wave_amplitude) < DBL_MIN) {
            data->wave_amplitude = DBL_MIN;
        }

        // Use cosine and logarithmic functions to emulate wave behavior
        data->wave_amplitude *= cos(data->depth * wave_number) - log(1 + data->depth);

        // Check for special floating-point cases and adjust accordingly
        if (isnan(data->wave_amplitude) || isinf(data->wave_amplitude)) {
            data->wave_amplitude = 1.0; // Reset amplitude on NaN or infinity
        }
        
        // Increment depth to simulate further propagation
        data->depth += 1.0;
    }
}

int main() {
    // Initialize wave data with a certain starting depth and amplitude
    GeophysicsData wave_data = {
        0.0,    // Initial depth
        1.0,    // Initial wave amplitude
        0.005   // Attenuation factor
    };

    // Propagate the wave over a set number of iterations (depth increments)
    simulate_wave_propagation(&wave_data, 1000);

    // Determine if the wave amplitude remains above a certain threshold
    int result = (wave_data.wave_amplitude > 0.001) ? 1 : 0;

    return result;
}
