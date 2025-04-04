#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void check(const char *type, int align) {
    if ((align & -align) != align) {
        printf("Alignment of type %s is not a power of two.\n", type);
        abort();
    }
}

#define QUOTE_(s) #s
#define QUOTE(s) QUOTE_(s)

#define CHECK_TYPE(t) check(QUOTE(t), __alignof__(t))

struct A {
    signed long long sll;
    unsigned long long ull;
    float f;
    double d;
    long double ld;
    void *dp;
    void (*fp)();
};

int main() {
    CHECK_TYPE(void);
    CHECK_TYPE(char);
    CHECK_TYPE(signed long);
    CHECK_TYPE(signed long long);
    CHECK_TYPE(unsigned long long);
    CHECK_TYPE(float);
    CHECK_TYPE(double);
    CHECK_TYPE(long double);
    CHECK_TYPE(void *);
    CHECK_TYPE(void (*)());
    CHECK_TYPE(struct A);
    
    printf("All alignment checks passed.\n");
    return 0;
}