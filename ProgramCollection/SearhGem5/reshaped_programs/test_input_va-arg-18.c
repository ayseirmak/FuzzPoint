#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef double L;

void f(L p0, L p1, L p2, L p3, L p4, L p5, L p6, L p7, L p8, ...)
{
    va_list select;
    
    va_start(select, p8);

    assert(va_arg(select, int) == 10);
    assert(va_arg(select, int) == 11);
    assert(va_arg(select, int) == 12);

    va_end(select);
}

int main()
{
    // Initialized the variables with default values reflecting typical use cases
    L p0 = 1.1;
    L p1 = 2.2;
    L p2 = 3.3;
    L p3 = 4.4;
    L p4 = 5.5;
    L p5 = 6.6;
    L p6 = 7.7;
    L p7 = 8.8;
    L p8 = 9.9;

    f(p0, p1, p2, p3, p4, p5, p6, p7, p8, 10, 11, 12);

    printf("All assertions passed successfully.\n");

    return 0;  // Indicating successful execution
}