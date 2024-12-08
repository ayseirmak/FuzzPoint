#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enums and Structures
typedef enum { A, B, C, D } E;

struct S {
    E a;
    E b;
    E c;
    E d;
};

// Function Declarations
static inline void lstrcpynW(short *d, const short *s, int n);
int badfunc(int u0, int u1, int u2, int u3, short *fsname, unsigned int fsname_len);
long f();
void foo(struct S *s);

// Function Definitions
static inline void lstrcpynW(short *d, const short *s, int n) {
    unsigned int count = n;
    while ((count > 1) && *s) {
        count--;
        *d++ = *s++;
    }
    if (count) *d = 0;
}

int badfunc(int u0, int u1, int u2, int u3, short *fsname, unsigned int fsname_len) {
    static const short ntfsW[] = {'N', 'T', 'F', 'S', 0};
    char superblock[5348];
    int ret = 0;

    if (f()) {
        return 0;
    }
    lstrcpynW(fsname, ntfsW, fsname_len);
    ret = 1;
    return ret;
}

long f() {
    return 0;
}

void foo(struct S *s) {
    if (s->a != s->b) {
        printf("Abort due to mismatched a and b\n");
        exit(1);
    }
    if (s->c != C) {
        printf("Abort due to mismatched c\n");
        exit(1);
    }
}

int main(void) {
    short buf[6];
    int ret;

    struct S s[2];
    s[0].a = B;
    s[0].b = B;
    s[0].c = C;
    s[0].d = D;
    s[1].a = D;
    s[1].b = C;
    s[1].c = B;
    s[1].d = A;

    foo(s);
    ret = badfunc(0, 0, 0, 0, buf, 6);

    return !ret;
}