#include <stdio.h>

// Define the structure types
typedef struct {
  int w;
  float x;
  double y;
  long long z;
} S1Ty;

typedef struct {
  S1Ty A, B;
} S2Ty;

// Function to print the S1 structure
void printS1(S1Ty *V) {
  printf("%d, %f, %f, %lld\n", V->w, V->x, V->y, V->z);
}

int main() {
  
  // Initialize the structures with fixed values
  S2Ty E;

  E.A.w = 5;
  E.A.x = 3.14f;
  E.A.y = 2.718;
  E.A.z = 10000000000LL;

  E.B.w = 10;
  E.B.x = 1.618f;
  E.B.y = 3.14159;
  E.B.z = 20000000000LL;

  // Print the initialized values
  printS1(&E.A);
  printS1(&E.B);

  return 0;
}