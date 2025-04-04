#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void vafunction(char *dummy, ...) {
    double darg = 0.0;
    int i = 0;
    int flag = 0;
    va_list ap;

    va_start(ap, dummy);
    for (i = 1; i <= 18; i++, flag++) {
        if (flag & 1) {
            darg = va_arg(ap, double);
            if (darg != (double)i) {
                printf("Error: Expected %f, but got %f\n", (double)i, darg);
            }
        } else {
            int iarg = va_arg(ap, int);
            if (iarg != i) {
                printf("Error: Expected %d, but got %d\n", i, iarg);
            }
        }
    }
    va_end(ap);
}

int main(void) {
    vafunction("", 1, 2.0, 3, 4.0, 5, 6.0, 7, 8.0, 9, 10.0, 11, 12.0, 13, 14.0, 15, 16.0, 17, 18.0);
    return 0;
}