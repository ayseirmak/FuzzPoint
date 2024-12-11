#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void f(double p0, double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8, ...) {
    va_list select;
    va_start(select, p8);

    if (va_arg(select, double) != 10.0) {
        printf("Unexpected value for p9\n");
        exit(1);
    }
    if (va_arg(select, double) != 11.0) {
        printf("Unexpected value for p10\n");
        exit(1);
    }
    if (va_arg(select, double) != 0.0) {
        printf("Unexpected value for p11\n");
        exit(1);
    }

    va_end(select);
}

int main() {
    // Initialized variables with typical values for demonstration
    double p0 = 1.0, p1 = 2.0, p2 = 3.0, p3 = 4.0, p4 = 5.0;
    double p5 = 6.0, p6 = 7.0, p7 = 8.0, p8 = 9.0;

    f(p0, p1, p2, p3, p4, p5, p6, p7, p8, 10.0, 11.0, 0.0);

    printf("All assertions passed successfully.\n");
    return 0;
}