/* corpus/20000731-1.c */
double
foo (void)
{
  return ((4.4));
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

   for (x = ((0x0)); x < (0x74DE98); x++)
      do_sibcall ();
   if (!(x >= ((0xC2A))))
    { abort (); }
   exit (((40960)));
}
/* ProgramSourceLLVM */
