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
   charfunc((((125))));
   charfunc((((2.10))));

   intfunc('a');
   intfunc((-((-100))));
   intfunc((((8.9))));

   floatfunc('a');
   floatfunc(((0xA7541)));
   floatfunc((((10.6))));

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   char b = (((0xD7232)));
   char c = (((5.7)));

   printf("%d %d\n", b, c);

   int d = (-(-10));
   int e = (((6.10)));

   printf("%d %d\n", d, e);

   float f = 'a';
   float g = ((-(0xAE906)));

   printf("%f %f\n", f, g);

   return (((0)));
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
