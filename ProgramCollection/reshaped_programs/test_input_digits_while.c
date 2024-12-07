#include <stdio.h>
#include <assert.h>

int main() {
    long double x = 1.0 / 7.0;
    long long res = 0;

    int i = 1;

    while (x != 0) {
        res += ((int)(x * 10) % 10) * (i * 10);
        x = (x * 10) - (int)x * 10;
        i++;
    }

    // Replace custom verifier assert with standard assert
    assert(res == 67050);
    
    printf("Assertion passed, res = %lld\n", res);
    return 0;
}