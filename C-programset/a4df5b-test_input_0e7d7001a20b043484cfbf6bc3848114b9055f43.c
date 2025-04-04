#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef __SIZE_TYPE__ size_t;

typedef struct t {
    unsigned a : 16;
    unsigned b : 8;
    unsigned c : 8;
    long d[4];
} *T;

typedef struct {
    long r[3];
} U;

T bar(U, unsigned int);

T foo(T x) {
    U d, u;
    memcpy(&u, &x->d[1], sizeof(u));
    d = u;
    return bar(d, x->b);
}

T baz(T x) {
    U d, u;
    d.r[0] = 0x123456789;
    d.r[1] = 0xfedcba98;
    d.r[2] = 0xabcdef123;
    memcpy(&u, &x->d[1], sizeof(u));
    d = u;
    return bar(d, x->b);
}

T bar(U d, unsigned int m) {
    if (d.r[0] != 21 || d.r[1] != 22 || d.r[2] != 23) {
        abort();
    }
    return NULL; // Return NULL as a placeholder for T type
}

int main(void) {
    struct t t_instance = { 26, 0, 0, { 0, 21, 22, 23 }};
    baz(&t_instance);
    foo(&t_instance);
    return 0;
}