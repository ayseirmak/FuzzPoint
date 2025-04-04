#include <stdio.h>
#include <stdlib.h>

void test(long double val, int *eval) {
    long double tmp = 1.0L;
    int i = 0;

    if (val < 0.0L) {
        val = -val;
    }

    if (val >= tmp) {
        while (tmp < val) {
            tmp *= 2.0L;
            if (i++ >= 10) {
                printf("Exceeded loop limit in increasing phase.\n");
                exit(1);
            }
        }
    } else if (val != 0.0L) {
        while (val < tmp) {
            tmp /= 2.0L;
            if (i++ >= 10) {
                printf("Exceeded loop limit in decreasing phase.\n");
                exit(1);
            }
        }
    }

    *eval = i;
}

int main(void) {
    int eval;

    test(3.0, &eval);
    printf("Test with 3.0 resulted in eval = %d\n", eval);

    test(3.5, &eval);
    printf("Test with 3.5 resulted in eval = %d\n", eval);

    test(4.0, &eval);
    printf("Test with 4.0 resulted in eval = %d\n", eval);

    test(5.0, &eval);
    printf("Test with 5.0 resulted in eval = %d\n", eval);

    return 0;
}