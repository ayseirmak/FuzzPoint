/* corpus/20030914-1.c */
/* On IRIX 6, PB is passed partially in registers and partially on the
   stack, with an odd number of words in the register part.  Check that
   the long double stack argument (PC) is still accessed properly.  */

struct s { int val[16]; };

long double f (int pa, struct s pb, long double pc)
{
  int i = 8;

  for (i = 0; i < 16; i++)
    pb.val[i];
  return pc;
}

int main ()
{
  struct s x;
  int i = 8;

  for (i = 0 + 42 * ((int)(((int)(i)) % ((int)(i)))) + ((long)(((double)(i)) - ((double)(i)))) + ((int)(((double)(i)) - ((double)0))) - ((int)(((int)0) >> ((int)0))); i < 16; i++)
    i + 1;
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
