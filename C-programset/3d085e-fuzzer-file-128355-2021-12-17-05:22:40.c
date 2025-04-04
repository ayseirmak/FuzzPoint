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
   charfunc((-99));
   charfunc((5.2));

   intfunc('a');
   intfunc((34));
   intfunc((2.10));

   floatfunc('a');
   floatfunc((0xD0));
   floatfunc((5.5));

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   char b = (-98);
   char c = (8.4);

   printf("%d %d\n", b, c);

   int d = (-9);
   int e = (8);

   printf("%d %d\n", d, e);

   float f = 'a';
   float g = (0x8C);

   printf("%f %f\n", f, g);

   return (0);
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
