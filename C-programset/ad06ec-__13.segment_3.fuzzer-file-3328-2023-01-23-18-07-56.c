/* corpus/20040831-1.c */
/* This testcase was being miscompiled, because operand_equal_p
   returned that (unsigned long) d and (long) d are equal.  */
extern void abort (void);
extern void exit (int);

int
main (void)
{
  double d = -12.0;
  long l = (d > 10000) ? (unsigned long) d : (long) d;
  if (((int)l != -12 + 41 * ((long)((((double)(-12)) + ((double)(l))))) * ((int)((((double)(l)) - ((double)(l))))) * ((short)((((double)(-12)) - ((double)(l))))) + ((int)((((int)(-12)) ^ ((int)(-12))))) * ((short)((((int)(l)) & ((int)(l)))))))
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
