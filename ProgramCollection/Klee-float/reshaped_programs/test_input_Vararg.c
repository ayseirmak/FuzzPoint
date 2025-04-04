#include <stdarg.h>
#include <stdio.h>
#include <assert.h>

struct triple {
    int first, second, third;
};

void test1(int x, ...) {
    va_list ap;
    va_start(ap, x);
    int i32 = va_arg(ap, int);
    long long i64 = va_arg(ap, long long);
    double d = va_arg(ap, double);
    struct triple p = va_arg(ap, struct triple);
    printf("types: (%d, %lld, %.2f, (%d,%d,%d))\n", i32, i64, d, p.first, p.second, p.third);
    va_end(ap);
}

int sum(int N, ...) {
    int i, res = 0;
    va_list ap, ap2;
    
    va_start(ap, N);
    for (i = 0; i < N; i++) {
        if (i == 1)
            va_copy(ap2, ap);
        res += va_arg(ap, int);
    }
    for (i = 0; i < N - 1; i++)
        res += va_arg(ap2, int);
    va_end(ap);
    va_end(ap2);

    return res;
}

int va_array(int N, ...) {
    va_list aps[2];
    unsigned i;
    unsigned sum1 = 0, sum2 = 0;

    va_start(aps[0], N);
    va_copy(aps[1], aps[0]);

    for (i = 0; i < N; i++) {
        unsigned cmd = va_arg(aps[0], int);

        if (cmd == 0) {
            sum1 += va_arg(aps[0], int);
        } else if (cmd == 1) {
            sum2 += va_arg(aps[1], int);
        } else if (cmd == 2) {
            va_copy(aps[1], aps[0]);
        }
    }

    for (i = 0; i < 2; i++)
        va_end(aps[i]);

    return 3 * sum1 + 5 * sum2;
}

int main() {
    struct triple p = { 9, 12, 15 };
    test1(-1, 52, 37ll, 2.0, p);

    assert(sum(2, 3, 4) == 11);
    assert(sum(0) == 0);
    assert(va_array(5, 0, 5, 1, 1, 2, 1) == 45); // 15 + 30

    return 0;
}