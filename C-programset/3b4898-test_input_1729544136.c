
#include <stdio.h>
#include <math.h>

#define NUM_BODIES 3
#define G 6.67430e-11 // Universal gravitational constant in m^3 kg^-1 s^-2

typedef struct {
    double x, y;   // Position (in meters)
    double vx, vy; // Velocity (in meters per second)
    double mass;   // Mass (in kilograms)
} Body;

// Function to compute the gravitational force between two bodies
void compute_force(const Body *b1, const Body *b2, double *fx, double *fy) {
    double dx = b2->x - b1->x;
    double dy = b2->y - b1->y;
    double distance = sqrt(dx*dx + dy*dy);
    if (distance == 0) return; // Avoid division by zero if bodies overlap
    double force = G * b1->mass * b2->mass / (distance * distance);
    *fx += force * dx / distance;
    *fy += force * dy / distance;
}

// Function to update the positions and velocities of all bodies
void update_bodies(Body *bodies, double dt) {
    for (int i = 0; i < NUM_BODIES; ++i) {
        double fx = 0, fy = 0;

        for (int j = 0; j < NUM_BODIES; ++j) {
            if (i != j) {
                compute_force(&bodies[i], &bodies[j], &fx, &fy);
            }
        }

        double ax = fx / bodies[i].mass;
        double ay = fy / bodies[i].mass;
        bodies[i].vx += ax * dt;
        bodies[i].vy += ay * dt;
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
    }
}

int main() {
    // Initial conditions: three bodies in a line
    Body bodies[NUM_BODIES] = {
        {0, 0, 0, 0, 5e24},
        {1e7, 0, 0, 1500, 5e24},
        {2e7, 0, 0, 3000, 5e24}
    };
    
    double dt = 1; // Time step in seconds
    int num_steps = 1000;

    for (int step = 0; step < num_steps; ++step) {
        update_bodies(bodies, dt);
        // Output the state every 200 steps
        if (step % 200 == 0) {
            printf("Time: %d s\n", step * dt);
            for (int i = 0; i < NUM_BODIES; ++i) {
                printf("  Body %d: Position = (%.2e, %.2e), Velocity = (%.2e, %.2e)\n",
                       i + 1, bodies[i].x, bodies[i].y, bodies[i].vx, bodies[i].vy);
            }
        }
    }

    return 0;
}
