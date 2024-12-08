#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    int i;
    for (i = 0; i < MAX_LENGTH; i++) {
        u.buf[i] = 'a';
    }
}

void check(int off, int len, int ch) {
    char *q = u.buf;
    int i;
    for (i = 0; i < off; i++, q++) {
        assert(*q == 'a');
    }
    for (i = 0; i < len; i++, q++) {
        assert(*q == ch);
    }
    for (i = 0; i < MAX_EXTRA; i++, q++) {
        assert(*q == 'a');
    }
}

int main() {
    int off;
    char *p;

    for (int len = 1; len <= MAX_COPY; len++) {
        for (off = 0; off < MAX_OFFSET; off++) {
            reset();
            
            p = memset(u.buf + off, '\0', len);
            assert(p == u.buf + off);
            check(off, len, '\0');
            
            p = memset(u.buf + off, A, len);
            assert(p == u.buf + off);
            check(off, len, 'A');
            
            p = memset(u.buf + off, 'B', len);
            assert(p == u.buf + off);
            check(off, len, 'B');
        }
    }

    return 0;
}