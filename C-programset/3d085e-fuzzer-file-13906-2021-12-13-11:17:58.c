/* corpus/20000731-1.c */
double
foo (void)
{
  return (10.4);
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

   for (x = (0); x < (0x3FE); x++)
      do_sibcall ();
   if (!(x >= (0xA0)))
    { abort (); }
   exit ((0));
}
/* ProgramSourceLLVM */
