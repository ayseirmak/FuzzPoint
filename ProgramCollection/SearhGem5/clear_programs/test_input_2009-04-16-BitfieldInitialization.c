#include <stdio.h>

// Initialize the structures with fixed values
struct ty {
  int info;
  union {
    int id;
    char *str;
  } u;
} t1 = { 101, 1 };

struct ty2 {
  float info;
  char x;
  int Y;
} t2 = { 101.0f, 1, 204 };

struct ty3 {
  int A;
  char C[3]; // Adjusted to include null-terminator
} t3 = { 4, "fo" };

struct ty4 {
  long double x;
  char y;
  long double z;
} t4 = { 1.0, 4, 17.0 };

struct {
  char x;
  unsigned char y : 4;
} t5a = { 101, 15 };

struct {
  char x;
  unsigned short y : 12;
} t5b = { 101, 1231 };

struct {
  char x;
  unsigned char y : 4;
  unsigned char z : 7;
} t5 = { 101, 15, 123 };

struct {
  long double x;
  unsigned char y : 4;
} t6 = { 123.412L, 5 };

struct {
  char x;
  unsigned char y : 4;
  unsigned char q : 3;
  unsigned char z : 7;
} t7 = { 101, 15, 3, 123 }; // 3 instead of 123 for q (3-bit)

struct {
  char x;
  unsigned short y : 4;
  unsigned short q : 12;
} t7a = { 101, 15, 123 };

struct sDescrItem {
  char what;
  char *types;
  char type;
} t8 = { 16, 0, 32 };

struct resword {
  const int *a;
  unsigned b : 16;
  int c : 16;
} t9 = { 0, 123, 456 };

struct t10s {
  short a;
  int *b;
} t10;

int x = 42;

int main() {
  // No usage of `argc` or `argv`. Command-line arguments are removed.

  t10.b = &x;
  
  printf("1: %d, %d\n", t1.info, t1.u.id);
  printf("2: %.2f, %d, %d\n", t2.info, t2.x, t2.Y);
  printf("3: %d %s\n", t3.A, t3.C);
  printf("4: %.2Lf %d %.2Lf\n", t4.x, t4.y, t4.z);
  printf("5: %d %d %d\n", t5.x, t5.y, t5.z);
  printf("5a: %d %d\n", t5a.x, t5a.y);
  printf("5b: %d %d\n", t5b.x, t5b.y);
  printf("6: %.2Lf %d\n", t6.x, t6.y);
  printf("7: %d %d %d %d\n", t7.x, t7.y, t7.q, t7.z);
  printf("7a: %d %d %d\n", t7a.x, t7a.y, t7a.q);
  printf("8: %d %d\n", t8.what, t8.type);
  printf("9: %d %d\n", t9.b, t9.c); // Note: t9.a is not dereferenced as it is null.
  printf("10: %d\n", *t10.b);
  
  return 0;
}