#include <stdio.h>
#include <stdlib.h>

// Function to check if alignment is a power of 2
void check(const char *type, int align) {
    if ((align & -align) != align) {
        printf("Alignment of %s is not a power of 2!\n", type);
        abort();
    }
}

#define QUOTE_(s) #s
#define QUOTE(s) QUOTE_(s)

// Create macro for consistency in testing
#define CHECK_ALIGNMENT(type) check(QUOTE(type), __alignof__(type))

int main() {
    // Check alignments for various types
    CHECK_ALIGNMENT(void);
    CHECK_ALIGNMENT(char);
    CHECK_ALIGNMENT(signed short);
    CHECK_ALIGNMENT(unsigned short);
    CHECK_ALIGNMENT(signed int);
    CHECK_ALIGNMENT(unsigned int);
    CHECK_ALIGNMENT(signed long);
    CHECK_ALIGNMENT(unsigned long);
    CHECK_ALIGNMENT(signed long long);
    CHECK_ALIGNMENT(unsigned long long);
    CHECK_ALIGNMENT(float);
    CHECK_ALIGNMENT(double);
    CHECK_ALIGNMENT(long double);
    CHECK_ALIGNMENT(void *);
    CHECK_ALIGNMENT(void (*)());
    struct { double ld; void *dp; void (*fp)(); } dummy_struct;
    check("struct dummy_struct", __alignof__(dummy_struct));

    printf("All alignments checked successfully!\n");
    return 0;
}