#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void reach_error() { 
    assert(0 && "Reach error condition"); 
}

int main() {
    long double x = 1.0 / 7.0;
    long long res = 0;

    for (int i = 1; x != 0; i++) {
        res += ((int)(x * 10) % 10) * (i * 10);
        x = (x * 10) - (int)(x * 10);
    }

    assert(res == 67050);
    if (res != 67050) {
        reach_error();
        abort();
    }

    return 0;
}