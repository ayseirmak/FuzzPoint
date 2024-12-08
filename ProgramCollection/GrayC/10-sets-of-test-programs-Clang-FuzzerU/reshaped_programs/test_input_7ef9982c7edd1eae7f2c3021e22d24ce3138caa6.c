#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

/* Function declarations */
void foo(_Complex double x);
void bar(_Complex float y);
void baz(_Complex long double z);

void complex_test() {
    _Complex double x;
    _Complex float y;
    _Complex long double z;

    /* Initialize complex numbers with fixed values */
    x = 1.0 + 2.0 * I;
    y = 3.0f + 4.0f * I;
    z = 5.0L + 6.0L * I;

    /* Call functions with complex numbers */
    foo(x);
    bar(y);
    baz(z);
}

/* Definition of foo that takes complex double */
void foo(_Complex double x) {
    /* Example operation on complex number */
    printf("foo: real part = %f, imaginary part = %f\n", creal(x), cimag(x));
}

/* Definition of bar that takes complex float */
void bar(_Complex float y) {
    /* Example operation on complex number */
    printf("bar: real part = %f, imaginary part = %f\n", crealf(y), cimagf(y));
}

/* Definition of baz that takes complex long double */
void baz(_Complex long double z) {
    /* Example operation on complex number */
    printf("baz: real part = %Lf, imaginary part = %Lf\n", creall(z), cimagl(z));
}

int main() {
    /* Call complex_test to demonstrate function executions */
    complex_test();
    
    /* Simulate original integer operations */
    unsigned long long r = 0x80000000LLU;
    do_test(&r);

    return 0;
}

void __attribute__((noinline)) do_test(unsigned long long *r) {
    int i;
    for (i = 0; i < 2; ++i) {
        example_operation(r);
    }
}

void __attribute__((always_inline)) example_operation(unsigned long long *r) {
    int i;
    for (i = 0; ; i++) {
        if (*r & ((unsigned long long)1 << (63 - i))) {
            printf("Detected: Exiting loop at iteration %d\n", i);
            break;
        }
    }
}

void __attribute__((noinline)) abort_if_nonzero(unsigned long long i) {
    if (i) {
        abort(); /* or exit with error code for simulation */
    }
}