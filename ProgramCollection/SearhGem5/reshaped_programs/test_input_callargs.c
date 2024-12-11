#include <stdio.h>

typedef struct SmallStruct_struct {
  char c1, c2, c3, c4;
  int  n;
} SmallStruct;

typedef struct BigStruct_struct {
  char       c1, c2, c3, c4;
  double     d1, d2;
  int        n;
  struct BigStruct_struct* next;
} BigStruct;

void printArgsNoRet(int a1,  float a2,  char a3,  double a4,  char* a5,
                    int a6,  float a7,  char a8,  double a9,  char* a10,
                    int a11, float a12, char a13, double a14, char* a15) {
  printf("\nprintArgsNoRet with 15 arguments:\n");
  printf("\tArgs 1-5  : %d %f %c %f %c\n", a1,  a2,  a3,  a4,  *a5);
  printf("\tArgs 6-10 : %d %f %c %f %c\n", a6,  a7,  a8,  a9,  *a10);
  printf("\tArgs 11-14: %d %f %c %f %c\n", a11, a12, a13, a14, *a15);
  printf("\n");
}

int main() {
  // Initialized with typical values
  int a1 = 42;
  float a2 = 3.14f;
  char a3 = 'X';
  double a4 = 1.618;
  char str5[] = "A";
  char *a5 = str5;

  int a6 = 17;
  float a7 = 2.71f;
  char a8 = 'Y';
  double a9 = 1.732;
  char str10[] = "B";
  char *a10 = str10;

  int a11 = 23;
  float a12 = 0.577f;
  char a13 = 'Z';
  double a14 = 3.14159;
  char str15[] = "C";
  char *a15 = str15;

  printArgsNoRet(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15);

  return 0;
}