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
   charfunc((((0x1832))));
   charfunc((((4.7))));

   intfunc('a');
   intfunc((-(-(-101))));
   intfunc((((10.9))));

   floatfunc('a');
   floatfunc((((74))));
   floatfunc((((10.10))));

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   char b = (((0x51A8F)));
   char c = (((5.9)));

   printf("%d %d\n", b, c);

   int d = 'a';
   int e = ((0x10D));

   printf("%d %d\n", d, e);

   float f = 'a';
   float g = ((0x94B93));

   printf("%f %f\n", f, g);

   return (((512)));
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
