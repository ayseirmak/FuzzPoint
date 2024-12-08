#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

typedef struct lock_chain {
    uint32_t irq_context: 2,
             depth: 6,
             base: 24;
} lock_chain;

typedef struct lock_chain1 {
    char x;
    unsigned short base;
} __attribute__((packed)) lock_chain1;

static unsigned int fixed_value = 42; // Deterministic input

unsigned int myrnd(void) {
    // Use a fixed value to meet deterministic input requirement
    return fixed_value;
}

lock_chain* foo(lock_chain *chain) {
    for (int i = 0; i < 100; i++) {
        chain[i+1].base = chain[i].base;
    }
    return chain;
}

lock_chain1* bar(lock_chain1 *chain) {
    for (int i = 0; i < 100; i++) {
        chain[i+1].base = chain[i].base;
    }
    return chain;
}

typedef struct A {
    unsigned short i: 1, l: 1, j: 3, k: 11;
} __attribute__((packed)) A;

A retmeA(A x) {
    return x;
}

unsigned int fn1A(unsigned int x) {
    A y = {0, 0, 0, 0};
    y.k += x;
    y = retmeA(y);
    return y.k;
}

unsigned int fn2A(unsigned int x) {
    A y = {0, 0, 0, 0};
    y.k += x;
    y.k %= 15;
    return y.k;
}

unsigned int retitA(void) {
    A sA = {0, 0, 0, 0};
    return sA.k;
}

void testA(void) {
    A sA = {0, 0, 0, -1};
    int i;
    unsigned int mask, v, a, r;
    A x;
    sA.k = -1;
    mask = sA.k;
    v = myrnd();
    a = myrnd();
    sA.k = v;
    x = sA;
    r = fn1A(a);
    if (x.i != sA.i || x.j != sA.j || x.k != sA.k || x.l != sA.l || ((v + a) & mask) != r) {
        abort();
    }
    v = myrnd();
    a = myrnd();
    sA.k = v;
    x = sA;
    r = fn2A(a);
    if (x.i != sA.i || x.j != sA.j || x.k != sA.k || x.l != sA.l || ((((v + a) & mask) % 15) & mask) != r) {
        abort();
    }
}

void qux(void) {
    lock_chain test[101] = {{0}};
    lock_chain1 test1[101] = {{0}};
    foo(test);
    bar(test1);
}

int main(void) {
    testA();
    qux();
    return 0;
}