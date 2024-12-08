#include <stdio.h>
#include <stdlib.h>

// Custom function to check alignment
void check(char const *type, int align) {
  if ((align & -align) != align) {
    printf("Alignment issue with type: %s\n", type);
    abort();
  }
}

#define QUOTE_(s) #s
#define QUOTE(s) QUOTE_(s)

// This struct should have an alignment of the lcm of all the types. If one of
// the base alignments is not a power of two, then A cannot be power of two
struct A {
  signed long long sll;
  unsigned long long ull;
  float f;
  double d;
  long double ld;
  void *dp;
  void (*fp)();
};

int main() {
  check(QUOTE(void), __alignof__(void));
  check(QUOTE(char), __alignof__(char));
  check(QUOTE(signed short), __alignof__(signed short));
  check(QUOTE(unsigned short), __alignof__(unsigned short));
  check(QUOTE(signed int), __alignof__(signed int));
  check(QUOTE(unsigned int), __alignof__(unsigned int));
  check(QUOTE(signed long), __alignof__(signed long));
  check(QUOTE(unsigned long), __alignof__(unsigned long));
  check(QUOTE(signed long long), __alignof__(signed long long));
  check(QUOTE(unsigned long long), __alignof__(unsigned long long));
  check(QUOTE(float), __alignof__(float));
  check(QUOTE(double), __alignof__(double));
  check(QUOTE(long double), __alignof__(long double));
  check(QUOTE(void *), __alignof__(void *));
  check(QUOTE(void (*)()), __alignof__(void (*)()));
  check(QUOTE(struct A), __alignof__(struct A));

  return 0;
}