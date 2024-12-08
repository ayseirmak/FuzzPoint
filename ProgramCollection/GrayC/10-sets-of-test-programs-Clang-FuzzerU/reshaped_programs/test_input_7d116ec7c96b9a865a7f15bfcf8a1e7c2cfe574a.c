#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef char A28[28];
typedef A28 A3_28[3];
typedef A3_28 A2_3_28[2];

static const A2_3_28 a = {
  { "1\00012", "123\0001234", "12345\000123456" },
  { "1234567\00012345678", "123456789\0001234567890", "12345678901\000123456789012" }
};

#define A(expr, N) \
  ((strlen(expr) == N) ? (void)0 : (printf("line %i: strlen(%s) = \"%s\") != %i\n", __LINE__, #expr, expr, N), abort()))

void test_array_ptr(void) {
  A(*(&a[0][0] + 0), 1);
  A(*(&a[0][0] + 1), 3);
  A(*(&a[0][0] + 2), 5);

  A(*(&a[1][0] + 0), 7);
  A(*(&a[1][0] + 1), 9);
  A(*(&a[1][0] + 2), 11);

  A(*(&a[1][1] - 1), 7);
  A(*(&a[1][1] + 0), 9);
  A(*(&a[1][1] + 1), 11);

  A(*(&a[0][0] + 0) + 2, 2);
  A(*(&a[0][0] + 1) + 4, 4);
  A(*(&a[0][0] + 2) + 6, 6);

  A(*(&a[0][0] + 0) + 5, 0);
  A(*(&a[0][0] + 1) + 10, 0);
  A(*(&a[0][0] + 2) + 14, 0);
}

void test_ptr_array(void) {
  static const A3_28* const pa[] = { &a[0], &a[1] };

  A(*((*pa[0]) + 0), 1);
  A(*((*pa[0]) + 1), 3);
  A(*((*pa[0]) + 2), 5);

  A(*((*pa[1]) + 0), 7);
  A(*((*pa[1]) + 1), 9);
  A(*((*pa[1]) + 2), 11);
}

int main(void) {
  test_array_ptr();
  test_ptr_array();
  return 0;
}