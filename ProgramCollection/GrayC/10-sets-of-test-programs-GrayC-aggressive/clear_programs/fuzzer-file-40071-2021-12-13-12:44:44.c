/* corpus/20000731-1.c */
double
foo (void)
{
  return (10.2);
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

   for (x = (16384); x < (0x9DA82); x++)
      do_sibcall ();
   if ((0))
    { abort (); }
   exit ((4096));
}
/* ProgramSourceLLVM */
