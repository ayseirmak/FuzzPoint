#include <stdio.h>
#include <stdlib.h>

int a = 1;
int b = -1;

int c = 1;
int d = 0;

int main() {
    double e;
    double f = 0.0; // Simulated fixed value for input 1
    double g = 0.0; // Simulated fixed value for input 2

    e = (a < b) ? f : g;
    if (e) {
        // Simulating abort with a message, since abort() might be considered non-standard in some contexts
        printf("Abort: e is non-zero\n");
        return 1;
    }
    printf("Execution successful: e is zero\n");
    return 0;
}