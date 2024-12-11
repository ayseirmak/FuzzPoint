#include <stdio.h>
#include <stdlib.h> // For abort()

struct s1 { double d; };
struct s2 { double d; };
union u { struct s1 x; struct s2 y; };

double f(struct s1 *a, struct s2 *b)
{
    a->d = 1.0;
    return b->d + 1.0;
}

int main()
{
    union u a;
    a.x.d = 0.0;  // Initialize the double member of the union

    if (f(&a.x, &a.y) != 2.0) {
        abort();  // Directly using abort function as intended by original code
    }

    return 0;
}