#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_OFFSET sizeof(long long)
#define MAX_COPY 15
#define MAX_EXTRA sizeof(long long)
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
        assert(*q == 'a');
    }

    for (int i = 0; i < len; i++, q++) {
        assert(*q == ch);
    }

    for (int i = 0; i < MAX_EXTRA; i++, q++) {
        assert(*q == 'a');
    }
}

typedef struct {
    long r[(19 + sizeof(long)) / (sizeof(long))];
} realvaluetype;

typedef void *tree;

static realvaluetype real_value_from_int_cst(tree x, tree y) {
    realvaluetype r;
    for (int i = 0; i < sizeof(r.r) / sizeof(long); ++i) {
        r.r[i] = -1;
    }
    return r;
}

struct brfic_args {
    tree type;
    tree i;
    realvaluetype d;
};

static void build_real_from_int_cst_1(void *data) {
    struct brfic_args *args = (struct brfic_args *)data;
    args->d = real_value_from_int_cst(args->type, args->i);
}

int main() {
    struct brfic_args args;
    memset(&args, 0, sizeof(args));
    build_real_from_int_cst_1(&args);

    if (args.d.r[0] == 0) {
        abort();
    }

    for (int off = 0; off < MAX_OFFSET; off++) {
        reset();

        char *p = memset(u.buf + off, '\0', 1);
        assert(p == u.buf + off);
        check(off, 1, '\0');

        p = memset(u.buf + off, A, 1);
        assert(p == u.buf + off);
        check(off, 1, 'A');

        p = memset(u.buf + off, 'B', 1);
        assert(p == u.buf + off);
        check(off, 1, 'B');
    }

    // Additional tests with different lengths
    int lengths[] = {2, 3, 4, 5, 6, 7, 8};
    for (int j = 0; j < sizeof(lengths) / sizeof(lengths[0]); ++j) {
        for (int off = 0; off < MAX_OFFSET; off++) {
            reset();

            char *p = memset(u.buf + off, '\0', lengths[j]);
            assert(p == u.buf + off);
            check(off, lengths[j], '\0');

            p = memset(u.buf + off, A, lengths[j]);
            assert(p == u.buf + off);
            check(off, lengths[j], 'A');

            p = memset(u.buf + off, 'B', lengths[j]);
            assert(p == u.buf + off);
            check(off, lengths[j], 'B');
        }
    }

    printf("All checks passed.\n");
    return 0;
}