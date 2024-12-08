#include <stdio.h>
#include <stdlib.h>

// Function to check if alignment is a power of 2
void check_alignment(const char *type, int align) {
    if ((align & -align) != align) {
        printf("Error: Alignment for type %s is not a power of 2!\n", type);
        abort();
    }
}

#define QUOTE_(s) #s
#define QUOTE(s) QUOTE_(s)

// Macro to call check_alignment for different types
#define check_alignment_for_type(t) check_alignment(QUOTE(t), __alignof__(t))

int main() {
    // Checking alignment for various data types
    check_alignment_for_type(void);
    check_alignment_for_type(char);
    check_alignment_for_type(signed short);
    check_alignment_for_type(unsigned short);
    check_alignment_for_type(signed int);
    check_alignment_for_type(unsigned int);
    check_alignment_for_type(signed long);
    check_alignment_for_type(unsigned long);
    check_alignment_for_type(signed long long);
    check_alignment_for_type(unsigned long long);
    check_alignment_for_type(float);
    check_alignment_for_type(double);
    check_alignment_for_type(long double);
    check_alignment_for_type(void *);
    check_alignment_for_type(void (*)());

    return 0;
}