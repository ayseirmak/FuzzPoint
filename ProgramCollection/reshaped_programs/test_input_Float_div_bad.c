#include <stdio.h>
#include <assert.h>

#define X 1.6f

int main() {
    float x = 1.0f;
    float x1 = x / X;

    while (x1 != x) {
        x = x1;
        x1 = x / X;
    }

    // Using standard assert to replace custom verification
    assert(x == 0);

    printf("Program executed without assertion error.\n");
    return 0;
}