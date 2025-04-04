#include <stdio.h>
#include <stdarg.h>

/* 5 bytes. */
typedef struct DWordS_struct { int i; char c; } DWordS;

/* 12 bytes if d is 4-byte aligned; 16 bytes if d is 8-byte aligned. */
typedef struct QuadWordS_struct { int i; double d; } QuadWordS;

/* 20 bytes if d is 4-byte aligned; 28 bytes if d is 8-byte aligned
 * (assuming pointer size is 4 bytes and 8 bytes respectively). */
typedef struct LargeS_struct { int i; double d; DWordS* ptr; int j; } LargeS;

void test(int num, ...) {
    va_list ap;
    int d;
    char c;
    char *s;
    DWordS dw;
    QuadWordS qw;
    LargeS ls;

    va_start(ap, num);
    char *fmt = va_arg(ap, char*);

    while (*fmt) {
        switch (*fmt++) {
            case 's': /* string */
                s = va_arg(ap, char*);
                printf("string %s\n", s);
                break;
            case 'i': /* int */
                d = va_arg(ap, int);
                printf("int %d\n", d);
                break;
            case 'd':
                printf("double %f\n", va_arg(ap, double));
                break;
            case 'l':
                printf("long long %lld\n", va_arg(ap, long long));
                break;
            case 'c': /* char */
                c = (char) va_arg(ap, int); /* promoted to int */
                printf("char %c\n", c);
                break;
            case 'D':
                dw.i = va_arg(ap, int);
                dw.c = (char) va_arg(ap, int);
                printf("DWord { %d, %c }\n", dw.i, dw.c);
                break;
            case 'Q':
                qw.i = va_arg(ap, int);
                qw.d = va_arg(ap, double);
                printf("QuadWord { %d, %f }\n", qw.i, qw.d);
                break;
            case 'L':
                ls.i = va_arg(ap, int);
                ls.d = va_arg(ap, double);
                ls.ptr = va_arg(ap, int) ? &dw : NULL;
                if (ls.ptr) {
                    dw.i = va_arg(ap, int);
                    dw.c = (char) va_arg(ap, int);
                }
                ls.j = va_arg(ap, int);
                printf("LargeS { %d, %f, 0x%d, %d }\n", ls.i, ls.d, (ls.ptr != NULL), ls.j);
                break;
        }
    }
    va_end(ap);
}

int main() {
    DWordS dw = {18, 'a'};
    QuadWordS qw = {19, 20.0};
    LargeS ls = {21, 22.0, &dw, 23};

    /* Simulate the logic without command line arguments */
    test(9, "ddil", 1.0, 2.0, 32764, 12345677823423LL);

    /* Test passing structs by value to varargs */
    test(10, "DQL", 18, 'a', 19, 20.0, 1, 21, 22.0, 1, 23);

    return 0;
}