#include <stdio.h>

struct complex
{
    float r;
    float i;
};

struct complex f(float a, float b)
{
    struct complex c;
    c.r = a;
    c.i = b;
    return c;
}

int main(void)
{
    float input1 = 3.14f;  // Example initialization
    float input2 = 2.71f;  // Example initialization
    struct complex z = f(input1, input2);

    // Check if returned complex values match the input
    if (z.r != input1 || z.i != input2)
    {
        printf("Test failed: complex numbers do not match input values.\n");
    }
    else
    {
        printf("Test passed: complex numbers correctly match input values.\n");
    }

    return 0;
}