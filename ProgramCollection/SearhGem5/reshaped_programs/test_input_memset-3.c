#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constants for buffer manipulation
#define MAX_OFFSET (sizeof(long long))
#define MAX_COPY 15
#define MAX_EXTRA (sizeof(long long))
#define MAX_LENGTH (MAX_OFFSET + MAX_COPY + MAX_EXTRA)

// Union to ensure proper memory alignment
static union {
    char buf[MAX_LENGTH];
    long long align_int;
    long double align_fp;
} u;

// Character to be used in memset
char A = 'A';

// Reset function to initialize buffer with 'a'
void reset() {
    for (int i = 0; i < MAX_LENGTH; i++)
        u.buf[i] = 'a';
}

// Check function to verify buffer content
void check(int off, int len, int ch) {
    char *q = u.buf;
    
    // Verify prefix
    for (int i = 0; i < off; i++, q++) {
        if (*q != 'a') {
            printf("Error: Prefix does not match\n");
            exit(EXIT_FAILURE);
        }
    }

    // Verify modified segment
    for (int i = 0; i < len; i++, q++) {
        if (*q != ch) {
            printf("Error: Modified segment does not match\n");
            exit(EXIT_FAILURE);
        }
    }

    // Verify suffix
    for (int i = 0; i < MAX_EXTRA; i++, q++) {
        if (*q != 'a') {
            printf("Error: Suffix does not match\n");
            exit(EXIT_FAILURE);
        }
    }
}

int main() {
    int len;
    char *p;

    // Offsets from 0 to 7
    for (int off = 0; off <= 7; off++) {
        for (len = 0; len < MAX_COPY; len++) {
            reset();

            // Set to '\0'
            p = memset(u.buf + off, '\0', len);
            if (p != u.buf + off) {
                printf("Error: Return value mismatch\n");
                exit(EXIT_FAILURE);
            }
            check(off, len, '\0');

            // Set to A
            p = memset(u.buf + off, A, len);
            if (p != u.buf + off) {
                printf("Error: Return value mismatch\n");
                exit(EXIT_FAILURE);
            }
            check(off, len, 'A');

            // Set to 'B'
            p = memset(u.buf + off, 'B', len);
            if (p != u.buf + off) {
                printf("Error: Return value mismatch\n");
                exit(EXIT_FAILURE);
            }
            check(off, len, 'B');
        }
    }

    return 0;
}