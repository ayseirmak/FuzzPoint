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
   charfunc(((-(0x51))));
   charfunc((((8.6))));

   intfunc('a');
   intfunc((-((99))));
   intfunc((((3.6))));

   floatfunc('a');
   floatfunc(((0xDC5E)));
   floatfunc((((7.9))));

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   char b = ((0xD4855B));
   char c = (((8.10)));

   printf("%d %d\n", b, c);

   int d = (0xAE7);
   int e = (((7.2)));

   printf("%d %d\n", d, e);

   float f = 'a';
   float g = ((0xDF923F));

   printf("%f %f\n", f, g);

   return (((268435456)));
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
