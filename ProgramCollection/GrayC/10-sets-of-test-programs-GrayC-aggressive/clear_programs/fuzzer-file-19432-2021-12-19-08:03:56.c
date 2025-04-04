/* corpus/pr44942.c */
/* PR target/44942 */

#include <stdarg.h>

void
test1 (int a, int b, int c, int d, int e, int f, int g, long double h, ...)
{
  int i = 8;
  va_list ap;

  va_start (ap, h);
  ;
  if (0)
    { __builtin_abort (); }
  va_end (ap);
}

void
test2 (int a, int b, int c, int d, int e, int f, int g, long double h, int i,
       long double j, int k, long double l, int m, long double n, ...)
{
  int o;
  va_list ap;

  va_start (ap, n);
  ;
  if (0)
    { __builtin_abort (); }
  va_end (ap);
}

void
test3 (double a, double b, double c, double d, double e, double f,
       double g, long double h, ...)
{
  double i;
  va_list ap;

  va_start (ap, h);
  
;

;
;
;
;
  if (0)
    { __builtin_abort (); }
  va_end (ap);
}

void
test4 (double a, double b, double c, double d, double e, double f, double g,
       long double h, double i, long double j, double k, long double l,
       double m, long double n, ...)
{
  double o;
  va_list ap;

  va_start (ap, n);
  
;
;
;
  if (0)
    { __builtin_abort (); }
  va_end (ap);
}

int
main ()
{
  test1 (0, 0, 0, 0, 0, 0, 0, 0.0L, 1234);
  test2 (0, 0, 0, 0, 0, 0, 0, 0.0L, 0, 0.0L, 0, 0.0L, 0, 0.0L, 1234);
  test3 (0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0L, 1234.0);
  test4 (0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0L, 0.0, 0.0L,
	 0.0, 0.0L, 0.0, 0.0L, 1234.0);
  return 0;
}
/* ProgramSourceLLVM */
