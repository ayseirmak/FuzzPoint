#include <stdio.h>
#include <stdarg.h>

typedef double TYPE;

void vafunction(TYPE dummy1, TYPE dummy2, ...) {
    va_list ap;
    va_start(ap, dummy2);

    if (dummy1 != 1.0) {
        printf("Error: dummy1 != 1.0\n");
        return;
    }
    if (dummy2 != 2.0) {
        printf("Error: dummy2 != 2.0\n");
        return;
    }
    if (va_arg(ap, TYPE) != 3.0) {
        printf("Error: third argument != 3.0\n");
        return;
    }
    if (va_arg(ap, TYPE) != 4.0) {
        printf("Error: fourth argument != 4.0\n");
        return;
    }
    if (va_arg(ap, TYPE) != 5.0) {
        printf("Error: fifth argument != 5.0\n");
        return;
    }
    if (va_arg(ap, TYPE) != 6.0) {
        printf("Error: sixth argument != 6.0\n");
        return;
    }
    if (va_arg(ap, TYPE) != 7.0) {
        printf("Error: seventh argument != 7.0\n");
        return;
    }
    if (va_arg(ap, TYPE) != 8.0) {
        printf("Error: eighth argument != 8.0\n");
        return;
    }
    if (va_arg(ap, TYPE) != 9.0) {
        printf("Error: ninth argument != 9.0\n");
        return;
    }
    if (va_arg(ap, TYPE) != 10.0) {
        printf("Error: tenth argument != 10.0\n");
        return;
    }
    if (va_arg(ap, TYPE) != 11.0) {
        printf("Error: eleventh argument != 11.0\n");
        return;
    }
    va_end(ap);
}

int main() {
    vafunction(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0);
    return 0;
}