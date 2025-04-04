#include <stdio.h>
#include <stdlib.h>

int bar(float x) {
    return 2241;
}

struct A {
    float a1;
    int a2;
} a;

int b;

void foo(int input_value) {
    a.a2 = bar(a.a1);
    a.a2 = a.a2 < input_value - 1 ? a.a2 : input_value - 1;
    if (a.a2 >= input_value - 1) {
        printf("Error: Condition failed in foo\n");
    }
}

int main() {
    int fixed_value = 100;  // suppose this is a typical or edge case value for testing

    a.a1 = 1.0f;  // initial float value for struct A
    b = 3384;     // arbitrary initialized value for variable b
    
    foo(fixed_value);
    return 0;
}