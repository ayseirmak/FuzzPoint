#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int i = 0;
double d = 0.0;

// Declare and initialize arrays with a fixed size.
float rootbeer[1] = {0.0};

typedef enum { hot, dog, poo, bear } dingos;
typedef enum { janette, laura, amanda } cranberry;

typedef float same1;
typedef float same2;

int main(void) {
    // Simulating conditions with assertions instead of built-in GCC checks.
    
    // Compatible types - we'll check by asserting known direct compatibility.
    assert(sizeof(int) == sizeof(const int));
    assert(sizeof(hot) == sizeof(int));
    assert(sizeof(hot) == sizeof(laura));
    assert(sizeof(int[5]) == sizeof(int*) && "Array decay to pointer check");
    assert(sizeof(same1) == sizeof(same2));

    // If an assertion fails, the program will terminate, mimicking `abort`.
    
    // Incompatible types checks using size comparison as an indirect way.
    assert(sizeof(char*) != sizeof(int));
    assert(sizeof(char*) != sizeof(const char*));
    assert(sizeof(long double) != sizeof(double));
    assert(sizeof(i) != sizeof(d));
    assert(sizeof(dingos) != sizeof(cranberry));
    assert(sizeof(char) != sizeof(int));
    
    printf("All checks passed successfully.\n");
    exit(0);
}