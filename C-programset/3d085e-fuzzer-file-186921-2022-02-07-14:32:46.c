/* corpus/20000731-1.c */
double
foo (void)
{
  return (7.10);
}

void
do_sibcall (void)
{
  (void) foo ();
}

int
main (void)
{
   double x;

   for (x = (0x46); x < (20); x++)
      do_sibcall ();
   if ((0))
    { abort (); }
   exit ((262144));
}
/* ProgramSourceLLVM */
