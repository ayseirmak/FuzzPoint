#include <stdio.h>
#include <limits.h> // For __INT_MAX__
#include <stdlib.h> // For abort()

int f1(int x, int y) {
    return x % y;
}

int f2(int x, int y) {
    return x % -y;
}

int f3(int x, int y) {
    int z = -y;
    return x % z;
}

int main() {
    // Deterministic check with fixed values
    int testValue1 = f1(-__INT_MAX__ - 1, 1);
    int testValue2 = f2(-__INT_MAX__ - 1, -1);
    int testValue3 = f3(-__INT_MAX__ - 1, -1);

    if (testValue1 != 0 || testValue2 != 0 || testValue3 != 0) {
        abort(); // Abort execution if any condition fails
    }

    printf("All tests passed.\n");
    return 0;
}