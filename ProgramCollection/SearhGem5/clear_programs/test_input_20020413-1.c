#include <stdio.h>
#include <assert.h>

void test(double val, int *eval) {
    double tmp = 1.0;
    int i = 0;

    if (val < 0.0)
        val = -val;

    if (val >= tmp)
        while (tmp < val) {
            tmp *= 2.0;
            assert(i++ < 10);  // Ensure `i` does not exceed 10
        }
    else if (val != 0.0)
        while (val < tmp) {
            tmp /= 2.0;
            assert(i++ < 10);  // Ensure `i` does not exceed 10
        }

    *eval = i;
}

int main() {
    double test_values[] = {0.5, 2.5, 10.0, 1024.0};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);
    int eval;
    
    for (int i = 0; i < num_tests; ++i) {
        test(test_values[i], &eval);
        printf("Test value: %f, Eval: %d\n", test_values[i], eval);
    }
    
    return 0;
}