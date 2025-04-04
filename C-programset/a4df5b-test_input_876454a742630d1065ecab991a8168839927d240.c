#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <assert.h>

int main() {
    double d = FLT_MIN / 2.0;
    double x = FLT_MIN / 2.0;

    // Use assertion instead of abort function to check condition
    assert(x == d);

    printf("Assertion passed and program finished successfully.\n");

    return 0;
}