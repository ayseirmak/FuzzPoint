#include <stdio.h>

struct S {
    double for_alignment;
    struct {
        int x, y, z;
    } a[16];
};

void f(struct S *s);

void f(struct S *s) {
    unsigned int i;

    // Example fixed values to simulate command-line input
    int values[48] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
        17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
        33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48
    };

    for (i = 0; i < 16; ++i) {
        s->a[i].x = values[i];
        s->a[i].y = values[i + 16];
        s->a[i].z = values[i + 32];
    }
}

int main() {
    struct S s;
    f(&s);

    // Display the initialized values for verification
    for(int i = 0; i < 16; i++) {
        printf("s.a[%d] = { x: %d, y: %d, z: %d }\n", i, s.a[i].x, s.a[i].y, s.a[i].z);
    }

    return 0;
}