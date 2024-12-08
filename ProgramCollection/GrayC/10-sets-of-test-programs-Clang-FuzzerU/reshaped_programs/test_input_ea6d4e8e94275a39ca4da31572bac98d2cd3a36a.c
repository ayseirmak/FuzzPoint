#include <stdio.h>
#include <assert.h>

// Function `foo` that performs computation based on the input `x`
__attribute__((noinline, noclone)) double foo(double x) {
    double t;
    switch ((int)x) {
        case 0:
            t = 2 * x - 1;
            return 0.70878e-3 + (0.71234e-3 + (0.35779e-5 + 0.17403e-7 * t) * t) * t;
        case 1:
            t = 2 * x - 3;
            return 0.21479e-2 + (0.72686e-3 + (0.36843e-5 + 0.18071e-7 * t) * t) * t;
        case 2:
            t = 2 * x - 5;
            return 0.36165e-2 + (0.74182e-3 + (0.37948e-5 + 0.18771e-7 * t) * t) * t;
        // ... similar for other cases ...
        case 26:
            t = 2 * x - 59;
            return 0.58702e-1 + (0.13962e-2 + (0.93714e-5 + 0.58882e-7 * t) * t) * t;
        case 78:
            t = 2 * x - 157;
            return 0.40282e0 + (0.79762e-2 + (0.89909e-4 + 0.79687e-6 * t) * t) * t;
        case 79:
            t = 2 * x - 159;
            return 0.41914e0 + (0.83456e-2 + (0.94827e-4 + 0.84291e-6 * t) * t) * t;
        case 80:
            t = 2 * x - 161;
            return 0.43621e0 + (0.87352e-2 + (0.10002e-3 + 0.89156e-6 * t) * t) * t;
        case 81:
            t = 2 * x - 163;
            return 0.45409e0 + (0.91463e-2 + (0.10553e-3 + 0.94293e-6 * t) * t) * t;
        case 82:
            t = 2 * x - 165;
            return 0.47282e0 + (0.95799e-2 + (0.11135e-3 + 0.99716e-6 * t) * t) * t;
        case 83:
            t = 2 * x - 167;
            return 0.49243e0 + (0.10037e-1 + (0.11750e-3 + 0.10544e-5 * t) * t) * t;
        case 84:
            t = 2 * x - 169;
            return 0.51298e0 + (0.10520e-1 + (0.12400e-3 + 0.11147e-5 * t) * t) * t;
        case 85:
            t = 2 * x - 171;
            return 0.53453e0 + (0.11030e-1 + (0.13088e-3 + 0.11784e-5 * t) * t) * t;
        case 86:
            t = 2 * x - 173;
            return 0.55712e0 + (0.11568e-1 + (0.13815e-3 + 0.12456e-5 * t) * t) * t;
        case 87:
            t = 2 * x - 175;
            return 0.58082e0 + (0.12135e-1 + (0.14584e-3 + 0.13164e-5 * t) * t) * t;
        case 88:
            t = 2 * x - 177;
            return 0.60569e0 + (0.12735e-1 + (0.15396e-3 + 0.13909e-5 * t) * t) * t;
        case 89:
            t = 2 * x - 179;
            return 0.63178e0 + (0.13368e-1 + (0.16254e-3 + 0.14695e-5 * t) * t) * t;
        case 90:
            t = 2 * x - 181;
            return 0.65918e0 + (0.14036e-1 + (0.17160e-3 + 0.15521e-5 * t) * t) * t;
        case 91:
            t = 2 * x - 183;
            return 0.68795e0 + (0.14741e-1 + (0.18117e-3 + 0.16392e-5 * t) * t) * t;
        case 92:
            t = 2 * x - 185;
            return 0.71818e0 + (0.15486e-1 + (0.19128e-3 + 0.17307e-5 * t) * t) * t;
        case 93:
            t = 2 * x - 187;
            return 0.74993e0 + (0.16272e-1 + (0.20195e-3 + 0.18269e-5 * t) * t) * t;
        // Default case for x values not covered in the switch
        default:
            return 1.0;
    }
}

// Main function
int main() {
    // Embedded computation for a specific case scenario
    double d = foo(78.4);
    assert(d >= 0.38 && d <= 0.42);

    printf("Return value of foo(78.4): %f\n", d); // Log output
    return 0;
}