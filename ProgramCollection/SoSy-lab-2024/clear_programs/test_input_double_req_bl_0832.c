#include <stdio.h>

// Define the reach_error function using standard printf
void reach_error() {
    printf("Error: reach_error was triggered.\n");
}

// Function to simulate a deterministic input, replacing __VERIFIER_nondet_double()
double deterministic_double() {
    return 0.0;  // Use 0.0 to match the requirement in the assert condition
}

typedef int __int32_t;
typedef unsigned int __uint32_t;

/* A union which permits us to convert between a double and two 32 bit
   ints.  */
typedef union {
  double value;
  struct {
    __uint32_t lsw;
    __uint32_t msw;
  } parts;
} ieee_double_shape_type;

static const double one_exp = 1.0,
                    halF_exp[2] =
                        {
                            0.5,
                            -0.5,
},
                    huge_exp = 1.0e+300,
                    twom1000_exp = 9.33263618503218878990e-302,
                    o_threshold_exp = 7.09782712893383973096e+02,
                    u_threshold_exp = -7.45133219101941108420e+02,
                    ln2HI_exp[2] =
                        {
                            6.93147180369123816490e-01,
                            -6.93147180369123816490e-01,
},
                    ln2LO_exp[2] =
                        {
                            1.90821492927058770002e-10,
                            -1.90821492927058770002e-10,
},
                    invln2_exp = 1.44269504088896338700e+00,
                    P1_exp = 1.66666666666666019037e-01,
                    P2_exp = -2.77777777770155933842e-03,
                    P3_exp = 6.61375632143793436117e-05,
                    P4_exp = -1.65339022054652515390e-06,
                    P5_exp = 4.13813679705723846039e-08;

double __ieee754_exp(double x) {
    double y, hi, lo, c, t;
    __int32_t k = 0, xsb;
    __uint32_t hx;

    ieee_double_shape_type gh_u;
    gh_u.value = x;
    hx = gh_u.parts.msw;
    
    xsb = (hx >> 31) & 1;
    hx &= 0x7fffffff;

    if (hx >= 0x40862E42) {
        if (hx >= 0x7ff00000) {
            __uint32_t lx;
            ieee_double_shape_type gl_u;
            gl_u.value = x;
            lx = gl_u.parts.lsw;
            
            if (((hx & 0xfffff) | lx) != 0)
                return x + x;
            else
                return (xsb == 0) ? x : 0.0;
        }
        if (x > o_threshold_exp)
            return huge_exp * huge_exp;
        if (x < u_threshold_exp)
            return twom1000_exp * twom1000_exp;
    }

    if (hx > 0x3fd62e42) {
        if (hx < 0x3FF0A2B2) {
            hi = x - ln2HI_exp[xsb];
            lo = ln2LO_exp[xsb];
            k = 1 - xsb - xsb;
        } else {
            k = invln2_exp * x + halF_exp[xsb];
            t = k;
            hi = x - t * ln2HI_exp[0];
            lo = t * ln2LO_exp[0];
        }
        x = hi - lo;
    } else if (hx < 0x3e300000) {
        if (huge_exp + x > one_exp)
            return one_exp + x;
    }

    t = x * x;
    c = x - t * (P1_exp + t * (P2_exp + t * (P3_exp + t * (P4_exp + t * P5_exp))));
    if (k == 0)
        return one_exp - ((x * c) / (c - 2.0) - x);
    else
        y = one_exp - ((lo - (x * c) / (2.0 - c)) - hi);

    if (k >= -1021) {
        __uint32_t hy;
        ieee_double_shape_type gh_u;
        gh_u.value = y;
        hy = gh_u.parts.msw;
        
        ieee_double_shape_type sh_u;
        sh_u.value = y;
        sh_u.parts.msw = hy + (k << 20);
        y = sh_u.value;
        return y;
    } else {
        __uint32_t hy;
        ieee_double_shape_type gh_u;
        gh_u.value = y;
        hy = gh_u.parts.msw;
        
        ieee_double_shape_type sh_u;
        sh_u.value = y;
        sh_u.parts.msw = hy + ((k + 1000) << 20);
        y = sh_u.value;
        return y * twom1000_exp;
    }
}

int main() {
    double x = deterministic_double();

    if (x == 0.0 || x == -0.0) {
        double res = __ieee754_exp(x);

        if (res != 1.0) {
            reach_error();
            return 1;
        }
    }

    return 0;
}