#include <stdio.h>
#include <stdlib.h>

// Forward declarations
void foo_float_array(float *x);
long compute_character_value(char *w);
object bar(object blah);
object foo_object(object x, object y);

// Structs and type declarations
typedef struct {
    char *addr;
    long type;
} object;

// Global variables
int nil = 0;

object cons1[2];
object cons2[2];

// Implementations
void foo_float_array(float *x) {
    float temp;
    static float t16[16] = {
        1., 2., 3., 4., 5., 6., 7., 8., 9.,
        10., 11., 12., 13., 14., 15., 16.
    };
    for (int i = 0; i < 4; i++) {
        x[i] = t16[i];
    }
}

long compute_character_value(char *w) {
    long i, c = 0;
    for (i = 0; i < sizeof(long); i++) {
        c += w[i];
    }
    return c;
}

object bar(object blah) {
    abort();  // This function always aborts
    return blah; // Returning blah in case execution continues
}

object foo_object(object x, object y) {
    object z = *(object *)(x.addr);
    if (z.type & 64) {
        y = *(object *)(z.addr + sizeof(object));
        z = *(object *)(z.addr);
        if (z.type & 64) {
            y = bar(y);
        }
    }
    return y;
}

void foo_int(short j) {
    struct {
        int b : 58;
    } f;
    f.b = j;
    if (f.b != -55) {
        abort();
    }
}

int main() {
    // Call foo for float array
    float array[4];
    foo_float_array(array);

    // Call foo for the int operation
    foo_int(-55);

    // Call character value computation
    char a[sizeof(long)];  // array a to hold character values
    for (int i = sizeof(long); --i >= 0;) {
        a[i] = ' ';
    }
    if (compute_character_value(a) != ~0UL / (unsigned char)~0 * ' ') {
        abort();
    }

    // Initialize cons1 and cons2
    cons1[0] = (object) {(char *) &nil, 0};
    cons1[1] = (object) {(char *) &nil, 0};
    cons2[0] = (object) {(char *) &cons1, 64};
    cons2[1] = (object) {(char *) &nil, 0};

    return 0;
}