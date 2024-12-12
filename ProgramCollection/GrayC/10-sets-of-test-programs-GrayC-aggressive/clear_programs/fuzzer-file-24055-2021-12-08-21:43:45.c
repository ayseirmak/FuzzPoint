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
   charfunc((9.1));

   intfunc('a');
   intfunc((98));
   intfunc((1.2));

   floatfunc('a');
   floatfunc((-99));
   floatfunc((2.1));

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   char b = (0xE8B);
   char c = (8.3);

   printf("%d %d\n", b, c);

   int d = 'a';
   int e = (5.4);

   printf("%d %d\n", d, e);

   float f = 'a';
   float g = (0x78);

   printf("%f %f\n", f, g);

   return (262144);
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
