#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
            printf("Error: Buffer not initialized correctly before offset\n");
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < len; i++, q++) {
        if (*q != ch) {
            printf("Error: Incorrect character found in range checked\n");
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < MAX_EXTRA; i++, q++) {
        if (*q != 'a') {
            printf("Error: Buffer not correctly initialized after length\n");
            exit(EXIT_FAILURE);
        }
    }
}

int main() {
    for (int off = 0; off < MAX_OFFSET; off++) {
        for (int len = 1; len <= 8; len++) {
            reset();
            memset(u.buf + off, '\0', len);
            if (u.buf + off != memset(u.buf + off, '\0', len)) {
                printf("Error: memset did not return the correct pointer\n");
                exit(EXIT_FAILURE);
            }
            check(off, len, '\0');

            memset(u.buf + off, A, len);
            if (u.buf + off != memset(u.buf + off, A, len)) {
                printf("Error: memset did not return the correct pointer\n");
                exit(EXIT_FAILURE);
            }
            check(off, len, 'A');

            memset(u.buf + off, 'B', len);
            if (u.buf + off != memset(u.buf + off, 'B', len)) {
                printf("Error: memset did not return the correct pointer\n");
                exit(EXIT_FAILURE);
            }
            check(off, len, 'B');
        }
    }

    printf("All tests passed successfully.\n");
    return 0;
}