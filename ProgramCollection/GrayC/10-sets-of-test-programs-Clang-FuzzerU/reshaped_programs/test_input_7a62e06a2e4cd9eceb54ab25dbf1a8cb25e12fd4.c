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

void check(int off, int len, char ch) {
    char *q = u.buf;
    
    for (int i = 0; i < off; i++, q++) {
        assert(*q == 'a');
    }

    for (int i = 0; i < len; i++, q++) {
        assert(*q == ch);
    }

    for (int i = 0; i < MAX_EXTRA; i++, q++) {
        assert(*q == 'a');
    }
}

int main() {
    int off;
    char *p;

    /* Testing memset with various lengths */
    for (int length = 1; length <= 15; length++) {
        for (off = 0; off < MAX_OFFSET; off++) {
            reset();

            p = memset(u.buf + off, '\0', length);
            assert(p == u.buf + off);
            check(off, length, '\0');

            p = memset(u.buf + off, A, length);
            assert(p == u.buf + off);
            check(off, length, 'A');

            p = memset(u.buf + off, 'B', length);
            assert(p == u.buf + off);
            check(off, length, 'B');
        }
    }

    return 0;
}