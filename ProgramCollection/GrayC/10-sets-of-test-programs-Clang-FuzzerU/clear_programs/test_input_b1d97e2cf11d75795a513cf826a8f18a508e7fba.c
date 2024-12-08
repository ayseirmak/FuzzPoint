#include <stdio.h>

struct point {
    double x;
    double y;
};

struct point point_array[100]; // Declare an array of struct point

int main() {
    int my_point = 10; // Initialize my_point with a fixed value

    // Initialize the x and y values for the point at index 'my_point'
    point_array[my_point].x = 12.34;
    point_array[my_point].y = 56.56;

    // Output the x and y coordinates of the point at index 'my_point'
    printf("%f, %f\n", point_array[my_point].x, point_array[my_point].y);

    return 0; // Exit the program
}