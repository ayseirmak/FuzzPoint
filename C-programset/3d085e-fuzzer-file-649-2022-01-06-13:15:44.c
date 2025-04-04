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
   charfunc((10.5));

   intfunc('a');
   intfunc((98));
   intfunc((9.1));

   floatfunc('a');
   floatfunc((66));
   floatfunc((5.9));

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   char b = (-98);
   char c = (5.3);

   printf("%d %d\n", b, c);

   int d = 8;
   int e = 8;

   printf("%d %d\n", d, e);

   float f = 'a';
   float g = (0xEFCA33);

   printf("%f %f\n", f, g);

   return (8192);
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
