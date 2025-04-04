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
   charfunc(((98)));
   charfunc(((8.2)));

   intfunc('a');
   intfunc((-(99)));
   intfunc(((6.2)));

   floatfunc('a');
   floatfunc(((0x951)));
   floatfunc(((10.10)));

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   char b = (0x5F);
   char c = ((9.4));

   printf("%d %d\n", b, c);

   int d = (-(0x9));
   int e = 8;

   printf("%d %d\n", d, e);

   float f = 'a';
   float g = ((97));

   printf("%f %f\n", f, g);

   return ((1073741824));
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
