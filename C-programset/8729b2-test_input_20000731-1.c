#include <stdio.h>

double foo(void) {
    return 0.0;
}

void do_sibcall(void) {
    (void)foo();
}

int main(void) {
    double x = 0.0;

    // Simulate the effect of the original program's logic
    x = 5.0; // An initial value that reflects the flow of the loop at least once

    for (; x < 20; x++)
        do_sibcall();

    if (!(x >= 10))
        printf("Error: x is not greater than or equal to 10\n");
    else
        printf("Finished with x = %f\n", x);
    
    return 0;
}