#include <assert.h>

#define NR 1

#if NR == 1
#define VAL 1.39f
#elif NR == 2
#define VAL 1.398f
#elif NR == 3
#define VAL 1.39843f
#elif NR == 4
#define VAL 1.39844f
#elif NR == 5
#define VAL 1.3985f
#elif NR == 6
#define VAL 1.399f
#elif NR == 7
#define VAL 1.4f
#elif NR == 8
#define VAL 1.5f
#endif

int main() {
    // Fixed input value
    float IN = 0.5f;  // Adjusted to a valid range [0.0, 1.0) for demo purposes
    // Validate input range
    if (!(IN >= 0.0f && IN < 1.0f)) {
        return 1;  // Exiting the program, use abort() if necessary
    }

    float x = IN;
    // Polynomial expression for result computation
    float result = 1.0f + 0.5f * x - 0.125f * x * x + 0.0625f * x * x * x - 0.0390625f * x * x * x * x;
    // Check result range against VAL
    if (!(result >= 0.0f && result < VAL)) {
        assert(0);  // Assertion to standard C library
    }

    return 0;
}