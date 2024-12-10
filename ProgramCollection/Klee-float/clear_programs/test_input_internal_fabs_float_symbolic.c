#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>

int main() {
  float x = -0.0f;  // Choose a specific value to test, can be changed to other values like 0.0f or INFINITY
  float result = fabsf(x); // Use standard fabsf to get the absolute value

  if (isnan(x)) {
    if (signbit(x)) {
      printf("-ve nan\n");
    } else {
      printf("+ve nan\n");
    }
    assert(!signbit(result));
    assert(isnan(result));
    return 0;
  }

  if (isinf(x)) {
    if (signbit(x)) {
      printf("-ve inf\n");
    } else {
      printf("+ve inf\n");
    }
    assert(!signbit(result));
    assert(isinf(result) == 1);
    return 0;
  }

  if (x == 0.0f) {
    if (signbit(x)) {
      printf("-ve 0.0\n");
    } else {
      printf("+ve 0.0\n");
    }
    assert(!signbit(result));
    assert(result == 0.0f);
    return 0;
  }

  printf("result > 0.0\n");
  assert(result > 0.0f);

  return 0;
}