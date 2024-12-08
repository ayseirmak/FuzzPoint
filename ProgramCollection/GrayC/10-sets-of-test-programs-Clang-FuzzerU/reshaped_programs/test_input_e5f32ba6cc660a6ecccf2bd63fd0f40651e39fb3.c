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
    T virk;
    virk = g();
    return virk;
}

void check_struct() {
    if (f().hours != 1 || f().day != 2 || f().month != 3 || f().year != 4) {
        printf("Error in structure values\n");
        abort();
    } else {
        printf("Structure values are correct\n");
    }
}

int bar(float x) {
    return 2241;
}

struct A {
    float a1;
    int a2;
} a;

int b;

void foo(void) {
    a.a2 = bar(a.a1);
    a.a2 = a.a2 < b - 1 ? a.a2 : b - 1;
    if (a.a2 >= b - 1) {
        printf("Error: a.a2 is greater than or equal to b-1\n");
        abort();
    } else {
        printf("a.a2 is less than b-1\n");
    }
}

void recursive_foo(int n, int m) {
    if (m == 0) {
        printf("Exiting recursion\n");
        exit(0);
    } else if (n != 0) {
        printf("Error: n is non-zero\n");
        abort();
    } else {
        recursive_foo(n + 1, m - 1);
    }
}

int main(void) {
    check_struct();

    a.a1 = 1.0f;
    b = 3384;
    foo();

    recursive_foo(0, 4);

    return 0;
}