#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>

typedef int32_t __int32_t;
typedef uint32_t __uint32_t;

/* A union to convert between a double and two 32-bit integers. */
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

static const double two54_scalbn = 1.80143985094819840000e+16;
static const double twom54_scalbn = 5.55111512312578270212e-17;
static const double huge_scalbn = 1.0e+300, tiny_scalbn = 1.0e-300;

double scalbn_double(double x, int n) {
    __int32_t k, hx, lx;
    ieee_double_shape_type ew_u;
    ew_u.value = x;
    hx = ew_u.parts.msw;
    lx = ew_u.parts.lsw;
    
    k = (hx & 0x7ff00000) >> 20;
    
    if (k == 0) {
        if ((lx | (hx & 0x7fffffff)) == 0) return x;
        x *= two54_scalbn;
        ieee_double_shape_type gh_u;
        gh_u.value = x;
        hx = gh_u.parts.msw;
        k = ((hx & 0x7ff00000) >> 20) - 54;
        if (n < -50000) return tiny_scalbn * x;
    }
    
    if (k == 0x7ff) return x + x;
    k += n;
    if (k > 0x7fe) return huge_scalbn * copysign_double(huge_scalbn, x);
    
    if (k > 0) {
        ieee_double_shape_type sh_u;
        sh_u.value = x;
        sh_u.parts.msw = ((hx & 0x800fffff) | (k << 20));
        x = sh_u.value;
        return x;
    }
    
    if (k <= -54) {
        if (n > 50000) return huge_scalbn * copysign_double(huge_scalbn, x);
        else return tiny_scalbn * copysign_double(tiny_scalbn, x);
    }
    
    k += 54;
    ieee_double_shape_type sh_u;
    sh_u.value = x;
    sh_u.parts.msw = ((hx & 0x800fffff) | (k << 20));
    x = sh_u.value;
    
    return x * twom54_scalbn;
}

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
        z = 1.0 - tiny_sqrt;
        if (z >= 1.0) {
            z = 1.0 + tiny_sqrt;
            if (q1 == (__uint32_t)0xffffffff) {
                q1 = 0;
                q += 1;
            } else if (z > 1.0) {
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
    sh_u.parts.msw = (high & 0x7fffffff);
    x = sh_u.value;
    
    return x;
}

// Additional constants trimmed for brevity

double __ieee754_pow(double x, double y) {
    double z, ax, z_h, z_l, p_h, p_l;
    double y1, t1, t2, r, s, t, u, v, w;
    __int32_t i, j, k, yisint, n;
    __int32_t hx, hy, ix, iy;
    __uint32_t lx, ly;

    ieee_double_shape_type ew_u;
    ew_u.value = x;
    hx = ew_u.parts.msw;
    lx = ew_u.parts.lsw;
    
    ew_u.value = y;
    hy = ew_u.parts.msw;
    ly = ew_u.parts.lsw;
    
    ix = hx & 0x7fffffff;
    iy = hy & 0x7fffffff;

    if ((iy | ly) == 0) return 1.0;
    
    if (ix > 0x7ff00000 || ((ix == 0x7ff00000) && (lx != 0)) || iy > 0x7ff00000 || ((iy == 0x7ff00000) && (ly != 0))) {
        if (((ix - 0x3ff00000) | lx) == 0) return 1.0;
        else return NAN;
    }
    
    yisint = 0;
    if (hx < 0) {
        if (iy >= 0x43400000) yisint = 2;
        else if (iy >= 0x3ff00000) {
            k = (iy >> 20) - 0x3ff;
            if (k > 20) {
                j = ly >> (52 - k);
                if ((j << (52 - k)) == ly) yisint = 2 - (j & 1);
            } else if (ly == 0) {
                j = iy >> (20 - k);
                if ((j << (20 - k)) == iy) yisint = 2 - (j & 1);
            }
        }
    }

    if (ly == 0) {
        if (iy == 0x7ff00000) {
            if (((ix - 0x3ff00000) | lx) == 0) return 1.0;
            else if (ix >= 0x3ff00000) return (hy >= 0) ? y : 0.0;
            else return (hy < 0) ? -y : 0.0;
        }
        if (iy == 0x3ff00000) {
            if (hy < 0) return 1.0 / x;
            else return x;
        }
        if (hy == 0x40000000) return x * x;
        if (hy == 0x3fe00000) {
            if (hx >= 0) return __ieee754_sqrt(x);
        }
    }

    ax = fabs_double(x);

    if (lx == 0) {
        if (ix == 0x7ff00000 || ix == 0 || ix == 0x3ff00000) {
            z = ax;
            if (hy < 0) z = 1.0 / z;
            if (hx < 0) {
                if (((ix - 0x3ff00000) | yisint) == 0) {
                    z = (z - z) / (z - z);
                } else if (yisint == 1) z = -z;
            }
            return z;
        }
    }

    if (((((__uint32_t)hx >> 31) - 1) | yisint) == 0) return (x - x) / (x - x);

    if (iy > 0x41e00000) {
        if (iy > 0x43f00000) {
            if (ix <= 0x3fefffff) return (hy < 0) ? huge_pow * huge_pow : tiny_pow * tiny_pow;
            if (ix >= 0x3ff00000) return (hy > 0) ? huge_pow * huge_pow : tiny_pow * tiny_pow;
        }

        if (ix < 0x3fefffff) return (hy < 0) ? huge_pow * huge_pow : tiny_pow * tiny_pow;
        if (ix > 0x3ff00000) return (hy > 0) ? huge_pow * huge_pow : tiny_pow * tiny_pow;

        t = ax - 1;
        w = (t * t) * (0.5 - t * (0.3333333333333333333333 - t * 0.25));
        u = ivln2_h_pow * t;
        v = t * ivln2_l_pow - w * ivln2_pow;
        t1 = u + v;
        ieee_double_shape_type sl_u;
        sl_u.value = t1;
        sl_u.parts.lsw = 0;
        t1 = sl_u.value;
        t2 = v - (t1 - u);
    } else {
        double s2, s_h, s_l, t_h, t_l;
        n = 0;

        if (ix < 0x00100000) {
            ax *= two53_pow;
            n -= 53;
            ieee_double_shape_type gh_u;
            gh_u.value = ax;
            ix = gh_u.parts.msw;
        }

        n += ((ix) >> 20) - 0x3ff;
        j = ix & 0x000fffff;

        ix = j | 0x3ff00000;
        if (j <= 0x3988E) k = 0;
        else if (j < 0xBB67A) k = 1;
        else {
            k = 0;
            n += 1;
            ix -= 0x00100000;
        }

        ieee_double_shape_type sh_u;
        sh_u.value = ax;
        sh_u.parts.msw = ix;
        ax = sh_u.value;

        u = ax - bp_pow[k];
        v = 1.0 / (ax + bp_pow[k]);
        s = u * v;
        s_h = s;
        ieee_double_shape_type sl_u;
        sl_u.value = s_h;
        sl_u.parts.lsw = 0;
        s_h = sl_u.value;

        t_h = 0.0;
        ieee_double_shape_type sh_u;
        sh_u.value = t_h;
        sh_u.parts.msw = (((ix >> 1) | 0x20000000) + 0x00080000 + (k << 18));
        t_h = sh_u.value;
        
        t_l = ax - (t_h - bp_pow[k]);
        s_l = v * ((u - s_h * t_h) - s_h * t_l);

        s2 = s * s;
        r = s2 * s2 * (L1_pow + s2 * (L2_pow + s2 * (L3_pow + s2 * (L4_pow + s2 * (L5_pow + s2 * L6_pow)))));
        r += s_l * (s_h + s);
        s2 = s_h * s_h;
        t_h = 3.0 + s2 + r;
        ieee_double_shape_type sl_u;
        sl_u.value = t_h;
        sl_u.parts.lsw = 0;
        t_h = sl_u.value;
        t_l = r - ((t_h - 3.0) - s2);

        u = s_h * t_h;
        v = s_l * t_h + t_l * s;

        p_h = u + v;
        ieee_double_shape_type sl_u;
        sl_u.value = p_h;
        sl_u.parts.lsw = 0;
        p_h = sl_u.value;
        p_l = v - (p_h - u);
        z_h = cp_h_pow * p_h;
        z_l = cp_l_pow * p_h + p_l * cp_pow + dp_l_pow[k];

        t = (double)n;
        t1 = (((z_h + z_l) + dp_h_pow[k]) + t);
        ieee_double_shape_type sl_u;
        sl_u.value = t1;
        sl_u.parts.lsw = 0;
        t1 = sl_u.value;
        t2 = z_l - (((t1 - t) - dp_h_pow[k]) - z_h);
    }

    s = 1.0;
    if (((((__uint32_t)hx >> 31) - 1) | (yisint - 1)) == 0) s = -1.0;

    y1 = y;
    ieee_double_shape_type sl_u;
    sl_u.value = y1;
    sl_u.parts.lsw = 0;
    y1 = sl_u.value;
    
    p_l = (y - y1) * t1 + y * t2;
    p_h = y1 * t1;
    z = p_l + p_h;
    ieee_double_shape_type ew_u;
    ew_u.value = z;
    j = ew_u.parts.msw;
    i = ew_u.parts.lsw;
    
    if (j >= 0x40900000) {
        if (((j - 0x40900000) | i) != 0) return s * huge_pow * huge_pow;
        else {
            if (p_l + ovt_pow > z - p_h) return s * huge_pow * huge_pow;
        }
    } else if ((j & 0x7fffffff) >= 0x4090cc00) {
        if (((j - 0xc090cc00) | i) != 0) return s * tiny_pow * tiny_pow;
        else {
            if (p_l <= z - p_h) return s * tiny_pow * tiny_pow;
        }
    }

    i = j & 0x7fffffff;
    k = (i >> 20) - 0x3ff;
    n = 0;
    if (i > 0x3fe00000) {
        n = j + (0x00100000 >> (k + 1));
        k = ((n & 0x7fffffff) >> 20) - 0x3ff;
        t = 0.0;
        ieee_double_shape_type sh_u;
        sh_u.value = t;
        sh_u.parts.msw = (n & ~(0x000fffff >> k));
        t = sh_u.value;
        n = ((n & 0x000fffff) | 0x00100000) >> (20 - k);
        if (j < 0) n = -n;
        p_h -= t;
    }

    t = p_l + p_h;
    ieee_double_shape_type sl_u;
    sl_u.value = t;
    sl_u.parts.lsw = 0;
    t = sl_u.value;
    
    u = t * lg2_h_pow;
    v = (p_l - (t - p_h)) * lg2_pow + t * lg2_l_pow;
    z = u + v;
    w = v - (z - u);
    t = z * z;
    t1 = z - t * (P1_pow + t * (P2_pow + t * (P3_pow + t * (P4_pow + t * P5_pow))));
    r = (z * t1) / (t1 - 2.0) - (w + z * w);
    z = 1.0 - (r - z);
    ieee_double_shape_type gh_u;
    gh_u.value = z;
    j = gh_u.parts.msw;
    
    j += (n << 20);
    if ((j >> 20) <= 0) z = scalbn_double(z, (int)n);
    else {
        ieee_double_shape_type sh_u;
        sh_u.value = z;
        sh_u.parts.msw = j;
        z = sh_u.value;
    }
    
    return s * z;
}

int main() {
    double x = 3.14159; // Example fixed double value; choose an appropriate value for testing.
    double y = 0.0;
    double res = __ieee754_pow(x, y);

    // result shall be 1.0
    assert(res == 1.0);

    return 0;
}