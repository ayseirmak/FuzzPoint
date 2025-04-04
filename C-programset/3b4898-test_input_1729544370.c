
#include <stdio.h>
#include <math.h>

// Constants for the simulation
#define GRAVITY 9.81             // Acceleration due to gravity in m/s^2
#define AIR_DENSITY 1.225        // Air density at sea level in kg/m^3
#define DRAG_COEFFICIENT 0.3     // Drag coefficient
#define LIFT_COEFFICIENT 0.5     // Lift coefficient
#define AIRCRAFT_AREA 30.0       // Wing area of the aircraft in m^2
#define TIME_STEP 0.1            // Time step for simulation in seconds

// Function to calculate lift force
double calculate_lift(double velocity) {
    return 0.5 * AIR_DENSITY * velocity * velocity * AIRCRAFT_AREA * LIFT_COEFFICIENT;
}

// Function to calculate drag force
double calculate_drag(double velocity) {
    return 0.5 * AIR_DENSITY * velocity * velocity * AIRCRAFT_AREA * DRAG_COEFFICIENT;
}

// Function to simulate the flight path
void simulate_flight(double initial_velocity, double initial_angle, double total_time) {
    double time = 0.0;
    double velocity = initial_velocity;
    double angle = initial_angle;
    double x_position = 0.0;
    double y_position = 0.0;

    printf("Time(s)   X Position(m)   Y Position(m)   Velocity(m/s)   Angle(deg)\n");
    printf("----------------------------------------------------------------------\n");

    while (time <= total_time) {
        double lift = calculate_lift(velocity);
        double drag = calculate_drag(velocity);

        // Update velocity and angle due to lift and drag forces
        double acceleration = (lift - drag) / (AIRCRAFT_AREA * AIR_DENSITY);
        velocity += acceleration * TIME_STEP;
        angle -= GRAVITY * TIME_STEP / velocity;

        // Update positions
        x_position += velocity * cos(angle) * TIME_STEP;
        y_position += velocity * sin(angle) * TIME_STEP - 0.5 * GRAVITY * TIME_STEP * TIME_STEP;

        printf("%6.2f %14.2f %14.2f %14.2f %12.2f\n", time, x_position, y_position, velocity, angle * (180.0 / M_PI));
        
        // Update time
        time += TIME_STEP;

        // Stop if the aircraft hits the ground
        if (y_position <= 0) {
            break;
        }
    }
}

int main() {
    double initial_velocity = 250.0; // Initial velocity in m/s
    double initial_angle = M_PI / 6; // Initial angle in radians (30 degrees)
    double total_time = 20.0;        // Total simulation time in seconds

    // Simulate the flight path
    simulate_flight(initial_velocity, initial_angle, total_time);

    return 0;
}
