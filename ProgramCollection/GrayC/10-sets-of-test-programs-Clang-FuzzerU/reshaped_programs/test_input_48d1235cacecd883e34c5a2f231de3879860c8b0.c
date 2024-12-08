#include <stdio.h>
#include <stdlib.h>

// Define the structure T
typedef struct {
    char hours, day, month;
    short year;
} T;

// Function g that returns an object of type T
T g(void) {
    T now;

    now.hours = 1;
    now.day = 2;
    now.month = 3;
    now.year = 4;
    return now;
}

// Function f that calls g and returns its result
T f(void) {
    T virk;

    virk = g();
    return virk;
}

// Define structure A
struct A {
    float a1;
    int a2;
} a;

// Global variable b
int b;

// Function bar to simulate a simple operation
int bar(float x) {
    return 2241;
}

// Function foo demonstrating control flow with simple operations
void foo(void) {
    a.a2 = bar(a.a1);
    a.a2 = a.a2 < b - 1 ? a.a2 : b - 1;
    if (a.a2 >= b - 1) {
        printf("Abort triggered in foo()\n");
        abort();
    }
}

// Main function demonstrating the usage of above functions and structures
int main(void) {
    T result = f();

    // Check the values of result
    if (result.hours != 1 || result.day != 2 || result.month != 3 || result.year != 4) {
        printf("Abort due to incorrect values in structure T\n");
        abort();
    }

    // Initialize a.a1 and b for function foo
    a.a1 = 1.0f;
    b = 3384;
    foo();

    printf("Program completed without error\n");
    return 0;
}