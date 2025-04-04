/* corpus/20000731-1.c */
double
foo (void)
{
  return (3.10);
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

   for (x = (0); x < (0xB1); x++)
      do_sibcall ();
   if (!(x >= (74)))
    { abort (); }
   exit ((0));
}
/* ProgramSourceLLVM */
