#include <assert.h>
#include <stdio.h>

#define HALFPI 1.57079632679f
#define NR 1

#if NR == 1
#define VAL 0.99
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

int main() {
    // Fixed input value between -HALFPI and HALFPI
    float IN = 0.5f; // Chosen value within the range
    assert(IN > -HALFPI && IN < HALFPI);

    float x = IN;
    float result = x - (x * x * x) / 6.0f + (x * x * x * x * x) / 120.0f + (x * x * x * x * x * x * x) / 5040.0f;

    if (!(result <= VAL && result >= -VAL)) {
        // If condition is violated, print an error message
        printf("Error: Result is out of bounds.\n");
        assert(0); // Simulate reach_error
    } else {
        // If condition is satisfied, print success message
        printf("Success: Result is within bounds.\n");
    }

    return 0;
}