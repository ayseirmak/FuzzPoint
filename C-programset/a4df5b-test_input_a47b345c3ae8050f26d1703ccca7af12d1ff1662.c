#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char hours, day, month;
    short year;
} T;

T g(void) {
    T now;
    now.hours = 1;
    now.day = 2;
    now.month = 3;
    now.year = 4;
    return now;
}

T f(void) {
    T virk = g();
    return virk;
}

int bar(float x) {
    return 2241;
}

struct A {
    float a1;
    int a2;
};

struct A a;
int b;

void foo(void) {
    a.a2 = bar(a.a1);
    a.a2 = (a.a2 < b - 1) ? a.a2 : b - 1;
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

    exit(0);
}