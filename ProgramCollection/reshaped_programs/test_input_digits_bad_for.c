#include <stdio.h>
#include <assert.h>

void reach_error() {
    printf("Reached error.\n");
}

void verifier_assert(int cond) {
    if (!cond) {
        reach_error();
        assert(0);
    }
}

int main()
{
    long double x = 1.0 / 7.0;
    long long res = 0;

    for (int i = 1; x != 0; i++) {
        res += ((int)(x * 10) % 10) * (i * 10);
        x = (x * 10) - (int)(x * 10);
    }

    verifier_assert(res > 67050);
    return 0;
}