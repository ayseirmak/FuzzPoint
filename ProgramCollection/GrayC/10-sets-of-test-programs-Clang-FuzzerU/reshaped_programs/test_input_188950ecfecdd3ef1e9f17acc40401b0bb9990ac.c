#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

static const char null[] = "(null)";

// Simulate some deterministic logic; actual logic may vary.
int g(char *s, const char *format, ...) {
    va_list ap;
    va_start(ap, format);

    const char *f = format;
    const char *string;
    char spec;

    static const void *step0_jumps[] = {
        &&do_precision,
        &&do_form_integer,
        &&do_form_string,
    };

    if (*f == '\0')
        goto all_done;

    do {
        spec = (*++f);
        goto *(step0_jumps[2]);

        do_precision:
            ++f;
            va_arg(ap, int);
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
        all_done:
            ;

    } while (*f != '\0');

    va_end(ap);
    return 0;
}

int test_endianness() {
    union doubleword {
        volatile double d;
        volatile long u[2];
    } dw;

    dw.d = 10.0;
    return dw.u[0] != 0 ? 1 : 0;
}

int test_endianness_vol() {
    union doubleword {
        volatile double d;
        volatile long u[2];
    } dw;

    dw.d = 10.0;
    return dw.u[0] != 0 ? 1 : 0;
}

int main(void) {
    // Test the g function with a fixed input.
    char buf[10];
    g(buf, "%s", "asdf");
    if (strcmp(buf, "asdf") != 0) {
        abort();
    }

    // Test endianness
    if (test_endianness() != test_endianness_vol()) {
        abort();
    }

    return 0;
}