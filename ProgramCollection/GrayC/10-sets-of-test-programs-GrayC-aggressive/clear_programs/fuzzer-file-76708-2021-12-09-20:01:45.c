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
   charfunc((106));
   charfunc((6.10));

   intfunc('a');
   intfunc((28));
   intfunc((4.5));

   floatfunc('a');
   floatfunc((-99));
   floatfunc((5.1));

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   char b = (0x8470);
   char c = (10.2);

   printf("%d %d\n", b, c);

   int d = 'a';
   int e = (5.10);

   printf("%d %d\n", d, e);

   float f = 'a';
   float g = (225);

   printf("%f %f\n", f, g);

   return (0);
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
