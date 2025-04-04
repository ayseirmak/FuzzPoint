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
   charfunc((0x5FC13));
   charfunc(((5.5)));

   intfunc('a');
   intfunc(((0xED4A51)));
   intfunc(((5.2)));

   floatfunc('a');
   floatfunc(((0xCDC58C)));
   floatfunc(((1.1)));

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   char b = ((-97));
   char c = ((5.6));

   printf("%d %d\n", b, c);

   int d = (0xE);
   int e = ((2.4));

   printf("%d %d\n", d, e);

   float f = 'a';
   float g = ((0x2F9F1));

   printf("%f %f\n", f, g);

   return ((0));
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
