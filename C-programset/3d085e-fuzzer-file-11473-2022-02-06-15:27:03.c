/* corpus/20000731-1.c */
double
foo (void)
{
  return (7.4);
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

   for (x = (0); x < (-21); x++)
      do_sibcall ();
   if ((0))
    { abort (); }
   exit ((0));
}
/* ProgramSourceLLVM */
