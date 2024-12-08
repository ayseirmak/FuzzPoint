#include <stdio.h>
#include <stdlib.h>

int main() {
    // Constants defined for deterministic operations
    const int bitwise_test_1 = 0xf0 | 1;
    const int bitwise_test_2 = 0xf0 & 1;
    const int bitwise_test_3 = 0xf0 & 0x1f;
    const int logical_test_1 = (0 > -1);
    const int logical_test_2 = (0 < -1);
    const int logical_test_3 = (1 == 1);
    
    // Checking multiple assertions to match original checks
    if (bitwise_test_1 != 0xf1) {
        printf("Bitwise OR test failed.\n");
        exit(EXIT_FAILURE);
    }

    if (bitwise_test_2 != 0) {
        printf("Bitwise AND test 1 failed.\n");
        exit(EXIT_FAILURE);
    }

    if (bitwise_test_3 != 0x10) {
        printf("Bitwise AND test 2 failed.\n");
        exit(EXIT_FAILURE);
    }

    if (logical_test_1 != 1) {
        printf("Logical test 1 failed.\n");
        exit(EXIT_FAILURE);
    }

    if (logical_test_2 != 0) {
        printf("Logical test 2 failed.\n");
        exit(EXIT_FAILURE);
    }

    if (logical_test_3 != 1) {
        printf("Equality test failed.\n");
        exit(EXIT_FAILURE);
    }

    // Arithmetic checks
    if ((1 << 1) != 2) {
        printf("Shift left test failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((2 >> 1) != 1) {
        printf("Shift right test failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((2 + 1) != 3) {
        printf("Addition test failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((2 - 3) != -1) {
        printf("Subtraction test failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((2 * 3) != 6) {
        printf("Multiplication test failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((6 / 3) != 2) {
        printf("Division test failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((7 % 3) != 1) {
        printf("Modulo test failed.\n");
        exit(EXIT_FAILURE);
    }

    // Control flow checks
    if ((0 ? 1 : 3) != 3) {
        printf("Ternary test 1 failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((1 ? 3 : 1) != 3) {
        printf("Ternary test 2 failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("All tests passed.\n");
    return 0;
}