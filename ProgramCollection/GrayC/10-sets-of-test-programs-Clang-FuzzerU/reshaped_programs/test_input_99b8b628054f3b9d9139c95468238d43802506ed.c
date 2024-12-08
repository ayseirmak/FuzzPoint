#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

// Function that processes the formatted input
int g(char *s, const char *format, va_list ap) {
    const char *f = format;
    const char *string;
    char spec;

    while (*f != '\0') {
        spec = *f;
        if (spec == '%') {
            f++;
            spec = *f;
            if (spec == 's') {
                string = va_arg(ap, const char *);
                strcpy(s, string);
            }
        }
        f++;
    }

    return 0;
}

// Function that initializes the va_list and calls g()
void f(char *s, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    g(s, fmt, ap);
    va_end(ap);
}

int main(void) {
    char buf[10];
    // Directly passing deterministic inputs
    f(buf, "%s", "teststring");
    printf("Buffer contains: %s\n", buf);

    // Verify the output string
    if (strcmp(buf, "teststring") != 0) {
        abort();
    }

    return 0;
}