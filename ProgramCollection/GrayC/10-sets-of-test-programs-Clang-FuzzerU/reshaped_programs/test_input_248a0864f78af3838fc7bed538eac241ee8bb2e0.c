#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char hours, day, month;
    short year;
} TimeStruct;

TimeStruct g(void) {
    TimeStruct now;
    // Assign fixed values
    now.hours = 1;
    now.day = 2;
    now.month = 3;
    now.year = 4;
    return now;
}

TimeStruct f(void) {
    return g();
}

struct A {
    float a1;
    int a2;
} a;

int b;

int bar(float x) {
    // Return fixed value as per requirement
    return 2241;
}

void foo(void) {
    a.a2 = bar(a.a1);
    a.a2 = a.a2 < b - 1 ? a.a2 : b - 1;
    if (a.a2 >= b - 1) {
        abort();
    }
}

int main(void) {
    if (f().hours != 1 || f().day != 2 || f().month != 3 || f().year != 4) {
        abort();
    }

    a.a1 = 1.0f;
    b = 3384;
    foo();

    return 0;
}