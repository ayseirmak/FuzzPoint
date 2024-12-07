#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <float.h>
#include <assert.h>

// Helper function to simulate reach_error in terms of assertion failure
void reach_error() {
    assert(0 && "Error reached: reach_error");
}

// All required constants (define them once)
static const double atanhi_atan[] = {
    4.63647609000806093515e-01,
    7.85398163397448278999e-01,
    9.82793723247329054082e-01,
    1.57079632679489655800e+00,
};

static const double atanlo_atan[] = {
    2.26987774529616870924e-17,
    3.06161699786838301793e-17,
    1.39033110312309984516e-17,
    6.12323399573676603587e-17,
};

static const double aT_atan[] = {
    3.33333333333329318027e-01, -1.99999999998764832476e-01,
    1.42857142725034663711e-01, -1.11111104054623557880e-01,
    9.09088713343650656196e-02, -7.69187620504482999495e-02,
    6.66107313738753120669e-02, -5.83357013379057348645e-02,
    4.97687799461593236017e-02, -3.65315727442169155270e-02,
    1.62858201153657823623e-02,
};

static const double one_atan = 1.0, pi_o_4 = 7.8539816339744827900E-01,
                    pi_o_2 = 1.5707963267948965580E+00,
                    pi = 3.1415926535897931160E+00, huge_atan = 1.0e300;

static const double tiny_atan2 = 1.0e-300, zero_atan2 = 0.0,
                    pi_lo_atan2 = 1.2246467991473531772E-16;

// A union which permits us to convert between a double and two 32 bit ints
typedef union {
    double value;
    struct {
        uint32_t lsw;
        uint32_t msw;
    } parts;
} ieee_double_shape_type;

// Return absolute value of a double
double fabs_double(double x) {
    ieee_double_shape_type shape;
    shape.value = x;
    shape.parts.msw &= 0x7fffffff;
    return shape.value;
}

// Computes arc tangent
double atan_double(double x) {
    double w, s1, s2, z;
    int32_t ix, hx, id;

    ieee_double_shape_type shape;
    shape.value = x;
    hx = shape.parts.msw;
    ix = hx & 0x7fffffff;
    if (ix >= 0x44100000) {
        uint32_t low = shape.parts.lsw;
        if (ix > 0x7ff00000 || (ix == 0x7ff00000 && (low != 0)))
            return x + x;
        if (hx > 0)
            return atanhi_atan[3] + atanlo_atan[3];
        else
            return -atanhi_atan[3] - atanlo_atan[3];
    }
    if (ix < 0x3fdc0000) {
        if (ix < 0x3e200000) {
            if (huge_atan + x > one_atan)
                return x;
        }
        id = -1;
    } else {
        x = fabs_double(x);
        if (ix < 0x3ff30000) {
            if (ix < 0x3fe60000) {
                id = 0;
                x = (2.0 * x - one_atan) / (2.0 + x);
            } else {
                id = 1;
                x = (x - one_atan) / (x + one_atan);
            }
        } else {
            if (ix < 0x40038000) {
                id = 2;
                x = (x - 1.5) / (one_atan + 1.5 * x);
            } else {
                id = 3;
                x = -1.0 / x;
            }
        }
    }

    z = x * x;
    w = z * z;

    s1 = z * (aT_atan[0] + w * (aT_atan[2] + w * (aT_atan[4] + w * (aT_atan[6] + w * (aT_atan[8] + w * aT_atan[10])))));
    s2 = w * (aT_atan[1] + w * (aT_atan[3] + w * (aT_atan[5] + w * (aT_atan[7] + w * aT_atan[9]))));
    if (id < 0)
        return x - x * (s1 + s2);
    else {
        z = atanhi_atan[id] - ((x * (s1 + s2) - atanlo_atan[id]) - x);
        return (hx < 0) ? -z : z;
    }
}

// Computes the four-quadrant inverse tangent
double __ieee754_atan2(double y, double x) {
    double z;
    int32_t k, m, hx, hy, ix, iy;
    uint32_t lx, ly;

    ieee_double_shape_type shape_x, shape_y;
    shape_x.value = x;  
    hx = shape_x.parts.msw;
    lx = shape_x.parts.lsw;

    ix = hx & 0x7fffffff;

    shape_y.value = y;
    hy = shape_y.parts.msw;
    ly = shape_y.parts.lsw;

    iy = hy & 0x7fffffff;

    if (((ix | ((lx | -lx) >> 31)) > 0x7ff00000) ||
        ((iy | ((ly | -ly) >> 31)) > 0x7ff00000))
        return x + y;

    if (((hx - 0x3ff00000) | lx) == 0)
        return atan_double(y);

    m = ((hy >> 31) & 1) | ((hx >> 30) & 2);

    if ((iy | ly) == 0) {
        switch (m) {
            case 0:
            case 1:
                return y;
            case 2:
                return pi + tiny_atan2;
            case 3:
                return -pi - tiny_atan2;
        }
    }

    if ((ix | lx) == 0)
        return (hy < 0) ? -pi_o_2 - tiny_atan2 : pi_o_2 + tiny_atan2;

    if (ix == 0x7ff00000) {
        if (iy == 0x7ff00000) {
            switch (m) {
                case 0: return pi_o_4 + tiny_atan2;
                case 1: return -pi_o_4 - tiny_atan2;
                case 2: return 3.0 * pi_o_4 + tiny_atan2;
                case 3: return -3.0 * pi_o_4 - tiny_atan2;
            }
        } else {
            switch (m) {
                case 0: return zero_atan2;
                case 1: return -zero_atan2;
                case 2: return pi + tiny_atan2;
                case 3: return -pi - tiny_atan2;
            }
        }
    }

    if (iy == 0x7ff00000)
        return (hy < 0) ? -pi_o_2 - tiny_atan2 : pi_o_2 + tiny_atan2;

    k = (iy - ix) >> 20;
    if (k > 60)
        z = pi_o_2 + 0.5 * pi_lo_atan2;
    else if (hx < 0 && k < -60)
        z = 0.0;
    else
        z = atan_double(fabs_double(y / x));
    switch (m) {
        case 0: return z;
        case 1: {
            ieee_double_shape_type zh_shape;
            zh_shape.value = z;
            zh_shape.parts.msw ^= 0x80000000;
            return zh_shape.value;
        }
        case 2: return pi - (z - pi_lo_atan2);
        default: return (z - pi_lo_atan2) - pi;
    }
}

int isinf_double(double x) {
    ieee_double_shape_type shape;
    shape.value = x;
    int32_t hx = shape.parts.msw;
    int32_t lx = shape.parts.lsw;
    hx &= 0x7fffffff;
    hx |= (uint32_t)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    return 1 - (int)((uint32_t)(hx | (-hx)) >> 31);
}

int isfinite_double(double x) {
    ieee_double_shape_type shape;
    shape.value = x;
    int32_t hx = shape.parts.msw;
    return (int)((uint32_t)((hx & 0x7fffffff) - 0x7ff00000) >> 31);
}

int __signbit_double(double x) {
    ieee_double_shape_type shape;
    shape.value = x;
    return (shape.parts.msw & 0x80000000) != 0;
}

int main() {
    double x = INFINITY; // Use standard C to denote infinity
    double y = -3.5; // Deterministic static example value

    if (isinf_double(x) && isfinite_double(y) && y < 0.0) {
        double res = __ieee754_atan2(y, x);
        if (!(res == -0.0 && __signbit_double(res) == 1)) {
            reach_error();
            return 1;
        }
    }

    printf("Passed the checks.\n");
    return 0;
}