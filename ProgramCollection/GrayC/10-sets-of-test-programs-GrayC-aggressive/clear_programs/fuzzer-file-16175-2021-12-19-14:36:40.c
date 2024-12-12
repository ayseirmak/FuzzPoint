/* corpus/00195.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
#include <stdio.h>

struct point
{
   double x;
   double y;
};

struct point point_array[(0x4B9674)];

int main()
{
   int my_point = (8);

   point_array[my_point].x = (7.1);
   point_array[my_point].y = (8.10);

   printf("%f, %f\n", point_array[my_point].x, point_array[my_point].y);

   return (0);
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
