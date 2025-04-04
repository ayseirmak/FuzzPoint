#include <stdio.h>
#include <string.h>

int b = 0, f = 0, g = 0;
float e = 0.0f;
unsigned long d = 123456789UL; // Some typical value for initialization

void foo(int *a) {
    for (g = 0; g < 32; g++) {
        if (f) {
            e = (float)d; // Cast unsigned long to float
            memcpy(&b, &e, sizeof(float));
            b = *a;
        }
    }
}

int main(void) {
    int h = 42; // Fixed value instead of reading from input
    f = 1; // Enable the action inside foo
    foo(&h);
    foo(&b);
    printf("b: %d, e: %.2f\n", b, e); // Output the result to verify program runs
    return 0;
}