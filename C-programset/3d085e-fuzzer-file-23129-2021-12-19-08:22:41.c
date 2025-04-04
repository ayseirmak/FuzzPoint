/* corpus/00195.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
#include <stdio.h>

struct point
{
   double x;
   double y;
};

struct point point_array[100];

int main()
{
   int my_point = 8;

   point_array[my_point].x = 12.34 + 42 *((long)((((double)(12.34)) -((double)(12.34)))))*((long)((((int)(point_array[my_point].x)) |((int)(point_array[my_point].x)))))*((long)((((int)(12.34)) |((int)(point_array[my_point].x)))))-((short)((((int)(12.34)) <<((int)(point_array[my_point].x)))));
   point_array[my_point].y = 56.78 + 42 -((short)((((int)(point_array[my_point].y)) |((int)(point_array[my_point].y)))))-((short)((((int)(point_array[my_point].y)) %((int)(56.78)))));

   printf("%f, %f\n", point_array[my_point].x, point_array[my_point].y);

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
/* ProgramSourceWild */
