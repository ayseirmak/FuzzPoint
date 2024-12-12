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
   charfunc((-(19)));
   charfunc(((3.1)));

   intfunc('a');
   intfunc(((96)));
   intfunc(((8.7)));

   floatfunc('a');
   floatfunc(((50)));
   floatfunc(((2.7)));

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   char b = (-(-99));
   char c = ((3.10));

   printf("%d %d\n", b, c);

   int d = (0x3);
   int e = ((6.5));

   printf("%d %d\n", d, e);

   float f = 'a';
   float g = (0x15);

   printf("%f %f\n", f, g);

   return ((0));
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
