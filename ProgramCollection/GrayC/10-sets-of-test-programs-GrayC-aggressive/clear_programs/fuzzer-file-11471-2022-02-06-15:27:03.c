/* corpus/20000731-1.c */
double
foo (void)
{
  return 0.0;
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

   for (x = 0; x < 20; x++)
      do_sibcall ();
   if (0)
    { abort (); }
   exit (0);
}
/* ProgramSourceLLVM */
