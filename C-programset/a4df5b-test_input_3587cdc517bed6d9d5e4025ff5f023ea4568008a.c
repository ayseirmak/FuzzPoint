#include <stdio.h>
#include <stdlib.h>

typedef float v4flt __attribute__((vector_size(16)));

void foo(float *dst, float **src, int a, int n) {
  int i, j;
  int z = sizeof(v4flt) / sizeof(float);

  // Process remainder elements
  for (j = 0; j < (n % z); ++j) {
    float t = src[0][j];
    for (i = 1; i < a; ++i) {
      t += src[i][j];
    }
    dst[j] = t;
  }

  // Process vectorized elements
  unsigned m = n / z - 1;
  for (j = 0; j <= m * z; j += z * 4) {
    v4flt t0 = *(v4flt *)(src[0] + j);
    v4flt t1 = *(v4flt *)(src[0] + j + z);
    v4flt t2 = *(v4flt *)(src[0] + j + 2 * z);
    v4flt t3 = *(v4flt *)(src[0] + j + 3 * z);

    for (i = 1; i < a; ++i) {
      t0 += *(v4flt *)(src[i] + j);
      t1 += *(v4flt *)(src[i] + j + z);
      t2 += *(v4flt *)(src[i] + j + 2 * z);
      t3 += *(v4flt *)(src[i] + j + 3 * z);
    }

    *(v4flt *)(dst + j) = t0;
    *(v4flt *)(dst + j + z) = t1;
    *(v4flt *)(dst + j + 2 * z) = t2;
    *(v4flt *)(dst + j + 3 * z) = t3;
  }

  for (; j < n; ++j) {
    float t = src[0][j];
    for (i = 1; i < a; ++i) {
      t += src[i][j];
    }
    dst[j] = t;
  }
}

int main(void) {
  // Initialize buffer with fixed size for deterministic behavior
  float buffer[64];
  float *dst;
  float *src[2];
  
  dst = buffer;
  float data1[64] = {1.0f}; // Initialize with some fixed data
  float data2[64] = {2.0f}; // Initialize with some fixed data

  src[0] = data1;
  src[1] = data2;

  // Call foo with deterministic parameters
  foo(dst, src, 2, 64);

  // Print the results
  for (int i = 0; i < 64; i++) {
    printf("%f ", dst[i]);
    if ((i + 1) % 8 == 0) {
      printf("\n");
    }
  }

  return 0;
}