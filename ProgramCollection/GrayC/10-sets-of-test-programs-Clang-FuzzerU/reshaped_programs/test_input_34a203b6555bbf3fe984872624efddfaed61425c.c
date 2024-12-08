#include <stdio.h>
#include <stdlib.h>

struct S {
    float f;
};

int __attribute__((noinline)) foo(int *r, struct S *p) {
    int *q = (int *)&p->f;
    int i = *q;
    *r = 0;
    return i + *q;
}

int main() {
    struct S s;
    int i = 1;
    
    // Initialize s.f with a fixed value to ensure determinism
    s.f = 1.0f;  // Example value
    
    // Ensure foo function receives initialized struct and int pointer
    if (foo(&i, &s) != 0) {
        abort();
    }
    return 0;
}