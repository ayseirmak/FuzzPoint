#include <stdio.h>

struct point {
   double x;
   double y;
};

struct point point_array[100];

int main() {
   int my_point = 0; // Initialize to a default valid index

   // Initialize the selected point in the array
   point_array[my_point].x = 12.34;
   point_array[my_point].y = 56.78;

   // Print the point values
   printf("%f, %f\n", point_array[my_point].x, point_array[my_point].y);

   return 0; // Indicate successful execution
}