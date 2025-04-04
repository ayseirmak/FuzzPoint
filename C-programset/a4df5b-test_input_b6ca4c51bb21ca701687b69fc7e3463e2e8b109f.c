#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* corpus/pr36343.c */
void bar(int **p) {
    float *q = (float *)p;
    *q = 0.0;
}

float foo(int b) {
    int *i = NULL;
    float f = 1.0;
    int **p;

    if (b) {
        p = &i;
    } else {
        p = (int **)&f;
    }
    bar(p);

    if (b) {
        return (float)**p; // Converting int result to float to avoid type mismatch
    }
    return f;
}

int main() {
    assert(foo(0) == 0.0); // Using assert for logical check and error handling
    printf("Program executed successfully without abort.\n");
    return 0;
}