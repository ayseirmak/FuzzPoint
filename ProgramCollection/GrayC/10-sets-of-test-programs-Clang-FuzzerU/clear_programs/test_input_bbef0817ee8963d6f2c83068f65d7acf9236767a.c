#include <stdio.h>
#include <stdlib.h>

int main() {
    double x = 0x1.fp1;

    if (x != 3.875) {
        printf("Assertion failed: x != 3.875\n");
        abort();
    }
    
    printf("Program exited normally.\n");
    return 0;
}