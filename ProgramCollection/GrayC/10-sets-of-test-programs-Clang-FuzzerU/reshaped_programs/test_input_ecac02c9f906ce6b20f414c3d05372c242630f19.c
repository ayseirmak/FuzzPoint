#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

typedef struct {
  _Complex double a;
  _Complex double b;
} Scf20;

typedef struct {
  _Complex double a;
} Scf10;

Scf10 g1s;

void check(Scf10 x, _Complex double y) {
  if (x.a != y) {
    printf("Check failed: x.a (%f + %fi) != y (%f + %fi)\n",
           creal(x.a), cimag(x.a), creal(y), cimag(y));
    exit(1);
  }
}

void init(Scf10 *p, _Complex double y) {
  p->a = y;
}

int main() {
  init(&g1s, (_Complex double)1);
  check(g1s, (_Complex double)1);

  printf("Program completed successfully.\n");

  return 0;
}