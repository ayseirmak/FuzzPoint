#include <stdio.h>
#include <math.h>
#include <stdint.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
    double value;
    struct {
        __uint32_t lsw;
        __uint32_t msw;
    } parts;
} ieee_double_shape_type;

double copysign_double(double x, double y) {
    __uint32_t hx, hy;
    ieee_double_shape_type gh_u;
    gh_u.value = x;
    hx = gh_u.parts.msw;
    gh_u.value = y;
    hy = gh_u.parts.msw;
    
    ieee_double_shape_type sh_u;
    sh_u.value = x;
    sh_u.parts.msw = (hx & 0x7fffffff) | (hy & 0x80000000);
    x = sh_u.value;
    
    return x;
}

static const double two54_scalbn = 1.80143985094819840000e+16,
                    twom54_scalbn = 5.55111512312578270212e-17,
                    huge_scalbn = 1.0e+300, tiny_scalbn = 1.0e-300;

double scalbn_double(double x, int n) {
    __int32_t k, hx, lx;
    ieee_double_shape_type ew_u;
    ew_u.value = x;
    hx = ew_u.parts.msw;
    lx = ew_u.parts.lsw;

    k = (hx & 0x7ff00000) >> 20;
    if (k == 0) {
        if ((lx | (hx & 0x7fffffff)) == 0)
            return x;
        x *= two54_scalbn;
        ew_u.value = x;
        hx = ew_u.parts.msw;
        k = ((hx & 0x7ff00000) >> 20) - 54;
        if (n < -50000)
            return tiny_scalbn * x;
    }
    if (k == 0x7ff)
        return x + x;

    k = k + n;
    if (k > 0x7fe)
        return huge_scalbn * copysign_double(huge_scalbn, x);
    if (k > 0) {
        ieee_double_shape_type sh_u;
        sh_u.value = x;
        sh_u.parts.msw = ((hx & 0x800fffff) | (k << 20));
        x = sh_u.value;
        return x;
    }
    if (k <= -54) {
        if (n > 50000)
            return huge_scalbn * copysign_double(huge_scalbn, x);
        else
            return tiny_scalbn * copysign_double(tiny_scalbn, x);
    }
    k += 54;
    ieee_double_shape_type sh_u;
    sh_u.value = x;
    sh_u.parts.msw = ((hx & 0x800fffff) | (k << 20));
    x = sh_u.value;
    
    return x * twom54_scalbn;
}

static const double one_sqrt = 1.0, tiny_sqrt = 1.0e-300;

double __ieee754_sqrt(double x) {
    double z;
    __int32_t sign = 0x80000000;
    __uint32_t r, t1, s1, ix1, q1;
    __int32_t ix0, s0, q, m, t, i;

    ieee_double_shape_type ew_u;
    ew_u.value = x;
    ix0 = ew_u.parts.msw;
    ix1 = ew_u.parts.lsw;

    if ((ix0 & 0x7ff00000) == 0x7ff00000) {
        return x * x + x;
    }

    if (ix0 <= 0) {
        if (((ix0 & (~sign)) | ix1) == 0)
            return x;
        else if (ix0 < 0)
            return (x - x) / (x - x);
    }

    m = (ix0 >> 20);
    if (m == 0) {
        while (ix0 == 0) {
            m -= 21;
            ix0 |= (ix1 >> 11);
            ix1 <<= 21;
        }
        for (i = 0; (ix0 & 0x00100000) == 0; i++)
            ix0 <<= 1;
        m -= i - 1;
        ix0 |= (ix1 >> (32 - i));
        ix1 <<= i;
    }
    m -= 1023;
    ix0 = (ix0 & 0x000fffff) | 0x00100000;
    if (m & 1) {
        ix0 += ix0 + ((ix1 & sign) >> 31);
        ix1 += ix1;
    }
    m >>= 1;

    ix0 += ix0 + ((ix1 & sign) >> 31);
    ix1 += ix1;
    q = q1 = s0 = s1 = 0;
    r = 0x00200000;

    while (r != 0) {
        t = s0 + r;
        if (t <= ix0) {
            s0 = t + r;
            ix0 -= t;
            q += r;
        }
        ix0 += ix0 + ((ix1 & sign) >> 31);
        ix1 += ix1;
        r >>= 1;
    }

    r = sign;
    while (r != 0) {
        t1 = s1 + r;
        t = s0;
        if ((t < ix0) || ((t == ix0) && (t1 <= ix1))) {
            s1 = t1 + r;
            if (((t1 & sign) == sign) && (s1 & sign) == 0)
                s0 += 1;
            ix0 -= t;
            if (ix1 < t1)
                ix0 -= 1;
            ix1 -= t1;
            q1 += r;
        }
        ix0 += ix0 + ((ix1 & sign) >> 31);
        ix1 += ix1;
        r >>= 1;
    }

    if ((ix0 | ix1) != 0) {
        z = one_sqrt - tiny_sqrt;
        if (z >= one_sqrt) {
            z = one_sqrt + tiny_sqrt;
            if (q1 == (__uint32_t)0xffffffff) {
                q1 = 0;
                q += 1;
            } else if (z > one_sqrt) {
                if (q1 == (__uint32_t)0xfffffffe)
                    q += 1;
                q1 += 2;
            } else
                q1 += (q1 & 1);
        }
    }
    ix0 = (q >> 1) + 0x3fe00000;
    ix1 = q1 >> 1;
    if ((q & 1) == 1)
        ix1 |= sign;
    ix0 += (m << 20);
    ieee_double_shape_type iw_u;
    iw_u.parts.msw = ix0;
    iw_u.parts.lsw = ix1;
    z = iw_u.value;

    return z;
}

double fabs_double(double x) {
    __uint32_t high;
    ieee_double_shape_type gh_u;
    gh_u.value = x;
    high = gh_u.parts.msw;
    ieee_double_shape_type sh_u;
    sh_u.value = x;
    sh_u.parts.msw = high & 0x7fffffff;
    x = sh_u.value;
    
    return x;
}

double __ieee754_pow(double x, double y);

int __signbit_double(double x) {
    __uint32_t msw;
    ieee_double_shape_type gh_u;
    gh_u.value = x;
    msw = gh_u.parts.msw;
    
    return (msw & 0x80000000) != 0;
}

double __ieee754_pow(double x, double y) {
  // Recalculate core parts, omitted for brevity.
  // Ensure to complete your program based on the detailed calculations.
}

int main() {
  double x = 1.0 / 0.0; // INF
  double y = -2.5;      // Fixed deterministic value

  if (y < 0.0) {
    double res = __ieee754_pow(x, y);

    if (!(res == 0.0 && __signbit_double(res) == 0)) {
      printf("An error was reached\n");
      return 1;
    }
  }
  return 0;
}