
#include <stdio.h>
#include <math.h>
#include <float.h>

// Structure to represent a signal sample in telecommunications
typedef struct {
    float signalAmplitude;
    double signalFrequency;
    long double signalPhase;
} SignalSample;

// Function to process signal sample and demonstrate precision loss
void process_signal(SignalSample sample) {
    // Calculating a representative value related to the signal
    long double baseCalculation = sample.signalAmplitude * sinl(sample.signalPhase) + sample.signalFrequency * cosl(sample.signalPhase);
    long double deepCalculation = baseCalculation * M_PI;

    // Demonstrate casting and precision loss
    float castFloat = (float)deepCalculation;
    double castDouble = (double)deepCalculation;
    long long castLongLong = (long long)deepCalculation;

    printf("Original long double calculation: %.10Le\n", deepCalculation);
    printf("Cast to float: %.10e\n", castFloat);
    printf("Cast to double: %.10e\n", castDouble);
    printf("Cast to long long: %lld\n", castLongLong);
}

// Function to demonstrate handling of special floating-point values
void handle_special_values() {
    double values[] = {0.0, -0.0, INFINITY, -INFINITY, NAN};
    const char *valueLabels[] = {"0.0", "-0.0", "INFINITY", "-INFINITY", "NAN"};

    for (int i = 0; i < 5; ++i) {
        switch (fpclassify(values[i])) {
            case FP_ZERO:
                printf("Value %s is zero\n", valueLabels[i]);
                break;
            case FP_INFINITE:
                printf("Value %s is infinite\n", valueLabels[i]);
                break;
            case FP_NAN:
                printf("Value %s is NaN\n", valueLabels[i]);
                break;
            default:
                printf("Other classified value: %s\n", valueLabels[i]);
                break;
        }
    }
}

int main() {
    // Define a signal sample structure
    SignalSample signal = {1.0F, 1000.0, M_PI / 4.0L};

    // Process signal and demonstrate floating-point operations
    process_signal(signal);

    // Demonstrate handling special floating-point values
    printf("\nHandling special floating-point values:\n");
    handle_special_values();

    return 0;
}
