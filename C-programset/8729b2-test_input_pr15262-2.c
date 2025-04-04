#include <stdio.h>

struct A
{
    int t;
    int i;
};

struct B
{
    int *p;
    float b;
};

float X;

float foo(struct B b, struct A *q, float *h)
{
    X += *h;
    *(b.p) = 3;
    q->t = 2;
    return *(b.p);
}

int main()
{
    struct A a;
    struct B b;

    // Initializes `h` to a typical example value or edge case
    float h = 1.5f; // Example float value, can be adjusted

    b.p = &(a.t);
    if (foo(b, &a, &h) == 3)
    {
        // Prints the message to indicate the condition is met
        printf("The condition is met, exiting with failure.\n");
        return 1;
    }

    return 0;
}