#include <stdio.h>
#include <math.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

/* A union which permits us to convert between a double and two 32 bit ints.  */
typedef union {
    double value;
    struct {
        __uint32_t lsw;
        __uint32_t msw;
    } parts;
} ieee_double_shape_type;

/* Get a 32 bit int from a float.  */
/* Set a float from a 32 bit int.  */
/* Macros to avoid undefined behaviour that can arise if the amount
   of a shift is exactly equal to the size of the shifted operand.  */
static const double huge_floor = 1.0e300;

double floor_double(double x) {
    __int32_t i0, i1, j0;
    __uint32_t i, j;
    ieee_double_shape_type ew_u;
    ew_u.value = (x);
    i0 = ew_u.parts.msw;
    i1 = ew_u.parts.lsw;
    
    j0 = ((i0 >> 20) & 0x7ff) - 0x3ff;
    if (j0 < 20) {
        if (j0 < 0) {
            if (huge_floor + x > 0.0) {
                if (i0 >= 0) {
                    i0 = i1 = 0;
                } else if (((i0 & 0x7fffffff) | i1) != 0) {
                    i0 = 0xbff00000;
                    i1 = 0;
                }
            }
        } else {
            i = (0x000fffff) >> j0;
            if (((i0 & i) | i1) == 0)
                return x;
            if (huge_floor + x > 0.0) {
                if (i0 < 0)
                    i0 += (0x00100000) >> j0;
                i0 &= (~i);
                i1 = 0;
            }
        }
    } else if (j0 > 51) {
        if (j0 == 0x400)
            return x + x;
        else
            return x;
    } else {
        i = ((__uint32_t)(0xffffffff)) >> (j0 - 20);
        if ((i1 & i) == 0)
            return x;
        if (huge_floor + x > 0.0) {
            if (i0 < 0) {
                if (j0 == 20)
                    i0 += 1;
                else {
                    j = i1 + (1 << (52 - j0));
                    if (j < i1)
                        i0 += 1;
                    i1 = j;
                }
            }
            i1 &= (~i);
        }
    }
    ieee_double_shape_type iw_u;
    iw_u.parts.msw = (i0);
    iw_u.parts.lsw = (i1);
    x = iw_u.value;
    return x;
}

// NaN check for doubles
int isnan_double(double x) {
    return x != x;
}

double copysign_double(double x, double y) {
    __uint32_t hx, hy;
    ieee_double_shape_type gh_u;
    
    gh_u.value = (x);
    hx = gh_u.parts.msw;
    
    gh_u.value = (y);
    hy = gh_u.parts.msw;
    
    ieee_double_shape_type sh_u;
    sh_u.value = (x);
    sh_u.parts.msw = ((hx & 0x7fffffff) | (hy & 0x80000000));
    x = sh_u.value;
    
    return x;
}

double scalbn_double(double x, int n) {
    __int32_t k, hx, lx;
    ieee_double_shape_type ew_u;
    ew_u.value = (x);
    hx = ew_u.parts.msw;
    lx = ew_u.parts.lsw;
    
    k = (hx & 0x7ff00000) >> 20;
    if (k == 0) {
        if ((lx | (hx & 0x7fffffff)) == 0)
            return x;
        x *= 1.80143985094819840000e+16;
        ieee_double_shape_type gh_u;
        gh_u.value = (x);
        hx = gh_u.parts.msw;
        
        k = ((hx & 0x7ff00000) >> 20) - 54;
        if (n < -50000)
            return 1.0e-300 * x;
    }
    if (k == 0x7ff)
        return x + x;
    k = k + n;
    if (k > 0x7fe)
        return 1.0e+300 * copysign_double(1.0e+300, x);
    
    if (k > 0) {
        ieee_double_shape_type sh_u;
        sh_u.value = (x);
        sh_u.parts.msw = ((hx & 0x800fffff) | (k << 20));
        x = sh_u.value;
        return x;
    }
    
    if (k <= -54) {
        if (n > 50000)
            return 1.0e+300 * copysign_double(1.0e+300, x);
        else
            return 1.0e-300 * copysign_double(1.0e-300, x);
    }
    
    k += 54;
    ieee_double_shape_type sh_u;
    sh_u.value = (x);
    sh_u.parts.msw = ((hx & 0x800fffff) | (k << 20));
    x = sh_u.value;
    
    return x * 5.55111512312578270212e-17;
}

double fabs_double(double x) {
    __uint32_t high;
    ieee_double_shape_type gh_u;
    gh_u.value = (x);
    high = gh_u.parts.msw;
    
    ieee_double_shape_type sh_u;
    sh_u.value = (x);
    sh_u.parts.msw = (high & 0x7fffffff);
    x = sh_u.value;
    return x;
}

double __kernel_cos(double x, double y) {
    double a, hz, z, r, qx;
    __int32_t ix;
    ieee_double_shape_type gh_u;
    gh_u.value = (x);
    ix = gh_u.parts.msw;
    
    ix &= 0x7fffffff;
    if (ix < 0x3e400000) {
        if ((int)x == 0)
            return 1.0;
    }
    z = x * x;
    r = z * (4.16666666666666019037e-02 +
             z * (-1.38888888888741095749e-03 +
                  z * (2.48015872894767294178e-05 +
                       z * (-2.75573143513906633035e-07 +
                            z * (2.08757232129817482790e-09 +
                                 z * -1.13596475577881948265e-11)))));
    if (ix < 0x3FD33333)
        return 1.0 - (0.5 * z - (z * r - x * y));
    else {
        if (ix > 0x3fe90000) {
            qx = 0.28125;
        } else {
            ieee_double_shape_type iw_u;
            iw_u.parts.msw = (ix - 0x00200000);
            iw_u.parts.lsw = (0);
            qx = iw_u.value;
        }
        
        hz = 0.5 * z - qx;
        a = 1.0 - qx;
        return a - (hz - (z * r - x * y));
    }
}

double __kernel_sin(double x, double y, int iy) {
    double z, r, v;
    __int32_t ix;
    ieee_double_shape_type gh_u;
    gh_u.value = (x);
    ix = gh_u.parts.msw;
    
    ix &= 0x7fffffff;
    if (ix < 0x3e400000) {
        if ((int)x == 0)
            return x;
    }
    z = x * x;
    v = z * x;
    r = 8.33333333332248946124e-03 +
        z * (-1.98412698298579493134e-04 +
             z * (2.75573137070700676789e-06 +
                  z * (-2.50507602534068634195e-08 +
                       z * 1.58969099521155010221e-10)));
    if (iy == 0)
        return x + v * (-1.66666666666666324348e-01 + z * r);
    else
        return x - ((z * (0.5 * y - v * r) - y) - v * -1.66666666666666324348e-01);
}

double cos_double(double x) {
    double y[2], z = 0.0;
    __int32_t n, ix;
    ieee_double_shape_type gh_u;
    gh_u.value = (x);
    ix = gh_u.parts.msw;
    
    ix &= 0x7fffffff;
    if (ix <= 0x3fe921fb)
        return __kernel_cos(x, z);
    else if (ix >= 0x7ff00000)
        return x - x;
    else {
        n = __ieee754_rem_pio2(x, y);
        switch (n & 3) {
        case 0:
            return __kernel_cos(y[0], y[1]);
        case 1:
            return -__kernel_sin(y[0], y[1], 1);
        case 2:
            return -__kernel_cos(y[0], y[1]);
        default:
            return __kernel_sin(y[0], y[1], 1);
        }
    }
}

int main() {
    double x = INFINITY; // INF
    double res = cos_double(x);

    // x is +INF, the result shall be NaN
    if (!isnan_double(res)) {
        printf("Error: Result is not NaN.\n");
        return 1;
    }

    printf("Test passed: Result is NaN as expected.\n");

    return 0;
}