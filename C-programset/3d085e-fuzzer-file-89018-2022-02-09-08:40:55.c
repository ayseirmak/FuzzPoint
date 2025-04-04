/* corpus/00175.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
#include <stdio.h>

void charfunc(char a)
{
   printf("char: %c\n", a);
}

void intfunc(int a)
{
   printf("int: %d\n", a);
}

void floatfunc(float a)
{
   printf("float: %f\n", a);
}

int main()
{
   charfunc('a');
   charfunc(((-(103))));
   charfunc((((9.4))));

   intfunc('a');
   intfunc((-((35))));
   intfunc((((8.8))));

   floatfunc('a');
   floatfunc(((-(65))));
   floatfunc((((6.10))));

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   char b = ((0xF4C1));
   char c = (((6.5)));

   printf("%d %d\n", b, c);

   int d = (-9);
   int e = (-9);

   printf("%d %d\n", d, e);

   float f = 'a';
   float g = ((0x8C34E));

   printf("%f %f\n", f, g);

   return (((524288)));
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
