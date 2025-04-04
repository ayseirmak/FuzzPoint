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
   charfunc(((-(-100))));
   charfunc((((1.9))));

   intfunc('a');
   intfunc((-((0x8A379))));
   intfunc((((9.5))));

   floatfunc('a');
   floatfunc(((-(0xFF12))));
   floatfunc((((7.1))));

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   char b = ((0xF4C1));
   char c = (((5.9)));

   printf("%d %d\n", b, c);

   int d = (-9);
   int e = (((3.2)));

   printf("%d %d\n", d, e);

   float f = 'a';
   float g = ((0x8C34E));

   printf("%f %f\n", f, g);

   return (((536870912)));
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
