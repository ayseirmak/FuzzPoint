#include <stdio.h>
#include <limits.h>

// Function to mimic the functionality of the fragmented code (foo and bar)
int foo(unsigned long long x) {
    unsigned long long y = (x >> 31ULL) & 1ULL;
    return (y == 0ULL) ? 0 : -1;
}

int bar(long long x) {
    long long y = (x >> 31LL) & 1LL;
    return (y == 0LL) ? 0 : -1;
}

// Main function to perform deterministic checks
int main(void) {
    // Ensure we're running in an environment where long long is 8 bytes
    if (sizeof(long long) != 8) {
        return 0;
    }
   
    // Deterministic tests using fixed input values
    if (foo(0x1682a9aaaULL)) {
        printf("Test foo failed for input 0x1682a9aaaULL\n");
        abort();
    }

    if (!foo(0x1882a9aaaULL)) {
        printf("Test foo failed for input 0x1882a9aaaULL\n");
        abort();
    }

    if (bar(0x1682a9aaaLL)) {
        printf("Test bar failed for input 0x1682a9aaaLL\n");
        abort();
    }

    if (!bar(0x1882a9aaaLL)) {
        printf("Test bar failed for input 0x1882a9aaaLL\n");
        abort();
    }

    printf("All tests passed.\n");
    return 0;
}