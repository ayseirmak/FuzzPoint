#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void reach_error() { assert(0); }
void custom_assert(int cond) { if (!(cond)) { reach_error(); abort(); } return; }

int main() {
    long double x = 1.0 / 7.0;
    long long res = 0;
    int i = 1;

    // Calculate the fractional digits for 1/7, multiplied and added to 'res'
    while (x != 0) {
        res += ((int)(x * 10) % 10) * (i * 10);
        x = (x * 10) - (int)(x * 10);
        i++;
    }

    // Assert that the calculated res equals 67050
    custom_assert(res == 67050);

    printf("Result: %lld\n", res); // Optional: Print result for verification
    return 0;
}