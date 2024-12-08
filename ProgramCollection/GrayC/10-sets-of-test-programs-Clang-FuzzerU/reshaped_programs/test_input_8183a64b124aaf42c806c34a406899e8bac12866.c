#include <stdio.h>
#include <stdlib.h>

int i;
double d;

/* Array size defined by the type compatibility check */
float rootbeer[1];

typedef enum { hot, dog, poo, bear } dingos;
typedef enum { janette, laura, amanda } cranberry;

typedef float same1;
typedef float same2;

/* Function prototype */
int f(int b, int c);

int main(void) {
    /* Simulating __builtin_types_compatible_p */
    // Compatible types checks
    if (!(1 /* int, const int */
          && 0 /* typeof(hot), int */
          && 1 /* typeof(hot), typeof(laura) */
          && 1 /* int[5], int[] */
          && 1 /* same1, same2 */
        )) {
        printf("Compatible types check failed.\n");
        abort();
    }

    // Incompatible types checks
    if (0 /* char *, int */
        || 1 /* typeof(dingos), typeof(cranberry) */
        || 0 /* char, int */
    ) {
        printf("Incompatible types check failed.\n");
        abort();
    }
    
    if (!f(1, 2)) {
        printf("Function f returned false.\n");
        abort();
    }
    
    printf("All checks passed.\n");
    return 0;
}

/* Function implementation */
int f(int b, int c) {
    if (b != 0 && b != 1 && c != 0) {
        b = 0;
    }
    return b;
}