/* corpus/20040831-1.c */
/* This testcase was being miscompiled, because operand_equal_p
   returned that (unsigned long) d and (long) d are equal.  */
extern void abort (void);
extern void exit (int);

int
main (void)
{
  double d = -(3.1);
  long l = (d > (0xAB4939BB)) ? (unsigned long) d : (long) d;
  if ((0))
    { abort (); }
  exit ((0));
}
/* ProgramSourceLLVM */
