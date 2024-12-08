#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

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

double cbrtl(double x) {
    double lt = 1.0;
    lt -= (lt - (x / (lt * lt))) * 0.333333333333333333333;
    return lt;
}

int main() {
    if (sizeof(float) != sizeof(int) || offsetof(struct R, a) != sizeof(int) || offsetof(struct Q, a) != sizeof(int)) {
        return 0;
    }

    s.a.i = 1;
    s.a.j = 2;
    if (test1((void *)&s) != 3) {
        printf("Abort in test1\n");
        abort();
    }

    s.a.i = 1;
    s.a.j = 2;
    if (test2((void *)&s) != 3) {
        printf("Abort in test2\n");
        abort();
    }

    s.a.i = 1;
    s.a.j = 2;
    if (test3((void *)&s) != 3) {
        printf("Abort in test3\n");
        abort();
    }

    if ((int)(cbrtl(27.0) + 0.5) != 3) {
        printf("Abort in cbrtl check\n");
        abort();
    }

    return 0;
}