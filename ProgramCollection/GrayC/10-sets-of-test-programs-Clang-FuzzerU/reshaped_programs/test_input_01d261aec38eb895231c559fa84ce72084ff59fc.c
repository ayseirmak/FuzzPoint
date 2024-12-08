#include <stdio.h>

#define CHUNK 500

typedef int l[CHUNK];

void s(int arg_count, ...);
void z(int arg_count, ...);
void c(int arg_count, ...);

void f(int n)
{
    int i;
    l a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;
    l a10, a11, a12, a13, a14, a15, a16, a17, a18, a19;
    l a20, a21, a22, a23, a24, a25, a26, a27, a28, a29;
    l a30, a31, a32, a33, a34, a35, a36, a37, a38, a39;
    int i0, i1, i2, i3, i4, i5, i6, i7, i8, i9;
    int i10, i11, i12, i13, i14, i15, i16, i17, i18, i19;
    int i20, i21, i22, i23, i24, i25, i26, i27, i28, i29;
    int i30, i31, i32, i33, i34, i35, i36, i37, i38, i39;

    for (i = 0; i < n; i++) {
        s(40, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,
           a10, a11, a12, a13, a14, a15, a16, a17, a18, a19,
           a20, a21, a22, a23, a24, a25, a26, a27, a28, a29,
           a30, a31, a32, a33, a34, a35, a36, a37, a38, a39);
        printf("Loop iteration: %d\n", i);
    }
}

void foo(float *x);

int main()
{
    float x[4] = {0};
    int n = 5; // Fixed deterministic input

    f(n);
    foo(x);

    return 0;
}

void foo(float *x)
{
    int i, j, k;
    float temp;
    static float t16[16] = {1., 2., 3., 4., 5., 6., 7., 8.,
                            9., 10., 11., 12., 13., 14., 15., 16.};
    static float tmp[4] = {0., 0., 0., 0.};

    for (i = 0; i < 4; i++) {
        k = 3 - i;
        temp = t16[5 * k];
        for (j = k + 1; j < 4; j++) {
            tmp[k] += t16[k + j * 4] * temp;
        }
    }

    x[0] = tmp[0];
    x[1] = tmp[1];
    x[2] = tmp[2];
    x[3] = tmp[3];
}