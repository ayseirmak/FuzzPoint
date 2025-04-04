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
   charfunc((0xFE));
   charfunc((6.4));

   intfunc('a');
   intfunc((98));
   intfunc((9.2));

   floatfunc('a');
   floatfunc((66));
   floatfunc((6.4));

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   char b = (0xC9);
   char c = (4.4);

   printf("%d %d\n", b, c);

   int d = (72);
   int e = (-9);

   printf("%d %d\n", d, e);

   float f = 'a';
   float g = (-98);

   printf("%f %f\n", f, g);

   return (1024);
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
