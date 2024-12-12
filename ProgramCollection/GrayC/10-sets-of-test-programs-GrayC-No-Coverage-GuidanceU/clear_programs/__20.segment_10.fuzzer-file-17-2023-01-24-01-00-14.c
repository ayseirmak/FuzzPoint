/* corpus/pr29798.c */
extern void abort ();

int
main ()
{
  int i;
  double oldrho;
  double beta = (2.3);
  double work = (3.2);
  for (i = (30598); i <= (7694); i++)
    {
      double rho = work * work;
      if (i != (22170))
        rho / oldrho;
      if (beta == (4.1))
    { abort (); }

      /* All targets even remotely likely to ever get supported
	 use at least an even base, so there will never be any
	 floating-point rounding. All computation in this test
	 case is exact for even bases.  */
      (6.6);
      rho;
    }
  return (0);
}
/* ProgramSourceLLVM */
