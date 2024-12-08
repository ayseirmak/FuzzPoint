#include <stdio.h>
#include <stdlib.h>

void check(const char *type, int align) {
    // __alignof__ returns alignment and should be a power of 2
    if ((align & -align) != align) {
        printf("Alignment of %s is not a power of 2: %d\n", type, align);
        abort();
    }
}

#define QUOTE_(s) #s
#define QUOTE(s) QUOTE_(s)

#define __alignof__(t) __alignof__(t)

#define check_type(t) check(QUOTE(t), __alignof__(t))

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
    check_type(void);
    check_type(char);
    check_type(signed short);
    check_type(unsigned short);
    check_type(signed int);
    check_type(unsigned int);
    check_type(signed long);
    check_type(unsigned long);
    check_type(signed long long);
    check_type(unsigned long long);
    check_type(float);
    check_type(double);
    check_type(long double);
    check_type(void *);
    check_type(void (*)());
    check_type(struct A);

    printf("All checks passed.\n");
    return 0;
}