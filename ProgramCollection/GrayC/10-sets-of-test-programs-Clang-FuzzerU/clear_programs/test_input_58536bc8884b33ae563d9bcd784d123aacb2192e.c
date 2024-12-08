#include <stdio.h>
#include <stdlib.h>

double x = 0x1.fp1;

int main() {
    if (x != 3.875) {
        printf("Error: x is not equal to 3.875\n");
        abort();
    }
    return 0;
}