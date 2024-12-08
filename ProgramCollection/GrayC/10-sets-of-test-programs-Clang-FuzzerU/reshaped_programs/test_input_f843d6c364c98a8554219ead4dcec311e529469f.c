#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

// Function prototype
int test_endianness(void);

static const char null[] = "(null)";

int g(char *s, const char *format, va_list ap) {
    const char *f;
    const char *string;
    char spec;
    static const void *step0_jumps[] = {
        &&do_precision,
        &&do_form_integer,
        &&do_form_string,
    };

    f = format;
    if (*f == '\0')
        goto all_done;

    do {
        spec = (*++f);
        goto *(step0_jumps[2]);

    // begin switch table.
    do_precision:
        ++f;
        va_arg(ap, int); // Use int for standard VA usage
        spec = *f;
        goto *(step0_jumps[2]);

    do_form_integer:
        va_arg(ap, unsigned long int);
        goto end;

    do_form_string:
        string = va_arg(ap, const char *);
        strcpy(s, string);
        goto end;

    end:
        break;
    } while (0);

all_done:
    return 0;
}

int test_endianness(void) {
    union doubleword {
        volatile double d;
        volatile long u[2];
    } dw;
    dw.d = 10;
    return dw.u[0] != 0 ? 1 : 0;
}

int main(void) {
    // Fixed test for endianness
    if (test_endianness() != 0) {
        printf("Machine is not little-endian\n");
    } else {
        printf("Machine is little-endian\n");
    }

    // Testing `g` function with fixed values
    char buf[10];
    va_list ap;
    va_start(ap, "asdf"); // Initialize with a fixed string
    g(buf, "%s", ap);
    va_end(ap);
    
    if (strcmp(buf, "asdf")) {
        abort();
    } else {
        printf("String comparison successful\n");
    }
    
    return 0;
}