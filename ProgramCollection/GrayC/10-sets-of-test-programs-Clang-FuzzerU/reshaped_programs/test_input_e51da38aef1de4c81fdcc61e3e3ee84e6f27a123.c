#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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
    for (int i = 0; i < MAX_LENGTH; i++) {
        u.buf[i] = 'a';
    }
}

void check(int off, int len, int ch) {
    char *q = u.buf;
    for (int i = 0; i < off; i++, q++) {
        if (*q != 'a') {
            printf("Check failed at prefix alignment not 'a'\n");
            abort();
        }
    }
    for (int i = 0; i < len; i++, q++) {
        if (*q != ch) {
            printf("Check failed in mem set range not '%c'\n", ch);
            abort();
        }
    }
    for (int i = 0; i < MAX_EXTRA; i++, q++) {
        if (*q != 'a') {
            printf("Check failed at suffix alignment not 'a'\n");
            abort();
        }
    }
}

int main() {
    int off;
    char *p;

    // Test loops for various length of memset
    const int lengths[] = {1, 2, 3, 5, 6, 8};
    size_t num_lengths = sizeof(lengths) / sizeof(lengths[0]);

    for (size_t index = 0; index < num_lengths; ++index) {
        int len = lengths[index];
        for (off = 0; off < MAX_OFFSET; off++) {
            reset();

            p = (char*) memset(u.buf + off, '\0', len);
            if (p != u.buf + off) {
                printf("Memset failed, did not return expected pointer.\n");
                abort();
            }
            check(off, len, '\0');

            p = (char*) memset(u.buf + off, A, len);
            if (p != u.buf + off) {
                printf("Memset failed, did not return expected pointer.\n");
                abort();
            }
            check(off, len, 'A');

            p = (char*) memset(u.buf + off, 'B', len);
            if (p != u.buf + off) {
                printf("Memset failed, did not return expected pointer.\n");
                abort();
            }
            check(off, len, 'B');
        }
    }

    printf("All test cases passed successfully.\n");
    return 0;
}