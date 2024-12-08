#include <stdio.h>

// Define assertion-based error approach
void reach_error() {
    printf("Assertion failed: reached error function.\n");
}

// A union which permits us to convert between a double and two 32-bit ints.
typedef union {
    double value;
    struct {
        unsigned int lsw;
        unsigned int msw;
    } parts;
} ieee_double_shape_type;

int isnan_double(double x) {
    return x != x;
}

static const double huge_floor = 1.0e300;

double floor_double(double x) {
    int i0, i1, j0;
    unsigned int i, j;
    ieee_double_shape_type ew_u;
    ew_u.value = x;
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
        i = (unsigned int)(0xffffffff) >> (j0 - 20);
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
    iw_u.parts.msw = i0;
    iw_u.parts.lsw = i1;
    x = iw_u.value;
    return x;
}

double copysign_double(double x, double y) {
    unsigned int hx, hy;
    ieee_double_shape_type gh_u;
    gh_u.value = x;
    hx = gh_u.parts.msw;
    gh_u.value = y;
    hy = gh_u.parts.msw;
    
    ieee_double_shape_type sh_u;
    sh_u.value = x;
    sh_u.parts.msw = ((hx & 0x7fffffff) | (hy & 0x80000000));
    x = sh_u.value;
    return x;
}

static const double two54_scalbn = 1.80143985094819840000e+16,
                    twom54_scalbn = 5.55111512312578270212e-17,
                    huge_scalbn = 1.0e+300, tiny_scalbn = 1.0e-300;

double scalbn_double(double x, int n) {
    int k, hx, lx;
    ieee_double_shape_type ew_u;
    ew_u.value = x;
    hx = ew_u.parts.msw;
    lx = ew_u.parts.lsw;
    
    k = (hx & 0x7ff00000) >> 20;
    if (k == 0) {
        if ((lx | (hx & 0x7fffffff)) == 0)
            return x;
        x *= two54_scalbn;
        ieee_double_shape_type gh_u;
        gh_u.value = x;
        hx = gh_u.parts.msw;
        
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
    ieee_double_shape_type sh_u_;
    sh_u_.value = x;
    sh_u_.parts.msw = ((hx & 0x800fffff) | (k << 20));
    x = sh_u_.value;
    return x * twom54_scalbn;
}

double fabs_double(double x) {
    unsigned int high;
    ieee_double_shape_type gh_u;
    gh_u.value = x;
    high = gh_u.parts.msw;
    
    ieee_double_shape_type sh_u;
    sh_u.value = x;
    sh_u.parts.msw = (high & 0x7fffffff);
    x = sh_u.value;
    return x;
}

int __kernel_rem_pio2(double *x, double *y, int e0, int nx, int prec, const int *ipio2) {
    int jk = 3;
    int jp = jk;
    
    int jx = nx - 1;
    int jv = (e0 - 3) / 24;
    if (jv < 0) jv = 0;
    int q0 = e0 - 24 * (jv + 1);
    
    double f[20] = {0};
    for (int i = 0, j = jv - jx; i <= nx + jk; ++i, ++j)
        f[i] = (j < 0) ? 0.0 : (double)ipio2[j];

    double q[20] = {0.0};
    for (int i = 0; i <= jk; ++i) {
        double fw = 0.0;
        for (int j = 0; j <= jx; ++j)
            fw += x[j] * f[jx + i - j];
        q[i] = fw;
    }

    int jz = jk;
    double z = q[jz];
    double fw = (double)((int)(1.0 / (1 << 24) * z));
    int iq[20] = {0};
    iq[0] = (int)(z - (1 << 24) * fw);
    z = q[jz - 1] + fw;

    z = scalbn_double(z, (int)q0);

    z -= 8.0 * floor_double(z * 0.125);
    int n = (int)z;
    z -= (double)n;
    int ih = (q0 > 0) ? iq[jz - 1] >> (24 - q0) : (z >= 0.5) ? 2 : 0;
    n += (q0 > 0) ? iq[jz - 1] >> (24 - q0) : 0;
    
    if (ih > 0) {
        n++;
        int carry = 0;
        for (int i = 0; i < jz; ++i) {
            int j = iq[i];
            if (carry == 0) {
                if (j != 0) {
                    carry = 1;
                    iq[i] = 0x1000000 - j;
                }
            } else {
                iq[i] = 0xffffff - j;
            }
        }
        if (ih == 2) {
            z = 1.0 - z;
            if (carry != 0)
                z -= scalbn_double(1.0, (int)q0);
        }
    }
    if (z == 0.0) {
        jz--;
        q0 -= 24;
        while (iq[jz] == 0) {
            jz--;
            q0 -= 24;
        }
    } else {
        z = scalbn_double(z, -(int)q0);
        if (z >= (1 << 24)) {
            fw = (double)((int)(1.0 / (1 << 24) * z));
            iq[jz] = (int)(z - (1 << 24) * fw);
            jz++;
            q0 += 24;
            iq[jz] = (int)fw;
        } else {
            iq[jz] = (int)z;
        }
    }

    fw = scalbn_double(1.0, (int)q0);
    double fq[20] = {0.0};
    for (int i = jz; i >= 0; i--) {
        q[i] = fw * (double)iq[i];
        fw *= (1.0 / (1 << 24));
    }

    for (int i = jz; i >= 0; i--) {
        fw = 0.0;
        for (int k = 0; k <= jp && k <= jz - i; k++)
            fw += (3.14159265358979323846 / 2) * q[i + k];
        fq[jz - i] = fw;
    }

    switch (prec) {
        case 0:
            fw = 0.0;
            for (int i = jz; i >= 0; i--)
                fw += fq[i];
            y[0] = (ih == 0) ? fw : -fw;
            break;
        case 1:
        case 2:
            fw = 0.0;
            for (int i = jz; i >= 0; i--)
                fw += fq[i];
            y[0] = (ih == 0) ? fw : -fw;
            fw = fq[0] - fw;
            for (int i = 1; i <= jz; i++)
                fw += fq[i];
            y[1] = (ih == 0) ? fw : -fw;
            break;
        case 3:
            for (int i = jz; i > 0; i--) {
                fw = fq[i - 1] + fq[i];
                fq[i] += fq[i - 1] - fw;
                fq[i - 1] = fw;
            }
            for (int i = jz; i > 1; i--) {
                fw = fq[i - 1] + fq[i];
                fq[i] += fq[i - 1] - fw;
                fq[i - 1] = fw;
            }
            for (fw = 0.0, int i = jz; i >= 2; i--)
                fw += fq[i];
            if (ih == 0) {
                y[0] = fq[0];
                y[1] = fq[1];
                y[2] = fw;
            } else {
                y[0] = -fq[0];
                y[1] = -fq[1];
                y[2] = -fw;
            }
            break;
    }
    return n & 7;
}

int __ieee754_rem_pio2(double x, double *y) {
    double z = 0.0, w, t, r, fn;
    double tx[3] = {0.0};
    int i, j, n, ix, hx;
    unsigned int low;

    ieee_double_shape_type gh_u;
    gh_u.value = x;
    hx = gh_u.parts.msw;
    ix = hx & 0x7fffffff;

    if (ix <= 0x3fe921fb) { // Less than or equal to pi/2
        y[0] = x;
        y[1] = 0;
        return 0;
    }
    if (ix < 0x4002d97c) {
        if (hx > 0) {
            z = x - 1.5707963267948966; // pi/2
            if (ix != 0x3ff921fb) {
                y[0] = z - 6.123233995736766e-17; // pi/2 truncated
                y[1] = (z - y[0]) - 6.123233995736766e-17;
            } else {
                z -= 6.123233995736766e-17;
                y[0] = z - 2.02226624879595063154e-21;
                y[1] = (z - y[0]) - 2.02226624879595063154e-21;
            }
            return 1;
        } else {
            z = x + 1.5707963267948966; // pi/2
            if (ix != 0x3ff921fb) {
                y[0] = z + 6.123233995736766e-17;
                y[1] = (z - y[0]) + 6.123233995736766e-17;
            } else {
                z += 6.123233995736766e-17;
                y[0] = z + 2.02226624879595063154e-21;
                y[1] = (z - y[0]) + 2.02226624879595063154e-21;
            }
            return -1;
        }
    }
    if (ix <= 0x413921fb) {
        t = fabs_double(x);
        n = (int)(t * 6.36619772367581382433e-01 + 0.5); // invpio2
        fn = (double)n;
        r = t - fn * 1.5707963267948966; // pio2_1
        w = fn * 6.123233995736766e-17; // pio2_1t
        if (n < 32 && ix != npio2_hw_rempio[n - 1]) {
            y[0] = r - w;
        } else {
            double high;
            j = ix >> 20;
            y[0] = r - w;
            gh_u.value = y[0];
            high = gh_u.parts.msw;
            i = j - ((high >> 20) & 0x7ff);
            if (i > 16) {
                t = r;
                w = fn * 6.123233995736766e-17; // pio2_2
                r = t - w;
                w = fn * 2.02226624879595063154e-21 - ((t - r) - w); // pio2_2t
                y[0] = r - w;
                gh_u.value = y[0];
                high = gh_u.parts.msw;
                i = j - ((high >> 20) & 0x7ff);
                if (i > 49) {
                    t = r;
                    w = fn * 2.02226624871116645580e-21; // pio2_3
                    r = t - w;
                    w = fn * 8.47842766036889956997e-32 - ((t - r) - w); // pio2_3t
                    y[0] = r - w;
                }
            }
        }
        y[1] = (r - y[0]) - w;
        if (hx < 0) {
            y[0] = -y[0];
            y[1] = -y[1];
            return -n;
        } else
            return n;
    }

    if (ix >= 0x7ff00000) { // inf or NaN
        y[0] = y[1] = x - x;
        return 0;
    }

    ieee_double_shape_type gl_u;
    gl_u.value = x;
    low = gl_u.parts.lsw;
    ieee_double_shape_type sl_u;
    sl_u.value = z;
    sl_u.parts.lsw = low;
    z = sl_u.value;

    int e0 = (int)((ix >> 20) - 1046);
    sl_u.value = z;
    sl_u.parts.msw = (ix - ((int)e0 << 20));
    z = sl_u.value;

    for (i = 0; i < 2; i++) {
        tx[i] = (double)((int)(z));
        z = (z - tx[i]) * (1 << 24);
    }
    tx[2] = z;

    int nx = 3;
    while (tx[nx - 1] == 0.0)
        nx--;

    n = __kernel_rem_pio2(tx, y, e0, nx, 2, two_over_pi_rempio);
    if (hx < 0) {
        y[0] = -y[0];
        y[1] = -y[1];
        return -n;
    }
    return n;
}

double __kernel_tan(double x, double y, int iy) {
    const double one = 1.0;
    const double pio4 = 0.78539816339744830962;
    const double pio4_lo = 3.06161699786838301793e-17;
    const double T[] = {
        0.33333333333334091986,
        0.13333333333301242699,
        0.053968253972260521377,
        0.0218694882948595424599,
        0.00886323982359930005737,
        0.00359207910759131235356,
        0.00145620945432529025516,
        0.000588041240820264096874,
        0.00024646313481846906812,
        0.00007817944429395570923,
        0.0000714072492382608190305,
        -0.0000185586374855274556654,
        0.0000259073051863633712884,
    };

    double z, r, v, w, s;
    int ix, hx;
    ieee_double_shape_type gh_u;
    gh_u.value = x;
    hx = gh_u.parts.msw;
    ix = hx & 0x7fffffff;

    if (ix < 0x3e300000) {
        if ((int)x == 0) {
            unsigned int low;
            ieee_double_shape_type gl_u;
            gl_u.value = x;
            low = gl_u.parts.lsw;
            if (((ix | low) | (iy + 1)) == 0)
                return one / fabs_double(x);
            else
                return (iy == 1) ? x : -one / x;
        }
    }
    if (ix >= 0x3FE59428) {
        if (hx < 0) {
            x = -x;
            y = -y;
        }
        z = pio4 - x;
        w = pio4_lo - y;
        x = z + w;
        y = 0.0;
    }
    z = x * x;
    w = z * z;
    r = T[1] + w * (T[3] + w * (T[5] + w * (T[7] + w * (T[9] + w * T[11]))));
    v = z * (T[2] + w * (T[4] + w * (T[6] + w * (T[8] + w * (T[10] + w * T[12])))));
    s = z * x;
    r = y + z * (s * (r + v) + y);
    r += T[0] * s;
    w = x + r;
    if (ix >= 0x3FE59428) {
        v = (double)iy;
        return (double)(1 - ((hx >> 30) & 2)) * (v - 2.0 * (x - (w * w / (w + v) - r)));
    }
    if (iy == 1)
        return w;
    else {
        double a, t;
        z = w;
        ieee_double_shape_type sl_u;
        sl_u.value = z;
        sl_u.parts.lsw = 0;
        z = sl_u.value;
        v = r - (z - x);
        t = a = -1.0 / w;
        ieee_double_shape_type sl_u_;
        sl_u_.value = t;
        sl_u_.parts.lsw = 0;
        t = sl_u_.value;
        s = 1.0 + t * z;
        return t + a * (s + t * v);
    }
}

double tan_double(double x) {
    double y[2], z = 0.0;
    int n, ix;
    ieee_double_shape_type gh_u;
    gh_u.value = x;
    ix = gh_u.parts.msw;
    
    ix &= 0x7fffffff;
    if (ix <= 0x3fe921fb) return __kernel_tan(x, z, 1); // Argument not reduced
    else if (ix >= 0x7ff00000) return x - x; // NaN or Inf
    else {
        n = __ieee754_rem_pio2(x, y);
        return __kernel_tan(y[0], y[1], 1 - ((n & 1) << 1));
    }
}

int __signbit_double(double x) {
    unsigned int msw;
    ieee_double_shape_type gh_u;
    gh_u.value = x;
    msw = gh_u.parts.msw;
    return (msw & 0x80000000) != 0;
}

int main() {
    // Fixed input value for deterministic execution
    double x = -0.0;
    double res = tan_double(x);

    if (!(res == -0.0 && __signbit_double(res) == 1)) {
        reach_error();
        return 1;
    }

    printf("Test passed: tan_double(-0.0) returned -0.0\n");
    return 0;
}