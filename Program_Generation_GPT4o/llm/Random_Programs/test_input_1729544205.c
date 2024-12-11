
#include <stdio.h>
#include <math.h>
#include <string.h>

// Function to perform a simple obfuscation using floating-point arithmetic
void floating_point_obfuscation(const char *input, double *obfuscated) {
    size_t length = strlen(input);
    double key = M_PI;
    
    for (size_t i = 0; i < length; ++i) {
        // Transform each character using a floating-point based formula
        obfuscated[i] = sin(input[i] * key) + cos(input[i] / key);
    }
}

// Function to perform inverse obfuscation (simplified for demonstration)
void inverse_floating_point_obfuscation(const double *obfuscated, char *output, size_t length) {
    double key = M_PI;
    
    for (size_t i = 0; i < length; ++i) {
        // Estimate the original character using inverse operations (not perfect)
        output[i] = (char)(round(asin(obfuscated[i] - 1) / key));
    }
    output[length] = '\0';
}

int main() {
    const char *message = "Hello";
    size_t length = strlen(message);
    double obfuscated[length];
    char deobfuscated[length + 1];

    // Obfuscate the message
    floating_point_obfuscation(message, obfuscated);

    printf("Obfuscated message:\n");
    for (size_t i = 0; i < length; ++i) {
        printf("%.5lf ", obfuscated[i]);
    }
    printf("\n");

    // Attempt to de-obfuscate the message
    inverse_floating_point_obfuscation(obfuscated, deobfuscated, length);

    printf("Deobfuscated message: %s\n", deobfuscated);

    return 0;
}
