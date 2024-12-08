#include <stdio.h>
#include <stdlib.h>

char *f(const char *s, int i) {
    // Ensure the input string is not NULL and index is sane
    if (s == NULL || i < 0) return NULL;
    return (char *)&s[i + 2];
}

void check(const char *type, int align) {
    if ((align & -align) != align) {
        printf("Alignment check failed for type: %s\n", type);
        exit(1);
    }
}

#define QUOTE_(s) #s
#define QUOTE(s) QUOTE_(s)

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
    const char str[] = "This is a test string.";
    char *x2 = f(str, 10); // Deterministic call to function f with fixed offset

    if (str + 12 != x2) {
        printf("String pointer arithmetic does not match expected result.\n");
        exit(1);
    }

    check_type(void);
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