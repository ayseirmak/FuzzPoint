#include <assert.h>

#define HALFPI 1.57079632679f

#define NR 2

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

int main() {
    // Use a deterministic value for IN
    float IN = 0.5f; // Ensure this is within the range (-HALFPI, HALFPI)
    
    // Since IN is fixed and within range, we skip assume_abort_if_not

    float x = IN;
    
    float result = x - (x * x * x) / 6.0f + (x * x * x * x * x) / 120.0f + (x * x * x * x * x * x * x) / 5040.0f;

    // Use standard assertion
    assert(result <= VAL && result >= -VAL);
  
    return 0;
}