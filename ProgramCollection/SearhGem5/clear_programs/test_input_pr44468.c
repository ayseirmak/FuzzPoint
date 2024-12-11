#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>  // For exit function

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

int main() {
    if (sizeof(float) != sizeof(int)
        || offsetof(struct R, a) != sizeof(int)
        || offsetof(struct Q, a) != sizeof(int)) {
        return 0;
    }

    s.a.i = 1;
    s.a.j = 2;
    if (test1((void *)&s) != 3) {
        printf("Test 1 failed\n");
        exit(EXIT_FAILURE);
    }

    s.a.i = 1;
    s.a.j = 2;
    if (test2((void *)&s) != 3) {
        printf("Test 2 failed\n");
        exit(EXIT_FAILURE);
    }

    s.a.i = 1;
    s.a.j = 2;
    if (test3((void *)&s) != 3) {
        printf("Test 3 failed\n");
        exit(EXIT_FAILURE);
    }

    printf("All tests passed.\n");
    return 0;
}