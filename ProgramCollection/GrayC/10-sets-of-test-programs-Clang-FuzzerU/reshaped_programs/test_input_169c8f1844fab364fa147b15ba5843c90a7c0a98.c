#include <stdio.h>
#include <stdlib.h> // For abort()

// Function to check alignment
void check(const char *type, int align) {
    if ((align & -align) != align) {
        printf("Alignment error for type: %s\n", type);
        abort();
    }
}

#define QUOTE_(s) #s
#define QUOTE(s) QUOTE_(s)

// Macro to facilitate alignment check
#define CHECK_TYPE(t) check(QUOTE(t), __alignof__(t))

int main() {
    // Checking alignment for various types
    CHECK_TYPE(void);
    CHECK_TYPE(char);
    CHECK_TYPE(signed short);
    CHECK_TYPE(unsigned short);
    CHECK_TYPE(signed int);
    CHECK_TYPE(unsigned int);
    CHECK_TYPE(signed long);
    CHECK_TYPE(unsigned long);
    CHECK_TYPE(signed long long);
    CHECK_TYPE(unsigned long long);
    CHECK_TYPE(float);
    CHECK_TYPE(double);
    CHECK_TYPE(long double);
    CHECK_TYPE(void *);
    CHECK_TYPE(void (*)());

    printf("All type alignments checked successfully.\n");

    return 0;
}