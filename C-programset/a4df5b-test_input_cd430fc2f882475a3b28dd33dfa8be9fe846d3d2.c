#include <stdio.h>
#include <stdarg.h>

struct foo {
    int i, j, k;
    char *p;
    float v;
};

int f1(struct foo *f, struct foo *p, int n, ...) {
    if (f->i != p->i) {
        return 0;
    }
    va_list args;
    va_start(args, n);
    // Since we ignore the variadic arguments in this deterministic context, we simply print
    printf("f1 is called with n = %d\n", n);
    va_end(args);
    return p->j + n;
}

int main(void) {
    struct foo f;
    
    f.i = 1;
    f.j = 1;
    f.k = 0;
    f.p = NULL;
    f.v = 0.0f;
    
    int result1 = f1(&f, &f, 2);
    printf("Result1: %d\n", result1);
    
    int result2 = f1(&f, &f, 2, 1, f, &f);  // Note: Extra arguments are ignored.
    printf("Result2: %d\n", result2);

    return 0;
}