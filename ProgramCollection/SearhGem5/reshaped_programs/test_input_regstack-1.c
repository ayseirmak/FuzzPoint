#include <stdio.h>
#include <assert.h>

int main() {
    // Initialize variables with typical values
    long double C = 25.0L;
    long double U = 10.0L;
    long double Y2 = 11.0L;
    long double Y1 = 20.0L;
    long double X, Y, Z, T, R, S;

    // Perform the computations
    X = (C + U) * Y2;
    Y = C - U - U;
    Z = C + U + U;
    T = (C - U) * Y1;
    X = X - (Z + U);
    R = Y * Y1;
    S = Z * Y2;
    T = T - Y;
    Y = (U - Y) + R;
    Z = S - (Z + U + U);
    R = (Y2 + U) * Y1;
    Y1 = Y2 * Y1;
    R = R - Y2;
    Y1 = Y1 - 0.5L;

    // Use assert to validate final conditions
    assert(Z == 68.0L);
    assert(Y == 49.0L);
    assert(X == 58.0L);
    assert(Y1 == 186.5L);
    assert(R == 193.0L);
    assert(S == 77.0L);
    assert(T == 65.0L);
    assert(Y2 == 11.0L);

    // Return success
    return 0;
}