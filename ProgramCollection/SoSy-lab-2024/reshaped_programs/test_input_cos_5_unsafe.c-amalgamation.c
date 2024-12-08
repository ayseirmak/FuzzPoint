#include <stdio.h>
#include <math.h>
#include <assert.h>

#define COS_CHECK_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062f
#define COS_CHECK_ERROR 1e-6f

int main() /* check_inverse */
{
    // Set a fixed value within the valid range for the input variable to make the program deterministic
    float x = 1.0f;

    // Ensure the input x value is within the valid range
    if (!(x >= 0.0f && x <= COS_CHECK_PI)) {
        printf("Input value not within the specified range.\n");
        return 1;  // Exit with error if not in range
    }

    // Perform the operations as specified
    float y = acosf(cosf(x));
    float z = fabsf(x - y);

    // Use assert to check the condition
    assert(z <= COS_CHECK_ERROR);

    // Log a message indicating successful verification
    printf("Assertion successful: z (%.10f) is within the allowed error margin.\n", z);

    return 0;
}