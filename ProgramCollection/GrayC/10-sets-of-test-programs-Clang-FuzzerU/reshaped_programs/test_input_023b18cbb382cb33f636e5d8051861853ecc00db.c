#include <stdio.h>
#include <stdlib.h>

__attribute__((noinline, noclone)) void
bar (int x)
{
    // Empty inline assembly to prevent certain optimizations,
    // for ARM architecture compatibility, this should be empty.
    __asm__ volatile ("" : : "g" (x) : "memory");
}

__attribute__((noinline, noclone)) int
foo (unsigned x, long long y)
{
    if (y < 0)
    {
        return 0;
    }
    if (y < (long long) (4 * x))
    {
        bar (y);
        return 1;
    }
    return 0;
}

int main(void)
{
    volatile unsigned x = 10;
    volatile long long y;

    y = -10000;
    if (foo(x, y) != 0)
    {
        printf("Test failed: y = -10000\n");
        exit(EXIT_FAILURE);
    }

    y = -1;
    if (foo(x, y) != 0)
    {
        printf("Test failed: y = -1\n");
        exit(EXIT_FAILURE);
    }

    y = 0;
    if (foo(x, y) != 1)
    {
        printf("Test failed: y = 0\n");
        exit(EXIT_FAILURE);
    }

    y = 39;
    if (foo(x, y) != 1)
    {
        printf("Test failed: y = 39\n");
        exit(EXIT_FAILURE);
    }

    y = 40;
    if (foo(x, y) != 0)
    {
        printf("Test failed: y = 40\n");
        exit(EXIT_FAILURE);
    }

    y = 10000;
    if (foo(x, y) != 0)
    {
        printf("Test failed: y = 10000\n");
        exit(EXIT_FAILURE);
    }

    printf("All tests passed.\n");
    return 0;
}