
#include <stdio.h>
#include <math.h>

#define NUM_PARTICLES 5
#define GRAVITY 9.81
#define BOUNCE_EFFICIENCY 0.8
#define TIME_STEP 0.01
#define BOX_SIZE 100.0

typedef struct {
    double x, y;      // Position
    double vx, vy;    // Velocity
    double radius;    // Radius
    double mass;      // Mass
} Particle;

// Function to update the position and velocity of particles
void update_particles(Particle *particles) {
    for (int i = 0; i < NUM_PARTICLES; i++) {
        particles[i].vy -= GRAVITY * TIME_STEP;
        particles[i].x += particles[i].vx * TIME_STEP;
        particles[i].y += particles[i].vy * TIME_STEP;

        // Handle collisions with walls
        if (particles[i].x - particles[i].radius < 0 || particles[i].x + particles[i].radius > BOX_SIZE) {
            particles[i].vx = -particles[i].vx * BOUNCE_EFFICIENCY;
            particles[i].x = fmax(particles[i].radius, fmin(particles[i].x, BOX_SIZE - particles[i].radius));
        }
        if (particles[i].y - particles[i].radius < 0 || particles[i].y + particles[i].radius > BOX_SIZE) {
            particles[i].vy = -particles[i].vy * BOUNCE_EFFICIENCY;
            particles[i].y = fmax(particles[i].radius, fmin(particles[i].y, BOX_SIZE - particles[i].radius));
        }
    }
}

// Function to handle collisions between particles
void handle_collisions(Particle *particles) {
    for (int i = 0; i < NUM_PARTICLES; i++) {
        for (int j = i + 1; j < NUM_PARTICLES; j++) {
            double dx = particles[j].x - particles[i].x;
            double dy = particles[j].y - particles[i].y;
            double distance = sqrt(dx * dx + dy * dy);

            if (distance < particles[i].radius + particles[j].radius) {
                // Elastic collision resolution
                double nx = dx / distance;
                double ny = dy / distance;
                
                double p = 2 * ((particles[i].vx * nx + particles[i].vy * ny) - 
                                (particles[j].vx * nx + particles[j].vy * ny)) / 
                           (particles[i].mass + particles[j].mass);
                
                particles[i].vx -= p * particles[j].mass * nx;
                particles[i].vy -= p * particles[j].mass * ny;
                particles[j].vx += p * particles[i].mass * nx;
                particles[j].vy += p * particles[i].mass * ny;
            }
        }
    }
}

int main() {
    // Initialize particles with fixed positions and velocities
    Particle particles[NUM_PARTICLES] = {
        {10.0, 10.0, 20.0, 10.0, 1.0, 1.0},
        {30.0, 20.0, -15.0, 5.0, 1.0, 1.0},
        {50.0, 70.0, 10.0, -10.0, 1.0, 1.0},
        {70.0, 50.0, -20.0, 15.0, 1.0, 1.0},
        {90.0, 30.0, 25.0, -20.0, 1.0, 1.0}
    };

    // Simulate for a fixed number of steps
    int num_steps = 1000;
    for (int step = 0; step < num_steps; ++step) {
        handle_collisions(particles);
        update_particles(particles);
        
        // Print the state every 200 steps
        if (step % 200 == 0) {
            printf("Step %d:\n", step);
            for (int i = 0; i < NUM_PARTICLES; ++i) {
                printf("  Particle %d: Position = (%.2f, %.2f), Velocity = (%.2f, %.2f)\n",
                       i + 1, particles[i].x, particles[i].y, particles[i].vx, particles[i].vy);
            }
        }
    }

    return 0;
}
