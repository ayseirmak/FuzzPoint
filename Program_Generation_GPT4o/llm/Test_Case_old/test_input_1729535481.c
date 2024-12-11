
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <fenv.h>

// Structure to represent cryptographic computation settings
typedef struct {
    float keyStrength;     // Strength of the cryptographic key
    double entropy;        // Entropy level
    long double computationTime; // Approximate time for computation
} CryptoSettings;

// Function to demonstrate different floating-point precision
void precision_comparison(CryptoSettings* settings) {
    // Simulate cryptographic precision requirements
    float entropy_float = settings->entropy;
    double entropy_double = settings->entropy;
    long long entropy_ll = (long long)settings->entropy;

    printf("Entropy (Float): %.8e\n", entropy_float);
    printf("Entropy (Double): %.10e\n", entropy_double);
    printf("Entropy as long long: %lld\n", entropy_ll);
}

// Function to demonstrate different rounding modes
void test_rounding_modes(double value) {
    const char *rounding_modes[] = {"FE_TONEAREST", "FE_TOWARDZERO", "FE_UPWARD", "FE_DOWNWARD"};
    int modes[] = {FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD};

    printf("Original Value: %f\n", value);

    for (int i = 0; i < 4; ++i) {
        fesetround(modes[i]);
        double rounded = nearbyint(value);
        printf("Rounded using %s: %f\n", rounding_modes[i], rounded);
    }
}

// Function to handle special floating-point values like NaN
void handle_special_values(long double value) {
    if (isnan(value)) {
        printf("Value is NaN.\n");
    } else if (isinf(value)) {
        printf("Value is infinite.\n");
    } else {
        printf("Value is normal.\n");
    }
}

int main() {
    // Initialize cryptographic settings with arbitrary values
    CryptoSettings settings = {256.0F, 128.5, NAN}; // Intentionally using NaN for computationTime

    printf("Initial Crypto Settings: Key Strength: %.2f, Entropy: %.2f, Computation Time: %.2Lf\n",
           settings.keyStrength, settings.entropy, settings.computationTime);

    // Compare precision across different types
    precision_comparison(&settings);

    // Demonstrate rounding modes on a sample entropy
    printf("\nTesting Rounding Modes on entropy...\n");
    test_rounding_modes(settings.entropy);

    // Handle and check special values (NaN)
    printf("\nHandling Special Values (NaN check)...\n");
    handle_special_values(settings.computationTime);

    // Demonstrate NaN comparison behavior
    printf("\nDemonstrating NaN comparisons...\n");
    if (settings.computationTime != settings.computationTime) {
        printf("NaN is not equal to itself.\n");
    } else {
        printf("Unexpected behavior! NaN comparison failed to detect.\n");
    }

    return 0;
}
