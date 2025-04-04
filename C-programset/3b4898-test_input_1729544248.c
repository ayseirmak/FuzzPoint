
#include <stdio.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265358979323846
#define KEY 3.1415 // Simulate a 'key' with a floating-point number

typedef struct {
    double real;
    double imag;
} Complex;

// Function to encode a message using trigonometric-based transformation
void encode_message(const char *input, Complex *output, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        double angle = (double)input[i] * KEY;
        output[i].real = cos(angle);
        output[i].imag = sin(angle);
    }
}

// Function to decode an encoded message (EDUCATIONAL purposes only)
void decode_message(const Complex *input, char *output, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        // Attempt to reconstruct the original character (in real cryptography this would be insecure)
        double angle = atan2(input[i].imag, input[i].real);
        output[i] = (char)(angle / KEY);
    }
    output[length] = '\0';
}

int main() {
    const char *message = "Secret";
    size_t length = strlen(message);
    Complex encoded[length];
    char decoded[length + 1];

    // Encode the message
    encode_message(message, encoded, length);

    // Decode the message
    decode_message(encoded, decoded, length);

    // Output the encoded and decoded results
    printf("Encoded message (complex numbers):\n");
    for (size_t i = 0; i < length; ++i) {
        printf("(%.3f, %.3f) ", encoded[i].real, encoded[i].imag);
    }
    printf("\nDecoded message: %s\n", decoded);

    return 0;
}
