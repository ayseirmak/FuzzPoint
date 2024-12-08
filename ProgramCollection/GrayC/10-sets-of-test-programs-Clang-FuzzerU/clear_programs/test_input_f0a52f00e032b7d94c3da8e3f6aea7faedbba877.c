#include <stdio.h>
#include <assert.h>

// Define a vector data structure using a struct
typedef struct {
    long elements[2];
} vector_long;

// Initialize vectors with deterministic values
vector_long init_vector(long el1, long el2) {
    vector_long vec;
    vec.elements[0] = el1;
    vec.elements[1] = el2;
    return vec;
}

// Function to mimic some vector operation
vector_long operation(vector_long v1, vector_long v2) {
    vector_long result;
    result.elements[0] = v1.elements[0] + v2.elements[0];
    result.elements[1] = v1.elements[1] + v2.elements[1];
    return result;
}

void check_results(vector_long v1, vector_long v2) {
    // Check if the vector operation results are as expected
    assert(v1.elements[0] == v2.elements[0]);
    assert(v1.elements[1] == v2.elements[1]);
}

int main() {
    vector_long l0 = init_vector(1, 1); // Initialize with explicit values
    vector_long l1 = init_vector(0, 0); // Initialize as zero vector

    // Perform vector operations
    l1 = operation(l0, l0);
    check_results(l1, init_vector(2, 2));

    printf("Vector operation check passed.\n");

    return 0;
}