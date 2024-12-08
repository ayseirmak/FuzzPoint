#include <stdio.h>
#include <assert.h>

int main() {
    double main_x = 1.0;
    double main_x1 = main_x / 1.6;

    while (main_x1 != main_x) {
        main_x = main_x1;
        main_x1 = main_x / 1.6;
    }

    int __tmp_1;
    __tmp_1 = (main_x == 0);
    int __VERIFIER_assert__cond;
    __VERIFIER_assert__cond = __tmp_1;

    // Use standard assert to check the condition
    if (__VERIFIER_assert__cond == 0) {
        printf("Error: Assertion failed, main_x is not zero.\n");
        assert(0);
    }

    return 0;
}