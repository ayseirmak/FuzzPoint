
#include <stdio.h>
#include <math.h>

// Structure to represent a geological layer
typedef struct {
    double density;       // Density of the layer (g/cm^3)
    double bulk_modulus;  // Bulk modulus of the layer (GPa)
    double shear_modulus; // Shear modulus of the layer (GPa)
} GeoLayer;

// Function to calculate the P-wave velocity in a layer
double calculate_p_wave_speed(GeoLayer layer) {
    // P-wave velocity formula: sqrt((K + 4/3 * G) / density)
    return sqrt((layer.bulk_modulus + 4.0/3.0 * layer.shear_modulus) / layer.density);
}

// Function to calculate the S-wave velocity in a layer
double calculate_s_wave_speed(GeoLayer layer) {
    // S-wave velocity formula: sqrt(G / density)
    return sqrt(layer.shear_modulus / layer.density);
}

int main() {
    // Define geological layers with fixed values
    GeoLayer layers[] = {
        {2.7, 50, 30},  // Layer 1: Crust
        {3.3, 60, 40},  // Layer 2: Upper Mantle
        {4.5, 140, 80}, // Layer 3: Lower Mantle
        {3.5, 110, 60}  // Layer 4: Outer Core
    };
    
    int num_layers = sizeof(layers) / sizeof(layers[0]);

    // Calculate and print seismic wave speeds for each layer
    printf("Seismic Wave Speeds (km/s):\n");
    for (int i = 0; i < num_layers; i++) {
        double p_wave_speed = calculate_p_wave_speed(layers[i]);
        double s_wave_speed = calculate_s_wave_speed(layers[i]);
        printf("Layer %d: P-wave speed = %.3f km/s, S-wave speed = %.3f km/s\n", 
               i + 1, p_wave_speed, s_wave_speed);
    }
    
    return 0;
}
