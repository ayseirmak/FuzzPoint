#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

int main() {
    long double x = 100.0;
    long double result = sqrtl(x);  // Use standard long double sqrt function
    printf("sqrt(%Lf) = %Lf\n", x, result);
    assert(result == 10.0);

    double y = 100.0;
    result = sqrtl(y);
    printf("sqrt(%f) = %Lf\n", y, result);
    assert(result == 10.0);

    float z = 100.0f;
    result = sqrtl(z);
    printf("sqrt(%f) = %Lf\n", z, result);
    assert(result == 10.0);

    printf("Test sqrt negative zero\n");
    x = -0.0;
    assert(signbit(x));
    result = sqrtl(x);
    printf("sqrt(%Lf) = %Lf\n", x, result);
    assert(result == -0.0);
    assert(signbit(result));

    printf("Test sqrt negative\n");
    x = -DBL_MIN;
    assert(signbit(x));
    assert(x < 0.0);
    result = sqrtl(x);
    printf("sqrt(%Lf) = %Lf\n", x, result);
    assert(isnan(result));

    return 0;
}