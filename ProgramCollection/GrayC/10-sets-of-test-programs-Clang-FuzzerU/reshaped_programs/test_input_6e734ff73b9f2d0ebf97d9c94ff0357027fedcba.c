#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// Define the vector and element access macros
#define vector(elcount, type) __attribute__((vector_size((elcount) * sizeof(type)))) type
#define vidx(type, vec, idx) (*((type *) &(vec) + idx))

// Define the functions to return fixed values
long vlng() { return (long)42; }
int vint() { return (int) 43; }
short vsrt() { return (short)42; }
char vchr() { return (char)42; }

int main() {
    // Define and initialize variables with fixed values instead of argc
    vector(16, char) c0 = {42, 1, 2, 3, 4, 5, 6, 7, 42, 1, 2, 3, 4, 5, 6, 7};
    vector(16, char) c1;
    
    vector(8, short) s0 = {42, 1, 2, 3, 4, 5, 6, 7};
    vector(8, short) s1;

    vector(4, int) i0 = {42, 1, 2, 3};
    vector(4, int) i1;

    vector(2, long) l0 = {42, 1};
    vector(2, long) l1;

    // Arithmetic operations on vectors
    c1 = vchr() + c0;
    s1 = vsrt() + s0;
    i1 = vint() * i0;
    l1 = vlng() * l0;

    // Code snippet for struct and function tests
    struct S {
        int i;
        int j;
    };

    struct R {
        int k;
        struct S a;
    };

    struct Q {
        float k;
        struct S a;
    };

    struct Q s;

    // Inline functions for testing
    int test1(void *q) {
        struct S *b = (struct S *)((char *)q + sizeof(int));
        s.a.i = 0;
        b->i = 3;
        return s.a.i;
    }

    int test2(void *q) {
        struct S *b = &((struct R *)q)->a;
        s.a.i = 0;
        b->i = 3;
        return s.a.i;
    }

    int test3(void *q) {
        s.a.i = 0;
        ((struct S *)((char *)q + sizeof(int)))->i = 3;
        return s.a.i;
    }

    // Size and offset checks
    if (sizeof(float) != sizeof(int) || offsetof(struct R, a) != sizeof(int) || offsetof(struct Q, a) != sizeof(int)) {
        return 0;
    }

    // Function checks
    s.a.i = 1;
    s.a.j = 2;
    if (test1((void *)&s) != 3) {
        abort();
    }

    s.a.i = 1;
    s.a.j = 2;
    if (test2((void *)&s) != 3) {
        abort();
    }

    s.a.i = 1;
    s.a.j = 2;
    if (test3((void *)&s) != 3) {
        abort();
    }

    return 0;
}