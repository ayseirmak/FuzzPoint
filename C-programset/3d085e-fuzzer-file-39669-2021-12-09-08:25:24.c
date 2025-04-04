/* corpus/20000731-1.c */
double
foo (void)
{
  return (7.7);
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

   for (x = (0x7); x < (0x41AC81); x++)
      do_sibcall ();
   if (!(x >= (10)))
    { abort (); }
   exit ((0));
}
/* ProgramSourceLLVM */
