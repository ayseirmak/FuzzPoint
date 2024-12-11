#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#ifndef MAX_OFFSET
#define MAX_OFFSET (sizeof (long long))
#endif

#ifndef MAX_COPY
#define MAX_COPY (10 * sizeof (long long))
#endif

#ifndef MAX_EXTRA
#define MAX_EXTRA (sizeof (long long))
#endif

#define MAX_LENGTH (MAX_OFFSET + MAX_COPY + MAX_EXTRA)

#define SEQUENCE_LENGTH 31

static union {
    char buf[MAX_LENGTH];
    long long align_int;
    long double align_fp;
} u1, u2;

int main() {
    // Initialize character buffers
    for (int i = 0; i < MAX_LENGTH; i++) {
        u1.buf[i] = 'a';
        u2.buf[i] = 'A' + (i % SEQUENCE_LENGTH);
    }

    for (int off1 = 0; off1 < MAX_OFFSET; off1++) {
        for (int off2 = 0; off2 < MAX_OFFSET; off2++) {
            for (int len = 1; len < MAX_COPY; len++) {

                // Copy a portion of u2.buf to u1.buf with the given offsets and length
                char *p = memcpy(u1.buf + off1, u2.buf + off2, len);
                assert(p == u1.buf + off1);

                char *q = u1.buf;
                for (int i = 0; i < off1; i++, q++) {
                    assert(*q == 'a');
                }

                for (int i = 0, c = 'A' + off2; i < len; i++, q++, c++) {
                    if (c >= 'A' + SEQUENCE_LENGTH)
                        c = 'A';
                    assert(*q == c);
                }

                for (int i = 0; i < MAX_EXTRA; i++, q++) {
                    assert(*q == 'a');
                }
            }
        }
    }

    printf("All checks passed.\n");
    return 0;
}