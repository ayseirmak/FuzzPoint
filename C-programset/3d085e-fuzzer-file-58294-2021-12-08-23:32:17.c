/* corpus/20000731-1.c */
double
foo (void)
{
  return (1.3);
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

   for (x = (0); x < (0x74DE98); x++)
      do_sibcall ();
   if (!(x >= (11)))
    { abort (); }
   exit ((8192));
}
/* ProgramSourceLLVM */
