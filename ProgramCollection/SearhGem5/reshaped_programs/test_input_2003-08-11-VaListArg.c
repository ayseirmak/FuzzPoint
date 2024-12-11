#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* 5 bytes. */
typedef struct DWordS_struct {
  int i;
  char c;
} DWordS;

/* 12 bytes if d is 4-byte aligned; 16 bytes if d is 8-byte aligned. */
typedef struct QuadWordS_struct {
  int i;
  double d;
} QuadWordS;

/* 20 bytes if d is 4-byte aligned; 28 bytes if d is 8-byte aligned
 * (assuming pointer size is 4 bytes and 8 bytes respectively). */
typedef struct LargeS_struct {
  int i;
  double d;
  DWordS *ptr;
  int j;
} LargeS;

void test(char *fmt) {
  DWordS dw;
  QuadWordS qw;
  LargeS ls;
  
  dw.i = 42;
  dw.c = 'b';
  
  qw.i = 84;
  qw.d = 42.42;
  
  ls.i = 168;
  ls.d = 84.84;
  ls.ptr = &dw;
  ls.j = 336;

  while (*fmt) {
    switch (*fmt++) {
      case 's': /* string */
        printf("string %s\n", "hello");
        break;
      case 'i': /* int */
        printf("int %d\n", 123);
        break;
      case 'd': /* double */
        printf("double %f\n", 3.14159);
        break;
      case 'l': /* long long */
        printf("long long %lld\n", 9876543210LL);
        break;
      case 'c': /* char */
        printf("char %c\n", 'z');
        break;
      case 'D':
        printf("DWord { %d, %c }\n", dw.i, dw.c);
        break;
      case 'Q':
        printf("QuadWord { %d, %f }\n", qw.i, qw.d);
        break;
      case 'L':
        printf("LargeS { %d, %f, 0x%x, %d }\n", ls.i, ls.d, ls.ptr != NULL, ls.j);
        break;
    }
  }
}

void testVaListArg(char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  test(fmt);
  va_end(ap);
}

void testVaCopyArg(char *fmt, ...) {
  va_list ap, aq;
  va_start(ap, fmt);
  va_copy(aq, ap); /* test va_copy */
  test(fmt);
  va_end(aq);
  va_end(ap);
}

int main() {
  DWordS dw = {18, 'a'};
  QuadWordS qw = {19, 20.0};
  LargeS ls = {21, 22.0, &dw, 23};

  testVaListArg("ssiciiiiis");
  testVaCopyArg("ssiciiiiis");

  testVaListArg("ddil");
  testVaCopyArg("ddil");

  char dwi[12], dwc[12];
  sprintf(dwi, "%d", dw.i);
  sprintf(dwc, "%c", dw.c);
  char qwi[12], qwd[12];
  sprintf(qwi, "%d", qw.i);
  sprintf(qwd, "%f", qw.d);
  char lsi[12], lsd[12], lsptr[12], lsj[12];
  sprintf(lsi, "%d", ls.i);
  sprintf(lsd, "%f", ls.d);
  sprintf(lsptr, "%lld", (long long)ls.ptr);
  sprintf(lsj, "%d", ls.j);

  testVaListArg("DQL", dwi, dwc, qwi, qwd, lsi, lsd, lsptr, lsj);
  testVaCopyArg("DQL", dwi, dwc, qwi, qwd, lsi, lsd, lsptr, lsj);

  return 0;
}