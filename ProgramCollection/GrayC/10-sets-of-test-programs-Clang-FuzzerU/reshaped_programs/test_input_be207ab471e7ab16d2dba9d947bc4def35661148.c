#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct foo {
    char a, b, c, d, e, f, g, h, i, j;
};

void test() {
    struct foo X = {'A', 0, 'C', 0, 'E', 0, 'G', 0, 'I', 0};
    char buffer[10];
    
    // Using standard memcpy to copy the struct data into the buffer
    memcpy(buffer, &X, sizeof(X));

    // Simple assertions to check copied values
    assert(buffer[0] == 'A');
    assert(buffer[2] == 'C');
    assert(buffer[4] == 'E');
    assert(buffer[6] == 'G');
    assert(buffer[8] == 'I');
}

int main() {
    test();
    printf("All tests passed.\n");
    return 0;
}