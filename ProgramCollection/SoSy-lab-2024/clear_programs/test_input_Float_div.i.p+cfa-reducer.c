#include <stdio.h>
#include <assert.h>

void reach_error() {
    assert(0 && "reach_error");
}

int main() {
    float main__x = 1.0;
    float main__x1 = main__x / 2.5;

    while (main__x1 != main__x) {
        main__x = main__x1;
        main__x1 = main__x / 2.5;
    }

    int __tmp_1 = (main__x == 0);
    if (!__tmp_1) {
        reach_error();
    }

    return 0;
}