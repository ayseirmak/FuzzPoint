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
   charfunc((98));
   charfunc((6.1));

   intfunc('a');
   intfunc((98));
   intfunc((3.2));

   floatfunc('a');
   floatfunc((98));
   floatfunc((3.6));

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   char b = (-98);
   char c = (7.1);

   printf("%d %d\n", b, c);

   int d = 'a';
   int e = (7.3);

   printf("%d %d\n", d, e);

   float f = 'a';
   float g = (113);

   printf("%f %f\n", f, g);

   return (268435456);
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
