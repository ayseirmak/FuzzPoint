#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void g(char *s, const char *format, va_list ap) {
    const char *string;
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == 's') {
                string = va_arg(ap, const char *);
                strcpy(s, string);
            }
        }
        format++;
    }
}

void f(char *s, const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    g(s, format, ap);
    va_end(ap);
}

int main(void) {
    char buf[10] = {'\0'}; // Initialize buffer

    f(buf, "%s", "hello");

    printf("Buffer contains: %s\n", buf);

    return 0;
}