/* corpus/00195.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
#include <stdio.h>

struct point
{
   double x;
   double y;
};

struct point point_array[(0x3F08F1)];

int main()
{
   int my_point = (0xD);

   ;
   ;

   printf("%f, %f\n", point_array[my_point].x, point_array[my_point].y);

   return (0);
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
