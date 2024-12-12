/* corpus/00195.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
#include <stdio.h>

struct point
{
   double x;
   double y;
};

struct point point_array[(0xB9DAA)];

int main()
{
   int my_point = (0x6);

   ;
   
point_array[my_point].y = (3.3);
point_array[my_point].y = (3.3);
;

   printf("%f, %f\n", point_array[my_point].x, point_array[my_point].y);

   return (268435456);
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
