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
    // Initialize and set a fixed value for IN
    float IN = 0.5f; // Changed to be within [0.0f, 1.0f) range
    assert((IN >= 0.0f && IN < 1.0f));

    // Calculate x
    float x = IN;
  
    // Calculate the result using the specified formula
    float result = 1.0f + 0.5f * x - 0.125f * x * x + 0.0625f * x * x * x * x;
  
    // Check assertion condition according to defined VAL
    assert((result >= 0.0f && result < VAL));
  
    return 0;
}