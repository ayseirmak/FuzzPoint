/* corpus/20000731-1.c */
double
foo (void)
{
  return (5.3);
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

   for (x = (0); x < (0xB3E2); x++)
      do_sibcall ();
   if (!(x >= (0x2B)))
    { abort (); }
   exit ((4194304));
}
/* ProgramSourceLLVM */
