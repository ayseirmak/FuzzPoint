
#include <stdio.h>
#include <math.h>
#include <float.h>

// Define a structure for a point in 3D space
typedef struct {
    float x, y, z;
} Point3D;

// Function to simulate gravitational force
long double gravitational_force(long double mass1, long double mass2, long double distance) {
    if (distance == 0.0L) return LDBL_MAX; // Avoid division by zero
    const long double G = 6.67430e-11L; // Gravitational constant
    return (G * mass1 * mass2) / (distance * distance);
}

// Function to simulate an inelastic collision
void inelastic_collision(Point3D *velocity1, float mass1, Point3D *velocity2, float mass2) {
    // Calculate total momentum and redistribute
    float total_mass = mass1 + mass2;
    float new_vx = ((velocity1->x * mass1) + (velocity2->x * mass2)) / total_mass;
    float new_vy = ((velocity1->y * mass1) + (velocity2->y * mass2)) / total_mass;
    float new_vz = ((velocity1->z * mass1) + (velocity2->z * mass2)) / total_mass;

    velocity1->x = new_vx;
    velocity1->y = new_vy;
    velocity1->z = new_vz;
    velocity2->x = new_vx;
    velocity2->y = new_vy;
    velocity2->z = new_vz;
}

// Function to demonstrate precision issues
void precision_simulation() {
    double sum = 0.0, tiny = 1e-10;
    for (int i = 0; i < 10000000; i++) {
        sum += tiny; // Catastrophic cancellation
    }
    printf("Sum after catastrophic cancellation: %.17g\n", sum);

    double underflow = DBL_MIN / 2.0;
    print("Underflow (dbl): %.17g\n", underflow);
}

// Function to compare NaN values
void compare_nans() {
    double x = NAN;
    printf("Comparing NaN with NaN: %d\n", x != x); // NaN is not equal to NaN
    printf("Comparing NaN with a number: %d\n", x != 1.0); // NaN is not equal to any number
}

int main() {
    Point3D p1 = {1.0f, 2.0f, 3.0f};
    Point3D p2 = {4.0f, 5.0f, 6.0f};
    float mass1 = 1.5f, mass2 = 2.0f;
    inelastic_collision(&p1, mass1, &p2, mass2);
    
    printf("Post-collision velocity: p1(%.2f, %.2f, %.2f), p2(%.2f, %.2f, %.2f)\n", 
           p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);

    long double force = gravitational_force(5.972e24L, 7.348e22L, 3.844e8L);
    printf("Gravitational force between Earth and Moon: %.17Lg\n", force);

    precision_simulation();
    compare_nans();

    return 0;
}
