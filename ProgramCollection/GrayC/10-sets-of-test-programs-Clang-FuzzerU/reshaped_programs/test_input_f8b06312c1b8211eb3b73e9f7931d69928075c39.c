#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

typedef long unsigned int size_t;

static const char null_str[] = "(null)";

int g(char *s, const char *format, ...) {
    va_list ap;
    const char *f;
    const char *string;
    char spec;

    // Set up jump table
    static const void *step0_jumps[] = {
        &&do_precision,
        &&do_form_integer,
        &&do_form_string,
    };

    f = format;
    if (*f == '\0') {
        goto all_done;
    }
    do {
        spec = (*++f);
        goto *(step0_jumps[2]);

    do_precision:
        ++f;
        va_arg(ap, int); // assuming int for illustration
        spec = *f;
        goto *(step0_jumps[2]);

    do_form_integer:
        va_arg(ap, unsigned long int);
        goto end;

    do_form_string:
        string = va_arg(ap, const char*);
        strcpy(s, string != NULL ? string : null_str);
        goto end;

    } while (*f != '\0');

end:
    va_end(ap);
    return 0;

all_done:
    return 0;
}

int test_endianness_vol() {
    union doubleword {
        volatile double d;
        volatile long u[2];
    } dw;
    dw.d = 10;
    return dw.u[0] != 0 ? 1 : 0;
}

int main(void) {
    // Hardcoded example for testing: It prepares the buffer and runs 'g'.
    char buf[10];
    g(buf, "%s", "asdf");

    // Verifying the output
    if (strcmp(buf, "asdf") != 0) {
        abort();
    }

    // Check test_endianness_vol function
    if (test_endianness_vol() != 1) {
        abort();
    }

    return 0;
}