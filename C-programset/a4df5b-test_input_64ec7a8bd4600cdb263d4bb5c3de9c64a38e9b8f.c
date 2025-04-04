#include <stdio.h>
#include <string.h>

int b = 0, f = 0, g = 0;
float e = 0.0;
unsigned long d = 0;

void foo(int *a) {
    for (g = 0; g < 32; g++) {
        if (f) {
            // Memory barrier
            __asm__ volatile ("" : : : "memory");
        }
    }
    
    // Eliminating recursive or redundant calls
    // asm volatile ("" : : : "memory");
    // foo(&b);
    // asm volatile ("" : : : "memory");

    e = d;
    memcpy(&b, &e, sizeof(float));
    b = *a;
}

int main() {
    int h = 5;
    f = 1;
    
    // Memory barrier
    __asm__ volatile ("" : : : "memory");
    
    foo(&h);
    
    // Eliminating redundant assembly and function call from main
    // asm volatile ("" : : : "memory");
    // foo(&b);
    // asm volatile ("" : : : "memory");
    
    printf("Value of b: %d\n", b);
    return 0;
}