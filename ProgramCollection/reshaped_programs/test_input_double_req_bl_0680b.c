#include <stdio.h>
#include <stdint.h>
#include <math.h>

typedef uint32_t __uint32_t;
typedef int32_t __int32_t;

typedef union {
  double value;
  struct {
    __uint32_t lsw;
    __uint32_t msw;
  } parts;
} ieee_double_shape_type;

#define ZERO_ATAN2 0.0
#define TINY_ATAN2 1.0e-300
#define PI_LO_ATAN2 1.2246467991473531772E-16
#define HUGE_ATAN 1.0e300
#define ONE_ATAN 1.0
#define PI 3.1415926535897931160E+00
#define PI_O_2 1.5707963267948965580E+00
#define PI_O_4 7.8539816339744827900E-01

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

double fabs_double(double x) {
    __uint32_t high;
    ieee_double_shape_type gh_u;
    gh_u.value = x;
    high = gh_u.parts.msw;
    gh_u.parts.msw = high & 0x7fffffff;
    return gh_u.value;
}

double atan_double(double x) {
    double w, s1, s2, z;
    __int32_t ix, hx, id;
  
    ieee_double_shape_type gh_u;
    gh_u.value = x;
    hx = gh_u.parts.msw;
    ix = hx & 0x7fffffff;
  
    if (ix >= 0x44100000) {
        __uint32_t low;
        ieee_double_shape_type gl_u;
        gl_u.value = x;
        low = gl_u.parts.lsw;
        
        if (ix > 0x7ff00000 || (ix == 0x7ff00000 && (low != 0)))
            return x + x;
        
        return (hx > 0) ? atanhi_atan[3] + atanlo_atan[3] : -atanhi_atan[3] - atanlo_atan[3];
    }
  
    if (ix < 0x3fdc0000) {
        if (ix < 0x3e200000) {
            if (HUGE_ATAN + x > ONE_ATAN)
                return x;
        }
        id = -1;
    } else {
        x = fabs_double(x);
        if (ix < 0x3ff30000) {
            if (ix < 0x3fe60000) {
                id = 0;
                x = (2.0 * x - ONE_ATAN) / (2.0 + x);
            } else {
                id = 1;
                x = (x - ONE_ATAN) / (x + ONE_ATAN);
            }
        } else {
            if (ix < 0x40038000) {
                id = 2;
                x = (x - 1.5) / (ONE_ATAN + 1.5 * x);
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

double __ieee754_atan2(double y, double x) {
    double z;
    __int32_t k, m, hx, hy, ix, iy;
    __uint32_t lx, ly;

    ieee_double_shape_type ew_u;
    ew_u.value = x;
    hx = ew_u.parts.msw;
    lx = ew_u.parts.lsw;
    ix = hx & 0x7fffffff;

    ew_u.value = y;
    hy = ew_u.parts.msw;
    ly = ew_u.parts.lsw;
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
            return PI + TINY_ATAN2;
        case 3:
            return -PI - TINY_ATAN2;
        }
    }

    if ((ix | lx) == 0)
        return (hy < 0) ? -PI_O_2 - TINY_ATAN2 : PI_O_2 + TINY_ATAN2;

    if (ix == 0x7ff00000) {
        if (iy == 0x7ff00000) {
            switch (m) {
            case 0:
                return PI_O_4 + TINY_ATAN2;
            case 1:
                return -PI_O_4 - TINY_ATAN2;
            case 2:
                return 3.0 * PI_O_4 + TINY_ATAN2;
            case 3:
                return -3.0 * PI_O_4 - TINY_ATAN2;
            }
        } else {
            switch (m) {
            case 0:
                return ZERO_ATAN2;
            case 1:
                return -ZERO_ATAN2;
            case 2:
                return PI + TINY_ATAN2;
            case 3:
                return -PI - TINY_ATAN2;
            }
        }
    }

    if (iy == 0x7ff00000)
        return (hy < 0) ? -PI_O_2 - TINY_ATAN2 : PI_O_2 + TINY_ATAN2;

    k = (iy - ix) >> 20;
    if (k > 60)
        z = PI_O_2 + 0.5 * PI_LO_ATAN2;
    else if (hx < 0 && k < -60)
        z = 0.0;
    else
        z = atan_double(fabs_double(y / x));

    switch (m) {
    case 0:
        return z;
    case 1: {
        __uint32_t zh;
        ieee_double_shape_type gh_u;
        gh_u.value = z;
        zh = gh_u.parts.msw;
        gh_u.parts.msw = zh ^ 0x80000000;
        z = gh_u.value;
    }
        return z;
    case 2:
        return PI - (z - PI_LO_ATAN2);
    default:
        return (z - PI_LO_ATAN2) - PI;
    }
}

int main() {
    double x = -0.0;
    double y = 0.0;
    double res = __ieee754_atan2(y, x);

    if (res != PI) {
        printf("Error: output does not match expected result!\n");
        return 1;
    }
    printf("Test passed: output matches expected result.\n");
    return 0;
}