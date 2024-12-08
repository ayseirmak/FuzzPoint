#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Adjust to match target architecture if necessary, ARM compliance assumed.
#ifndef MAX_OFFSET
#define MAX_OFFSET (sizeof(long long))
#endif

#ifndef MAX_COPY
#define MAX_COPY 15
#endif

#ifndef MAX_EXTRA
#define MAX_EXTRA (sizeof(long long))
#endif

#define MAX_LENGTH (MAX_OFFSET + MAX_COPY + MAX_EXTRA)

static union {
    char buf[MAX_LENGTH];
    long long align_int;
    long double align_fp;
} u;

char A = 'A';

void reset() {
    int i;
    for (i = 0; i < MAX_LENGTH; i++)
        u.buf[i] = 'a';
}

void check(int off, int len, int ch) {
    char *q = u.buf;
    int i;

    for (i = 0; i < off; i++, q++)
        if (*q != 'a') {
            fprintf(stderr, "check failed at offset %d\n", i);
            exit(EXIT_FAILURE);
        }

    for (i = 0; i < len; i++, q++)
        if (*q != ch) {
            fprintf(stderr, "check failed in range at offset %d\n", i + off);
            exit(EXIT_FAILURE);
        }

    for (i = 0; i < MAX_EXTRA; i++, q++)
        if (*q != 'a') {
            fprintf(stderr, "check failed after fill at offset %d\n", i + off + len);
            exit(EXIT_FAILURE);
        }
}

int main() {
    int off;
    char *p;

    // Testing various lengths
    for (int len = 1; len <= 8; len++) {
        for (off = 0; off < MAX_OFFSET; off++) {
            reset();

            p = memset(u.buf + off, '\0', len);
            if (p != u.buf + off) {
                fprintf(stderr, "memset failed for \\0 at offset %d\n", off);
                exit(EXIT_FAILURE);
            }
            check(off, len, '\0');

            p = memset(u.buf + off, A, len);
            if (p != u.buf + off) {
                fprintf(stderr, "memset failed for 'A' at offset %d\n", off);
                exit(EXIT_FAILURE);
            }
            check(off, len, 'A');

            p = memset(u.buf + off, 'B', len);
            if (p != u.buf + off) {
                fprintf(stderr, "memset failed for 'B' at offset %d\n", off);
                exit(EXIT_FAILURE);
            }
            check(off, len, 'B');
        }
    }

    printf("All checks passed successfully.\n");
    return EXIT_SUCCESS;
}