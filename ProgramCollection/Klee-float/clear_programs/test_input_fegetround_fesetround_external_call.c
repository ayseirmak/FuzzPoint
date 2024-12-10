#include <fenv.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
  double rne;
  double ru;
  double rd;
  double rz;
} Result;

// Function to set the rounding mode using C standard functions
void setRoundingMode(int rm) {
  int result = fesetround(rm);
  assert(result == 0);
  int newRoundingMode = fegetround();
  assert(newRoundingMode != -1);
  assert(newRoundingMode == rm);
}

int main() {
  // Initialize input value directly
  double initialValue = 0.5;
  
  // Initialize result struct
  Result r;
  
  // Perform square root calculations under different rounding modes
  setRoundingMode(FE_TONEAREST);
  r.rne = sqrt(initialValue);
  printf("Result RNE: %.40f (hexfloat: %a)\n", r.rne, r.rne);
  
  setRoundingMode(FE_UPWARD);
  r.ru = sqrt(initialValue);
  printf("Result RU : %.40f (hexfloat: %a)\n", r.ru, r.ru);
  
  setRoundingMode(FE_DOWNWARD);
  r.rd = sqrt(initialValue);
  printf("Result RD : %.40f (hexfloat: %a)\n", r.rd, r.rd);
  
  setRoundingMode(FE_TOWARDZERO);
  r.rz = sqrt(initialValue);
  printf("Result RZ : %.40f (hexfloat: %a)\n", r.rz, r.rz);

  // Perform assertions to validate results
  assert(r.rne == r.ru);
  assert(r.rd == r.rz);
  assert(r.rne > r.rd);

  return 0; // Indication of successful execution
}