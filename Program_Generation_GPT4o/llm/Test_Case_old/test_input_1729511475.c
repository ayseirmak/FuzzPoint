
#include <stdio.h>
#include <math.h>
#include <float.h>

// Define constants for seismic wave propagation
#define GRID_SIZE 5
#define MAX_DEPTH 10

// Recursive function to simulate seismic wave amplitude decay
double simulate_wave_amplitude(double grid[GRID_SIZE][GRID_SIZE], int x, int y, int depth) {
    if (depth > MAX_DEPTH || x >= GRID_SIZE || y >= GRID_SIZE || x < 0 || y < 0) {
        return 0.0;  // Base case or out of bounds
    }

    double amplitude = grid[x][y] - depth * 0.1; // Simulate amplitude decay
    amplitude = fmax(0, amplitude); // Ensure non-negative amplitudes

    // Handle denormalized numbers
    if (amplitude > 0 && amplitude < DBL_MIN) {
        amplitude = 0; // Deal with potential underflows
    }

    // Recursive calls in four directions to simulate wave propagation
    amplitude += simulate_wave_amplitude(grid, x + 1, y, depth + 1);
    amplitude += simulate_wave_amplitude(grid, x - 1, y, depth + 1);
    amplitude += simulate_wave_amplitude(grid, x, y + 1, depth + 1);
    amplitude += simulate_wave_amplitude(grid, x, y - 1, depth + 1);

    return amplitude;
}

int main() {
    // Initialize a grid with some initial seismic activity amplitudes
    double seismic_grid[GRID_SIZE][GRID_SIZE] = {
        {0.0, 0.0, 1.0, 0.0, 0.0},
        {0.0, 0.0, 2.0, 0.0, 0.0},
        {0.0, 0.0, 0.5, 0.0, 0.0},
        {0.0, 0.0, DBL_MIN/2, 0.0, 0.0},  // Small, potentially denormalized number
        {0.0, 0.0, 0.0, 0.0, 0.0}
    };

    printf("Initial Seismic Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%0.2f ", seismic_grid[i][j]);
        }
        printf("\n");
    }

    // Start the recursive seismic wave simulation from the center of the grid
    double total_amplitude = simulate_wave_amplitude(seismic_grid, 2, 2, 0);

    printf("\nTotal amplitude after simulation: %0.2f\n", total_amplitude);

    return 0;
}
