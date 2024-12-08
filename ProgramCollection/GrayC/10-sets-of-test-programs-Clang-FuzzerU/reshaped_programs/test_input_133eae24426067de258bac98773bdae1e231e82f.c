#include <stdio.h>

double a[3] = { 0.0, 1.0, 2.0 };

void bar(int x) {
    printf("Value from bar function: %d\n", x);
}

int main() {
    double c = 0.0;  // Initialize variable c
    int d = 0;       // Initialize variable d

    // Perform a simple operation to showcase the use of c and d
    c = a[1] + a[2];  // Assign a fixed calculation for demonstration
    d = (int)c;       // Cast double to int

    printf("Value of c: %.2f\n", c);
    printf("Value of d: %d\n", d);

    // Call the bar function with a fixed value
    bar(d);

    return 0;
}