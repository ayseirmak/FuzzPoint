#include <math.h>
#include <stdio.h>
#include <assert.h>

int main() {
    // Set fixed input for x (since nondeterministic inputs are not allowed). 
    // Let's use a mid-range value to test: Pi / 4
    float x = M_PI_4; // Using a known constant value
    
    // No need for __VERIFIER_assume since we've manually set x to a non-special value.
    
    float y = cosf(x);
    
    // Using standard assert instead of custom __VERIFIER_assert.
    assert(y >= -1.0f);

    printf("Assertion successful: cos(%f) = %f >= -1.0\n", x, y);
    
    return 0;
}