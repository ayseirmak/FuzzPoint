#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

// Function to check if alignment is a power of two
void check(const char *type, int align) {
    if ((align & -align) != align) {
        printf("Alignment of %s is not a power of two.\n", type);
        abort();
    }
}

#define QUOTE_(s) #s
#define QUOTE(s) QUOTE_(s)

// Using a macro to apply the check function to different types
#define check_type(t) check(QUOTE(t), __alignof__(t))

// Definition of struct A
struct A {
    char c;
    signed short ss;
    unsigned short us;
    signed int si;
    unsigned int ui;
    signed long sl;
    unsigned long ul;
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

    return 0;
}