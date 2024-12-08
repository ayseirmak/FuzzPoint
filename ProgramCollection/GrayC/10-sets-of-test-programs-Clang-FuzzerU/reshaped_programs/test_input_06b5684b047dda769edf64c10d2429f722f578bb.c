#include <stdio.h>
#include <stdlib.h>

int f(int a, int *y) {
    int x = a;
    if (a == 0)
        return *y;
    return f(a - 1, &x);
}

int main() {
    int fixed_value = 0;
    if (f(100, &fixed_value) != 1) {
        abort(); 
    }
    printf("Program completed successfully.\n");
    return 0;
}