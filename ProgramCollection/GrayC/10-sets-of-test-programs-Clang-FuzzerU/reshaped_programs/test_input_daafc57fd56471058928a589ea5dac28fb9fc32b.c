#include <stdio.h>
#include <stdlib.h>

double a[3] = { 0.0, 1.0, 2.0 };

void bar(int x, double y) {
    abort();  // Exiting the program to maintain the functionality of the original code
}

int main() {
    double c = 0.0; // Initial declaration and initialization of 'c'
    int d;          // Declaration of 'd', initialization will follow fixed/deterministic inputs

    d = 0; // Example fixed value assignment for 'd'
    if (d < 3) {
        c = a[d];
    }

    // Call bar with fixed arguments as per original program logic
    bar(d, c);

    return 0;
}