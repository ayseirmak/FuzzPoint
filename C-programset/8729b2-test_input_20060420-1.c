#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef float v4flt __attribute__ ((vector_size (16)));

// Function to process the floating-point vectors
void __attribute__ ((noinline)) foo(float *dst, float **src, int a, int n)
{
    int i, j;
    int z = sizeof(v4flt) / sizeof(float);
    unsigned m = sizeof(v4flt) - 1;

    for (j = 0; j < n && (((unsigned long)dst + j) & m); ++j)
    {
        float t = src[0][j];
        for (i = 1; i < a; ++i)
            t += src[i][j];
        dst[j] = t;
    }

    for (; j < (n - (4 * z - 1)); j += 4 * z)
    {
        v4flt t0 = *(v4flt *)(src[0] + j + 0 * z);
        v4flt t1 = *(v4flt *)(src[0] + j + 1 * z);
        v4flt t2 = *(v4flt *)(src[0] + j + 2 * z);
        v4flt t3 = *(v4flt *)(src[0] + j + 3 * z);
        for (i = 1; i < a; ++i)
        {
            t0 += *(v4flt *)(src[i] + j + 0 * z);
            t1 += *(v4flt *)(src[i] + j + 1 * z);
            t2 += *(v4flt *)(src[i] + j + 2 * z);
            t3 += *(v4flt *)(src[i] + j + 3 * z);
        }
        *(v4flt *)(dst + j + 0 * z) = t0;
        *(v4flt *)(dst + j + 1 * z) = t1;
        *(v4flt *)(dst + j + 2 * z) = t2;
        *(v4flt *)(dst + j + 3 * z) = t3;
    }
    for (; j < n; ++j)
    {
        float t = src[0][j];
        for (i = 1; i < a; ++i)
            t += src[i][j];
        dst[j] = t;
    }
}

// Buffer used for aligned memory
float buffer[64];

int main()
{
    int i;
    float *dst, *src[2];
    char *cptr;

    // Aligning the buffer to 16-byte boundary
    cptr = (char *)buffer;
    cptr += (-(long int)buffer & (16 * sizeof(float) - 1));
    dst = (float *)cptr;
    src[0] = dst + 16;
    src[1] = dst + 32;

    // Initializing src arrays with fixed values
    for (i = 0; i < 16; ++i)
    {
        src[0][i] = i + 1.0f;  // Example fixed initialization
        src[1][i] = (i + 1.0f) * 2; // Example fixed initialization
    }

    foo(dst, src, 2, 16);

    // Check with expected results and print the result
    // Assuming expected values are the sum of both sources
    for (i = 0; i < 16; ++i)
    {
        float expected = src[0][i] + src[1][i];
        printf("dst[%d] = %f, expected = %f\n", i, dst[i], expected);
        assert(dst[i] == expected);
    }
    
    printf("All assertions passed.\n");
    return 0;
}