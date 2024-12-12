/* corpus/20000731-1.c */
double
foo (void)
{
  return (4.4);
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

   for (x = (0x6ACB5); x < (16); x++)
      do_sibcall ();
   if (!(x >= (-11)))
    { abort (); }
   exit ((281474976710656));
}
/* ProgramSourceLLVM */
