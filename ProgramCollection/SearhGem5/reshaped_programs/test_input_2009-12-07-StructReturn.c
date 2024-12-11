#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Define the struct types
typedef struct {
  float ary[3];
} foostruct;

typedef struct {
  foostruct foo;
  float safe;
} barstruct;

// Initialize the array of barstruct
barstruct bar_ary[4] = {};

// Function that updates the safe field of bar_ary and returns its address
float *spooky(int i) {
  bar_ary[i].safe = 142.0;
  return &bar_ary[i].safe;
}

// Function that returns a foostruct from a static barstruct
foostruct foobify(void) {
  static barstruct my_static_foo = { {42.0, 42.0, 42.0}, /*safe=*/42.0 };
  return my_static_foo.foo;
}

int main(void) {
  // Declare a pointer to float and initialize with spooky function
  float *pf = spooky(0);

  // Assign the foo member of bar_ary[0] with the result of foobify
  bar_ary[0].foo = foobify();

  // Check the value pointed to by pf and print an error message if it is not as expected
  if (*pf != 142.0) {
    printf("error: store clobbered memory outside destination\n");
    return 1; // Return 1 to indicate failure due to unexpected state
  }

  return 0; // Return 0 to indicate successful execution
}