#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct foo {
    char a;
    char b;
    char c;
    char d;
    char e;
    char f;
    char g;
    char h;
    char i;
    char j;
};

void test3() {
    struct foo X = { 
        .a = 'A', 
        .b = 0, // Adding placeholders for unspecified fields
        .c = 'C', 
        .d = 0,
        .e = 'E', 
        .f = 0,
        .g = 'G', 
        .h = 0,
        .i = 'I', 
        .j = 0 
    };
    
    char buffer[10];
    memcpy(buffer, &X, sizeof(struct foo));
    
    if (buffer[0] != 'A' || buffer[2] != 'C' || buffer[4] != 'E' || buffer[6] != 'G' || buffer[8] != 'I') {
        abort();
    }

    printf("Test passed.\n");
}

int main() {
    test3();
    return 0;
}