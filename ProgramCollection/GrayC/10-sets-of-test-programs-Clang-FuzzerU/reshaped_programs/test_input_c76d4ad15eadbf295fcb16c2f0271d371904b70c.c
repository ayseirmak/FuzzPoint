#include <stdio.h>
#include <stdlib.h>

#define vector(elcount, type)  \
__attribute__((vector_size((elcount)*sizeof(type)))) type

#define vidx(type, vec, idx) (*((type *) &(vec) + idx))

#define check(type, count, v0, v1, scalar, op, direction) \
do { \
    for (int i = 0; i < count; i++) { \
        if (vidx(type, v0, i) direction scalar != vidx(type, v1, i)) { \
            printf("Check failed at index %d\n", i); \
            abort(); \
        } \
    } \
} while (0)

long __attribute__ ((noinline)) vlng() { return 42L; }
int  __attribute__ ((noinline)) vint() { return 43; }
short __attribute__ ((noinline)) vsrt() { return 42; }
char __attribute__ ((noinline)) vchr() { return 42; }

int main() {
    vector(16, char) c0 = {1, 1, 2, 3, 4, 5, 6, 7, 1, 1, 2, 3, 4, 5, 6, 7};
    vector(16, char) c1;

    vector(8, short) s0 = {1, 1, 2, 3, 4, 5, 6, 7};
    vector(8, short) s1;

    vector(4, int) i0 = {1, 1, 2, 3};
    vector(4, int) i1;

    vector(2, long) l0 = {1, 1};
    vector(2, long) l1;

    c1 = vchr() + c0;
    check(char, 16, c0, c1, vchr(), +, -);

    s1 = vsrt() + s0;
    check(short, 8, s0, s1, vsrt(), +, -);

    i1 = vint() * i0;
    check(int, 4, i0, i1, vint(), *, /);

    l1 = vlng() * l0;
    check(long, 2, l0, l1, vlng(), *, /);

    printf("All checks passed.\n");
    return 0;
}