#include <stdio.h>
#include <stddef.h>

// Define vector types for ARM compatibility
typedef unsigned int UV __attribute__((vector_size (16)));
typedef int SV __attribute__((vector_size (16)));

// Custom abort function for simulation
void my_abort() {
    printf("Abort called\n");
    exit(1);
}

// Declare functions from macros
#define TEST(a, b, c, d) \
__attribute__((noinline)) void uq##a##b##c##d(UV *x, UV *y) \
{ *x = *y / ((UV){ a, b, c, d }); } \
__attribute__((noinline)) void ur##a##b##c##d(UV *x, UV *y) \
{ *x = *y % ((UV){ a, b, c, d }); } \
__attribute__((noinline)) void sq##a##b##c##d(SV *x, SV *y) \
{ *x = *y / ((SV){ a, b, c, d }); } \
__attribute__((noinline)) void sr##a##b##c##d(SV *x, SV *y) \
{ *x = *y % ((SV){ a, b, c, d }); }

// Define test cases based on macro definitions
#define TESTS \
TEST(4, 4, 4, 4) \
TEST(1, 4, 2, 8) \
TEST(3, 3, 3, 3) \
TEST(6, 5, 6, 5) \
TEST(14, 14, 14, 6) \
TEST(7, 7, 7, 7)

TESTS

// Initialize UV and SV arrays with fixed values
UV u[] = {
    ((UV){ 73U, 65531U, 0U, 174U }),
    ((UV){ 1U, 8173U, ~0U, ~0U - 63 })
};

SV s[] = {
    ((SV){ 73, -9123, 32761, 8191 }),
    ((SV){ 9903, -1, -7323, 0 })
};

int main() {
    UV ur;
    SV sr;
 
    // Loop over the vector arrays and use the defined TESTS
    for (size_t i = 0; i < sizeof(u) / sizeof(u[0]); i++) {
        // Here we are calling the generated functions based on TESTS
        ur4444(&ur, &u[i]);
        if (ur[0] != u[i][0] / 4 || ur[3] != u[i][3] / 4) my_abort();
        ur1428(&ur, &u[i]);
        if (ur[0] != u[i][0] / 1 || ur[3] != u[i][3] / 8) my_abort();
        ur3333(&ur, &u[i]);
        if (ur[0] != u[i][0] / 3 || ur[3] != u[i][3] / 3) my_abort();        
        ur6565(&ur, &u[i]);
        if (ur[0] != u[i][0] / 6 || ur[3] != u[i][3] / 5) my_abort();        
        ur14146(&ur, &u[i]);
        if (ur[0] != u[i][0] / 14 || ur[3] != u[i][3] / 6) my_abort();        
        ur7777(&ur, &u[i]);
        if (ur[0] != u[i][0] / 7 || ur[3] != u[i][3] / 7) my_abort();
        
        sr4444(&sr, &s[i]);
        if (sr[0] != s[i][0] / 4 || sr[3] != s[i][3] / 4) my_abort();
        sr1428(&sr, &s[i]);
        if (sr[0] != s[i][0] / 1 || sr[3] != s[i][3] / 8) my_abort();
        sr3333(&sr, &s[i]);
        if (sr[0] != s[i][0] / 3 || sr[3] != s[i][3] / 3) my_abort();        
        sr6565(&sr, &s[i]);
        if (sr[0] != s[i][0] / 6 || sr[3] != s[i][3] / 5) my_abort();        
        sr14146(&sr, &s[i]);
        if (sr[0] != s[i][0] / 14 || sr[3] != s[i][3] / 6) my_abort();        
        sr7777(&sr, &s[i]);
        if (sr[0] != s[i][0] / 7 || sr[3] != s[i][3] / 7) my_abort();
    }
    
    printf("All tests passed!\n");
    return 0;
}