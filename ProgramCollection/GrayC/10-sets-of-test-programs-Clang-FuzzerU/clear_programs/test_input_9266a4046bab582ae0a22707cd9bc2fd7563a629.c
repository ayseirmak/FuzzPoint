#include <stdio.h>
#include <stdlib.h>

// Define the struct A with various data types.
struct A {
    signed long long sll;
    unsigned long long ull;
    float f;
    double d;
    long double ld;
    void *dp;
    void (*fp)();
};

// Function to check alignment of a type.
void check(const char *type, int align) {
    if ((align & -align) != align) {
        printf("Alignment check failed for type: %s\n", type);
        abort();
    }
}

#define QUOTE_(s) #s
#define QUOTE(s) QUOTE_(s)
#define check_type(t) check(QUOTE(t), __alignof__(t))

int main() {
    // Check alignment of different types.
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

    printf("All alignment checks passed successfully.\n");
    return 0;
}