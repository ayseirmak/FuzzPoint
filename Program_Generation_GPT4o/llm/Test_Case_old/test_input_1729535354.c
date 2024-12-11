
#include <stdio.h>
#include <math.h>
#include <fenv.h>
#include <float.h>

typedef struct {
    float proportional_gain;
    double integral_gain;
    long double derivative_gain;
    long double set_point;
    long double control_output;
} ControlSystem;

void set_rounding_mode(int mode) {
    switch (mode) {
        case FE_TONEAREST:
            fesetround(FE_TONEAREST);
            break;
        case FE_DOWNWARD:
            fesetround(FE_DOWNWARD);
            break;
        case FE_UPWARD:
            fesetround(FE_UPWARD);
            break;
        case FE_TOWARDZERO:
            fesetround(FE_TOWARDZERO);
            break;
        default:
            printf("Invalid rounding mode\n");
            break;
    }
}

long double calculate_control_output(ControlSystem *system, long double input_value) {
    long double error = system->set_point - input_value;

    // Example of operations with different scales
    long double proportional_term = system->proportional_gain * error;
    long double integral_term = system->integral_gain * M_PI * error;
    long double derivative_term = system->derivative_gain * M_E * error;

    long double output = proportional_term + integral_term + derivative_term;

    // Handle special values using switch
    switch (fpclassify(output)) {
        case FP_NAN:
            printf("Output is NaN\n");
            return 0.0L;
        case FP_INFINITE:
            printf("Output is %s infinity\n", (output > 0) ? "positive" : "negative");
            return (output > 0) ? LDBL_MAX : -LDBL_MAX;
        default:
            return output;
    }
}

void control_algorithm_demo() {
    // Initialize the control system with some arbitrary gains
    ControlSystem system = {0.2F, 0.01, 0.001L, 1000.0L, 0.0L};

    // Initialize input value
    long double input_value = 0.0L;
    set_rounding_mode(FE_TONEAREST);
    system.control_output = calculate_control_output(&system, input_value);
    printf("Control Output (round to nearest): %.10Lf\n", system.control_output);

    // Test with different rounding modes
    set_rounding_mode(FE_DOWNWARD);
    system.control_output = calculate_control_output(&system, input_value);
    printf("Control Output (round downward): %.10Lf\n", system.control_output);

    set_rounding_mode(FE_UPWARD);
    system.control_output = calculate_control_output(&system, input_value);
    printf("Control Output (round upward): %.10Lf\n", system.control_output);

    set_rounding_mode(FE_TOWARDZERO);
    system.control_output = calculate_control_output(&system, input_value);
    printf("Control Output (round toward zero): %.10Lf\n", system.control_output);
}

int main() {
    control_algorithm_demo();

    // Precision comparison loop
    float f_value = FLT_MIN;
    double d_value = DBL_MIN;
    long double ld_value = LDBL_MIN;

    printf("\nPrecision Effects:\n");
    for (int i = 0; i < 5; ++i) {
        f_value *= 10.0F;
        d_value *= 10.0;
        ld_value *= 10.0L;
        printf("Iteration %d, float: %.8e, double: %.8e, long double: %.8Le\n", i, f_value, d_value, ld_value);
    }

    return 0;
}
