#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum { C = 1, D = 2 } B;

struct S {
    B a;
    B b;
};

typedef float v4flt __attribute__ ((vector_size (16)));

void __attribute__ ((noinline)) foo(struct S *s) {
    if (s->a != C || s->b != D) {
        abort();
    }
}

int main(void) {
    struct S s;
    s.a = C;
    s.b = D;

    foo(&s);

    printf("Function executed successfully.\n");
    return 0;
}