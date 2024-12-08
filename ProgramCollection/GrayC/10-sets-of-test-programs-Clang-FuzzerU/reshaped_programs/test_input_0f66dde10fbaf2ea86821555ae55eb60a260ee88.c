#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

typedef __builtin_va_list va_list; // Typically, stdarg.h already defines this

void f(char *s, const char *format, ...);

int g(char *s, const char *format, va_list ap) {
    const char *f;
    const char *string;
    char spec;

    f = format; 
    while (*f != '\0') {
        spec = *f;
        switch (spec) {
            case 's':
                string = va_arg(ap, const char *);
                strcpy(s, string);
                break;
            case 'd':
                // You can handle integer formatting if desired
                break;
            default:
                // Handle unknown specifiers
                break;
        }
        ++f;
    }

    return 0;
}

void f(char *s, const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    g(s, format, ap);
    va_end(ap);
}

int main(void) {
    char buf[10];
    strcpy(buf, "init");  // Initializing buffer
    f(buf, "%s", "asdf");
    
    printf("Buffer: %s\n", buf); // Output the result
    
    // Test conditional to ensure the function behaves correctly
    if (strcmp(buf, "asdf") == 0) {
        printf("String copied correctly.\n");
    } else {
        abort(); // If not correct, abort program
    }
    
    return 0;
}