#include <stdio.h>
#include <stdint.h>

// Define structs with character arrays initialized with fixed string values
struct s9 { char x[9]; } s9 = { "ABCDEFGHI" };

// Define a struct with floating-point members
struct hfa24 { double a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

// Function to print a long long value in hex format
void pll(unsigned long long x) {
    printf("%llx\n", x);
}

void movi(void) {
    printf("MOVI:\n");
    pll(0xabcdef0123456789);
}

// Utility arithmetic functions
static uint32_t addip0(uint32_t x) { return x; }
static uint32_t subim503808(uint32_t x) { return x + 503808; }
static uint64_t addp12345(uint64_t x) { return x + 12345; }
static uint64_t negl(uint64_t x) { return 0 - x; }

// Function to perform various operations
void opi(void) {
    uint32_t x = 1000;
    pll(addip0(x));
    pll(subim503808(x));
    pll(addp12345(x));    
    pll(negl(x));
}

// Function for placeholder calling conventions
void pcs(void) {
    movi();
    opi();
}

// Main execution function
int main() {
    pcs();
    return 0;
}