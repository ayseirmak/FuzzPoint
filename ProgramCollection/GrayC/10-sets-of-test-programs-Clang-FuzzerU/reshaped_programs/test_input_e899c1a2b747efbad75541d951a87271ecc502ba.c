#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

float fx(float x) {
    return 1.0 + 3.0 / (2.302585093 * x);
}

float inita() { return 3.0; }
float initc() { return 4.0; }

int main() {
    float a, b, c;
    a = inita();
    c = initc();
    b = fx(c) + a;
    
    if (!(a == 3.0 && b >= 4.3257 && b <= 4.3258 && c == 4.0)) {
        abort();
    }
    return 0;
}