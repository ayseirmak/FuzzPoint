#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    double oldrho = 0.0;
    double beta = 0.0;
    double work = 4.0; // Example initialization, since no input is provided

    for (i = 1; i <= 2; i++) {
        double rho = work * work;
        if (i != 1)
            beta = rho / oldrho;
        
        // Here instead of aborting, we are using printf to log the beta value.
        if (beta == 1.0) {
            printf("Beta is exactly 1.0, which was unexpected\n");
        }

        /*
        The comment about floating-point precision still applies.
        */
        work /= 2.0;
        oldrho = rho;
    }

    return 0;
}