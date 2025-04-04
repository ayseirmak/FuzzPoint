#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_OFFSET (sizeof(long long))
#define MAX_COPY 15
#define MAX_EXTRA (sizeof(long long))
#define MAX_LENGTH (MAX_OFFSET + MAX_COPY + MAX_EXTRA)

static union {
    char buf[MAX_LENGTH];
    long long align_int;
    long double align_fp;
} u;

char A = 'A';

void reset() {
    for (int i = 0; i < MAX_LENGTH; i++) {
        u.buf[i] = 'a';
    }
}

void check(int off, int len, int ch) {
    char *q = u.buf;
    
    for (int i = 0; i < off; i++, q++) {
        if (*q != 'a') {
            printf("Error: Memory validation failed at offset %d, index %d\n", off, i);
            abort();
        }
    }
    
    for (int i = 0; i < len; i++, q++) {
        if (*q != ch) {
            printf("Error: Memory validation failed at length %d, index %d\n", len, i);
            abort();
        }
    }
    
    for (int i = 0; i < MAX_EXTRA; i++, q++) {
        if (*q != 'a') {
            printf("Error: Memory validation failed for extra at index %d\n", i);
            abort();
        }
    }
}

int main() {
    int len;
    char *p;

    /* Test memset with various offsets */
    for (int off = 0; off < 4; off++) {
        for (len = 0; len < MAX_COPY; len++) {
            reset();

            p = memset(u.buf + off, '\0', len);
            if (p != u.buf + off) {
                printf("Error: memset did not return the expected pointer at offset %d\n", off);
                abort();
            }
            check(off, len, '\0');

            p = memset(u.buf + off, A, len);
            if (p != u.buf + off) {
                printf("Error: memset did not return the expected pointer at offset %d\n", off);
                abort();
            }
            check(off, len, 'A');

            p = memset(u.buf + off, 'B', len);
            if (p != u.buf + off) {
                printf("Error: memset did not return the expected pointer at offset %d\n", off);
                abort();
            }
            check(off, len, 'B');
        }
    }

    printf("All tests passed.\n");
    return 0;
}