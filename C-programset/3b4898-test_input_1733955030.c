
#include <stdio.h>
#include <math.h>

// Constants
#define REF_INTENSITY 1.0e-12  // Reference intensity (W/m^2)

// Structure to represent a sound source
typedef struct {
    double power;  // Acoustic power of the source (in Watts)
    double x, y, z; // Position of the source in 3D space (in meters)
} SoundSource;

// Function to calculate the intensity of sound at a given distance
double calculate_intensity(SoundSource source, double distance) {
    // Intensity formula: Power / (4 * pi * distance^2)
    if (distance == 0) return source.power;  // Avoid division by zero
    return source.power / (4 * M_PI * pow(distance, 2));
}

// Function to calculate the sound intensity level in decibels
double sound_intensity_level(double intensity) {
    // Sound intensity level formula: 10 * log10(intensity / reference intensity)
    return 10.0 * log10(intensity / REF_INTENSITY);
}

// Function to calculate Euclidean distance between two 3D points
double calculate_distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

int main() {
    // Define a sound source with fixed characteristics
    SoundSource source = { 10.0, 0.0, 0.0, 0.0 };  // 10 Watts at origin
    
    // Define some receiver points in 3D space
    const int num_receivers = 5;
    double receivers[num_receivers][3] = {
        {10.0, 0.0, 0.0},
        {20.0, 0.0, 0.0},
        {30.0, 0.0, 0.0},
        {40.0, 0.0, 0.0},
        {50.0, 0.0, 0.0}
    };

    printf("Receiver Position | Intensity (W/m^2) | Intensity Level (dB)\n");
    for (int i = 0; i < num_receivers; i++) {
        double distance = calculate_distance(source.x, source.y, source.z,
                                             receivers[i][0], receivers[i][1], receivers[i][2]);
        double intensity = calculate_intensity(source, distance);
        double intensity_level = sound_intensity_level(intensity);
        printf("   (%4.1f, %4.1f, %4.1f) | %14.8e | %16.3f dB\n", 
               receivers[i][0], receivers[i][1], receivers[i][2], intensity, intensity_level);
    }
    
    return 0;
}
