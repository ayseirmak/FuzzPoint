#include <stdio.h>
#include <stdlib.h>

typedef enum { hot, dog, poo, bear } dingos;
typedef enum { janette, laura, amanda } cranberry;

typedef float same1;
typedef float same2;

int main (void) {
    // Example of compatible type demonstration
    // This statement checks if two types are compatible (using built-in types feature).
    int a;
    const int b = 10;
    
    if (__builtin_types_compatible_p(typeof(a), typeof(b))) {
        printf("The types are compatible.\n");
    } else {
        printf("The types are not compatible.\n");
    }

    return 0;
}