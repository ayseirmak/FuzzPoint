#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef size_t size_t;

static int mymemcmp1(unsigned long int a, unsigned long int b) {
    if (a == b)
        return 0;
    return (a < b) ? -1 : 1;
}

static int mymemcmp2(long int srcp1, long int srcp2, size_t len) {
    for (size_t i = 0; i < len; i++) {
        unsigned long int a = ((unsigned long int *)srcp1)[i];
        unsigned long int b = ((unsigned long int *)srcp2)[i];
        int cmp = mymemcmp1(a, b);
        if (cmp != 0) {
            return cmp;
        }
    }
    return 0;
}

__attribute__((noinline))
int mymemcmp(const void *s1, const void *s2, size_t len) {
    long int srcp1 = (long int)s1;
    long int srcp2 = (long int)s2;
    return mymemcmp2(srcp1, srcp2, len / sizeof(unsigned long int));
}

int main(void) {
    char buf[256] = {0};
    char *p;
    union {
        long int l;
        char c[sizeof(long int)];
    } u;

    if (sizeof(long int) != sizeof(void *) || sizeof(long int) < 4) {
        return 0;
    }

    u.l = 0x12345678L;
    if (u.c[0] != 0x78 || u.c[1] != 0x56 || u.c[2] != 0x34 || u.c[3] != 0x12) {
        return 0;
    }

    p = buf + 16 - (((long int)buf) & 15);
    const char data1[] = "\x01\x37\x82\xa7\x55\x49\x9d\xbf\xf8\x44\xb6\x55\x17\x8e\xf9";
    const char data2[] = "\x01\x37\x82\xa7\x55\x49\xd0\xf3\xb7\x2a\x6d\x23\x71\x49\x6a";
    memcpy(p + 9, data1, sizeof(data1) - 1);
    memcpy(p + 128 + 24, data2, sizeof(data2) - 1);

    if (mymemcmp(p + 9, p + 128 + 24, 33) != -51) {
        printf("Assertion failed, aborting program.\n");
        exit(EXIT_FAILURE);
    }

    printf("Program executed successfully.\n");
    return 0;
}