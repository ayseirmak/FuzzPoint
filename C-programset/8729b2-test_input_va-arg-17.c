#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

typedef double TYPE;

void vafunction(char *dummy, ...)
{
    va_list ap;
    va_start(ap, dummy);

    TYPE val1 = va_arg(ap, TYPE);
    TYPE val2 = va_arg(ap, TYPE);
    TYPE val3 = va_arg(ap, TYPE);
    TYPE val4 = va_arg(ap, TYPE);
    TYPE val5 = va_arg(ap, TYPE);
    TYPE val6 = va_arg(ap, TYPE);
    TYPE val7 = va_arg(ap, TYPE);
    TYPE val8 = va_arg(ap, TYPE);
    TYPE val9 = va_arg(ap, TYPE);

    va_end(ap);

    printf("Values received:\n");
    printf("%lf\n", val1);
    printf("%lf\n", val2);
    printf("%lf\n", val3);
    printf("%lf\n", val4);
    printf("%lf\n", val5);
    printf("%lf\n", val6);
    printf("%lf\n", val7);
    printf("%lf\n", val8);
    printf("%lf\n", val9);
}

int main()
{
    // Fixed values instead of program arguments
    TYPE val1 = 1.0;
    TYPE val2 = 2.0;
    TYPE val3 = 3.0;
    TYPE val4 = 4.0;
    TYPE val5 = 5.0;
    TYPE val6 = 6.0;
    TYPE val7 = 7.0;
    TYPE val8 = 8.0;
    TYPE val9 = 9.0;

    vafunction("", val1, val2, val3, val4, val5, val6, val7, val8, val9);

    return 0;
}