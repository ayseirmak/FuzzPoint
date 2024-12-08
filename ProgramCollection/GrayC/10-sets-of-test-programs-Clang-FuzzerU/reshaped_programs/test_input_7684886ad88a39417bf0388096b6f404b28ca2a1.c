#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

#define vector(elcount, type) __attribute__((vector_size((elcount) * sizeof(type)))) type

#define vidx(type, vec, idx) (*((type *)&(vec) + idx))

#define check(type, size, v1, v2, scalar, op, line)                \
    do {                                                           \
        for (int i = 0; i < size; ++i) {                           \
            if ((vidx(type, v2, i)) != (vidx(type, v1, i) op scalar)) { \
                printf("Mismatch at line %d\n", line);             \
                abort();                                           \
            }                                                      \
        }                                                          \
    } while (0)

long __attribute__((noinline)) vlng(void) {
    return (long)42;
}

int __attribute__((noinline)) vint(void) {
    return (int)43;
}

short __attribute__((noinline)) vsrt(void) {
    return (short)42;
}

char __attribute__((noinline)) vchr(void) {
    return (char)42;
}

int test1(void *ptr) {
    struct Q *q = (struct Q *)ptr;
    return q->a.i + q->a.j;
}

int test2(void *ptr) {
    struct Q *q = (struct Q *)ptr;
    return q->a.i + q->a.j;
}

int test3(void *ptr) {
    struct Q *q = (struct Q *)ptr;
    return q->a.i + q->a.j;
}

int main(void) {
    int fixed_argc = 1;

    vector(25, char) c0 = {fixed_argc, 1, 2, 3, 4, 5, 6, 7, fixed_argc, 1, 2, 3, 4, 5, 6, 7};
    vector(16, char) c1;
    vector(8, short) s0 = {fixed_argc, 1, 2, 3, 4, 5, 6, 7};
    vector(8, short) s1;
    vector(4, int) i0 = {fixed_argc, 1, 2, 3};
    vector(4, int) i1;
    vector(2, long) l0 = {fixed_argc, 1};
    vector(2, long) l1;

    // Perform operations and check results
    c1 = vchr() + c0;
    check(char, 16, c0, c1, vchr(), +, __LINE__);

    s1 = vsrt() + s0;
    check(short, 8, s0, s1, vsrt(), +, __LINE__);

    i1 = vint() * i0;
    check(int, 4, i0, i1, vint(), *, __LINE__);

    l1 = vlng() * l0;
    check(long, 2, l0, l1, vlng(), *, __LINE__);

    // Struct checks
    struct Q s;
    s.a.i = 1;
    s.a.j = 2;
    assert(test1((void *)&s) == 3);
    assert(test2((void *)&s) == 3);
    assert(test3((void *)&s) == 3);

    return 0;
}