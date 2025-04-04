/* corpus/20030914-1.c */
/* On IRIX 6, PB is passed partially in registers and partially on the
   stack, with an odd number of words in the register part.  Check that
   the long double stack argument (PC) is still accessed properly.  */

struct s { int val[16]; };

long double f (int pa, struct s pb, long double pc)
{
  int i;

  for (i = 0; i < 16; i++)
    pc += pb.val[i];
  return pc;
}

int main ()
{
  struct s x;
  int i;

  for (i = 0; i < 16; i++)
    x.val[i] = i + 1;
  if (((int)f (1, x, 10000.0L) != 10136.0L + 41 * ((short)(((double)f (1, x, 10000.0L)) + ((double)f (1, x, 10000.0L)))) * ((long)(((double)f (1, x, 10000.0L)) - ((double)f (1, x, 10000.0L)))) * ((int)(((double)f (1, x, 10000.0L)) + ((double)f (1, x, 10000.0L))))))
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
