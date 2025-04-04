#include <stdio.h>
#include <stdlib.h>

void abort_execution(void) {
    printf("Abort: Condition x != d failed.\n");
    exit(1);
}

int main(void) {
    // Initialize variables with fixed values for demonstration purposes
    double d = 4.0 / 2.0;  // This represents atof(argv[1]) / 2.0
    double x = 4.0 / 2.0;  // This represents atof(argv[2]) / 2.0
    
    // Check if x is not equal to d
    if (x != d) {
        abort_execution(); // Call abort_execution instead of abort() to comply with the guidelines
    }
    
    return 0;
}