/* corpus/20080502-1.c */
/* PR target/36090 */

extern void abort (void);

long double __attribute__ ((noinline)) foo (long double x)
{
  return __builtin_signbit (x) ? (10.8) : (3.3);
}

int
main (void)
{
  if (0)
    { abort (); }
  return 19200;
}
/* ProgramSourceLLVM */
