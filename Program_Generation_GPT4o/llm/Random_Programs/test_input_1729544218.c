
#include <stdio.h>
#include <math.h>

// Define constants for the simulation
#define AU 149597870.7 // Astronomical Unit in kilometers (average Earth-Sun distance)
#define NUM_PLANETS 2 // Limiting to two planets for simplicity in this demo

typedef struct {
    double semi_major_axis; // Semi-major axis in AU
    double eccentricity;    // Orbital eccentricity
    double period;          // Orbital period in Earth years
} Planet;

typedef struct {
    double x, y;   // Position coordinates in AU
} Position;

// Function to calculate the position of a planet in its orbit using Kepler's laws
Position calculate_planet_position(Planet planet, double time_years) {
    // Mean anomaly
    double mean_anomaly = 2.0 * M_PI / planet.period * time_years;

    // Eccentric anomaly and iterative solution using Newton's method
    double eccentric_anomaly = mean_anomaly;
    for (int i = 0; i < 100; ++i) {
        eccentric_anomaly = mean_anomaly + planet.eccentricity * sin(eccentric_anomaly);
    }

    // True anomaly
    double true_anomaly = 2.0 * atan2(sqrt(1 + planet.eccentricity) * sin(eccentric_anomaly / 2),
                                      sqrt(1 - planet.eccentricity) * cos(eccentric_anomaly / 2));

    // Distance from the sun
    double distance = planet.semi_major_axis * (1 - planet.eccentricity * cos(eccentric_anomaly));

    // Cartesian coordinates in the orbital plane
    Position pos;
    pos.x = distance * cos(true_anomaly);
    pos.y = distance * sin(true_anomaly);
    return pos;
}

int main() {
    // Define two planets: Earth and Mars for demonstration purposes
    Planet planets[NUM_PLANETS] = {
        {1.0, 0.0167, 1.0}, // Earth
        {1.524, 0.0934, 1.88} // Mars
    };

    double time_years = 2.0; // Calculate position at year 2

    printf("Planetary positions at year %.1f:\n", time_years);
    for (int i = 0; i < NUM_PLANETS; ++i) {
        Position pos = calculate_planet_position(planets[i], time_years);
        printf("Planet %d: Position = (%.3f AU, %.3f AU)\n", i + 1, pos.x, pos.y);
    }

    return 0;
}
