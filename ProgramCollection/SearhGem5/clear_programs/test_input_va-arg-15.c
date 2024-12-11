#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void vafunction(char *dummy, ...)
{
    double darg;
    int iarg;
    int flag = 0;
    int i;
    va_list ap;

    va_start(ap, dummy);
    for (i = 1; i <= 18; i++, flag++)
    {
        if (flag & 1)
        {
            darg = va_arg(ap, double);
            if (darg != (double)i)
            {
                printf("Error: Expected double value %d, but got %f\n", i, darg);
                return;
            }
        }
        else
        {
            iarg = va_arg(ap, int);
            if (iarg != i)
            {
                printf("Error: Expected integer value %d, but got %d\n", i, iarg);
                return;
            }
        }
    }
    va_end(ap);
    printf("All values match the expected sequence.\n");
}

int main(void)
{
    // Initialized values array with values 1 to 18 to simulate the logic
    int values[18];
    for (int i = 0; i < 18; i++)
    {
        values[i] = i + 1;
    }

    vafunction("", values[0], (double)values[1], values[2], (double)values[3], values[4], (double)values[5], values[6], (double)values[7], values[8], (double)values[9], values[10], (double)values[11], values[12], (double)values[13], values[14], (double)values[15], values[16], (double)values[17]);
    
    return 0;
}