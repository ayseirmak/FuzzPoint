#include <stdio.h>

// Define a normal union without any special attributes
typedef union {
  float *__fptr;
  int *__iptr;
} UNION;

// The 'try' function will return 1 to simulate a check
int try(UNION U) {
  return 1;
}

// The 'test' function uses fixed int and float initializers
int test() {
  int intVal = 42;         // Example integer value
  float floatVal = 3.14f;  // Example float value

  return try((UNION){.__iptr = &intVal}) | try((UNION){.__fptr = &floatVal});
}

int main() {
  // Directly calling 'test' without using any arguments or input
  if (test()) {
    printf("ok\n");
  }
  return 0;
}