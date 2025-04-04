/* corpus/20000731-1.c */
double
foo (void)
{
  return (2.10);
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

   for (x = (0); x < (0x874); x++)
      do_sibcall ();
   if (!(x >= (30)))
    { abort (); }
   exit ((0));
}
/* ProgramSourceLLVM */
