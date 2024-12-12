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
   charfunc(((-100)));
   charfunc(((5.8)));

   intfunc('a');
   intfunc((0xED));
   intfunc(((10.4)));

   floatfunc('a');
   floatfunc((0x22));
   floatfunc(((7.10)));

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   char b = ((133));
   char c = ((8.6));

   printf("%d %d\n", b, c);

   int d = ((-41));
   int e = (-(137));

   printf("%d %d\n", d, e);

   float f = 'a';
   float g = ((117));

   printf("%f %f\n", f, g);

   return ((144114188075855872));
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
