#include <stdio.h>
#include <assert.h>

// Constants for the program
#define HALFPI 1.57079632679f
#define NR 3

// Value based on NR (predefined)
#if NR == 1
#define VAL 0.99f
#elif NR == 2
#define VAL 1.0f
#elif NR == 3
#define VAL 1.001f
#elif NR == 4
#define VAL 1.01f
#elif NR == 5
#define VAL 1.1f
#elif NR == 6
#define VAL 1.2f
#elif NR == 7
#define VAL 1.5f
#elif NR == 8
#define VAL 2.0f
#endif

void reach_error() {
    // This function is intended to terminate the program when an error condition is reached
    assert(0);
}

void assume_abort_if_not(int cond) {
    // This simulates an assumption by terminating the program if the condition is false
    if (!cond) { 
        abort();
    }
}

int main() {
    // Deterministic input for demonstration (fixed value)
    float IN = 1.0f;  // Example of a predetermined valid input

    // Assume the input is within the defined range
    assume_abort_if_not(IN > -HALFPI && IN < HALFPI);

    // Calculate the result based on the given equation
    float x = IN;
    float result = x - (x * x * x) / 6.0f + (x * x * x * x * x) / 120.0f + (x * x * x * x * x * x * x) / 5040.0f;

    // Check if the result is within the valid range and call reach_error() if not
    if (!(result <= VAL && result >= -VAL)) { 
        reach_error();
    }

    // Normal program termination
    return 0;
}