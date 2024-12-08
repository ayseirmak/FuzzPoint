#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

// Define vector types for compatibility
#define vector(elcount, type)  type __attribute__((vector_size((elcount)*sizeof(type))))
#define vidx(type, vec, idx) (*((type *) &(vec) + idx))

// Functions to return fixed scalar values
long vlng() { return (long)42; }
int vint() { return (int)43; }
short vsrt() { return (short)42; }
char vchr() { return (char)42; }

// Functions to check the operation results with deterministic values
void check_char_vector(vector(16, char) v0, vector(16, char) v1, char operand, char op) {
    for (int i = 0; i < 16; i++) {
        assert((operand + vidx(char, v0, i)) == vidx(char, v1, i));
    }
}

void check_short_vector(vector(8, short) v0, vector(8, short) v1, short operand, char op) {
    for (int i = 0; i < 8; i++) {
        assert((operand + vidx(short, v0, i)) == vidx(short, v1, i));
    }
}

void check_int_vector(vector(4, int) v0, vector(4, int) v1, int operand, char op) {
    for (int i = 0; i < 4; i++) {
        assert((operand * vidx(int, v0, i)) == vidx(int, v1, i));
    }
}

void check_long_vector(vector(2, long) v0, vector(2, long) v1, long operand, char op) {
    for (int i = 0; i < 2; i++) {
        assert((operand * vidx(long, v0, i)) == vidx(long, v1, i));
    }
}

int main() {
    // Static initialization of vectors with arbitrary fixed values 
    vector(16, char) c0 = {0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7};
    vector(16, char) c1;

    vector(8, short) s0 = {0, 1, 2, 3, 4, 5, 6, 7};
    vector(8, short) s1;

    vector(4, int) i0 = {0, 1, 2, 3};
    vector(4, int) i1;

    vector(2, long) l0 = {0, 1};
    vector(2, long) l1;

    // Operations with vectors and scalars
    c1 = vchr() + c0;
    check_char_vector(c0, c1, vchr(), '+');

    s1 = vsrt() + s0;
    check_short_vector(s0, s1, vsrt(), '+');

    i1 = vint() * i0;
    check_int_vector(i0, i1, vint(), '*');

    l1 = vlng() * l0;
    check_long_vector(l0, l1, vlng(), '*');

    // Struct alignment tests to demonstrate compliance with offsets
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
    if (sizeof(float) != sizeof(int)
        || offsetof(struct R, a) != sizeof(int)
        || offsetof(struct Q, a) != sizeof(int)) {
        return 0;
    }
    s.a.i = 1;
    s.a.j = 2;

    // Validate simplified operations
    assert(((struct S *)((char *)&s + sizeof(int)))->i == 2);

    return 0;
}