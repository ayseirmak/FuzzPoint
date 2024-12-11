#include <stdio.h>

static double getDC(), getDS(), getDI();

int main() {
    // Initialize the conversion results
    double DC = getDC();
    double DS = getDS();
    double DI = getDI();
    
    // Perform the type conversions
    unsigned char uc = (unsigned char) DC;
    unsigned short us = (unsigned short) DS;
    unsigned int ui = (unsigned int) DI;
    
    // Print the results
    printf("DC = %lf, DS = %lf, DI = %lf\n", DC, DS, DI);
    printf("uc = %u, us = %u, ui = %u\n", uc, us, ui);

    return 0;
}

static double getDC() { return (double) ((1L  <<  8) - 16L ); }
static double getDS() { return (double) ((1LL << 16) - 16L ); }
static double getDI() { return (double) ((1LL << 32) - 16LL); }