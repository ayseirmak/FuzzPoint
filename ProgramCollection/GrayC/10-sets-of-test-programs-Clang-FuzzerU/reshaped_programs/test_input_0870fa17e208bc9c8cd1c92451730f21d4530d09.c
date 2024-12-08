#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

volatile _Complex float f1 = 1.1f + 2.2if;
volatile _Complex float f2 = 3.3fi;
volatile _Complex double d2 = 3.3 + 4.4i;
volatile _Complex double d3 = 5.5 + 6.6i;
volatile _Complex double d4 = 7.7 + 8.8i;
volatile _Complex double d5 = 9.9 + 10.1i;
volatile _Complex long double ld1 = 1.1L + 2.2iL;
volatile _Complex long double ld2 = 3.3L + 4.4iL;

unsigned nfails = 0;

#define A(expr, N) \
  do { \
    const char *s = (expr); \
    unsigned n = 0; \
    while (s[n] != '\0' && n < N) n++; \
    if (n != N) { \
      printf("line %i: strlen(%s = \"%s\") == %u failed\n", \
              __LINE__, #expr, s, N); \
      nfails++; \
    } \
  } while (0)

const char ca[][4] = {
  {'1', '2', '3', '4'}, {'5', '\0'},
  {'1', '2', '3', '4'}, {'5', '6'},
  {'1', '2', '3', '4'}, {'5', '6', '7'},
  {'1', '2', '3', '4'}, {'5', '6', '7', '8'},
  {'9', '\0'}
};

static void test_const_global_arrays(void) {
  int idx = 0;
  A(ca[0], 5);
  A(&ca[0][0], 5);
  A(&ca[0][1], 4);
  A(&ca[0][3], 2);

  int i = 0;
  A(ca[i], 5);
  A(&ca[i][0], 5);
  A(&ca[i][1], 4);
  A(&ca[i][3], 2);

  int j = i;
  A(&ca[i][i], 5);
  A(&ca[i][j + 1], 4);
  A(&ca[i][j + 2], 3);

  A(&ca[idx][i], 5);
  A(&ca[idx][j + 1], 4);
  A(&ca[idx][j + 2], 3);

  A(&ca[idx][idx], 5);
  A(&ca[idx][idx + 1], 4);
  A(&ca[idx][idx + 2], 3);

  A(&ca[0][++j], 4);
  A(&ca[0][++j], 3);
  A(&ca[0][++j], 2);

  if (j != 3) {
    nfails++;
  }
}

static void test_const_local_arrays(void) {
  const char a[][4] = {
    {'1', '2', '3', '4'}, {'5', '\0'},
    {'1', '2', '3', '4'}, {'5', '6'},
    {'1', '2', '3', '4'}, {'5', '6', '7'},
    {'1', '2', '3', '4'}, {'5', '6', '7', '8'},
    {'9', '\0'}
  };

  int idx = 0;
  A(a[0], 5);
  A(&a[0][0], 5);
  A(&a[0][1], 4);
  A(&a[0][3], 2);

  int i = 0;
  A(a[i], 5);
  A(&a[i][0], 5);
  A(&a[i][1], 4);
  A(&a[i][3], 2);

  int j = i;
  A(&a[i][i], 5);
  A(&a[i][j + 1], 4);
  A(&a[i][j + 2], 3);

  A(&a[idx][i], 5);
  A(&a[idx][j + 1], 4);
  A(&a[idx][j + 2], 3);

  A(&a[idx][idx], 5);
  A(&a[idx][idx + 1], 4);
  A(&a[idx][idx + 2], 3);

  A(&a[0][++j], 4);
  A(&a[0][++j], 3);
  A(&a[0][++j], 2);

  if (j != 3) {
    nfails++;
  }
}

int main(void) {
  test_const_global_arrays();
  test_const_local_arrays();

  if (nfails) {
    printf("%u tests failed.\n", nfails);
  } else {
    printf("All tests passed.\n");
  }
  
  return 0;
}