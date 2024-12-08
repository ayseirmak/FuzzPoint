#include <stdio.h>
#include <stdlib.h>

// Function to check if alignment is a power of two.
void check(const char* type, int align) {
    if ((align & -align) != align) {
        abort();
    }
}

// Redefine the check macro to include alignment checks
#define QUOTE_(s) #s
#define QUOTE(s) QUOTE_(s)
#define perform_check(t) check(QUOTE(t), __alignof__(t))

// Structure definition
struct A {
    signed long long sll;
    unsigned long long ull;
    float f;
    double d;
    long double ld;
    void* dp;
    void (*fp)();
};

int main() {
    // Perform alignment checks for various types
    perform_check(void);
    perform_check(char);
    perform_check(signed short);
    perform_check(unsigned short);
    perform_check(signed int);
    perform_check(unsigned int);
    perform_check(signed long);
    perform_check(unsigned long);
    perform_check(signed long long);
    perform_check(unsigned long long);
    perform_check(float);
    perform_check(double);
    perform_check(long double);
    perform_check(void*);
    perform_check(void (*)());
    perform_check(struct A);
    
    return 0;
}