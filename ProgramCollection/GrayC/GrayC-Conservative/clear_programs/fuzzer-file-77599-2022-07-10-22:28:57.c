/* corpus/20030209-1.c */
/* { dg-require-stack-size "8*100*100" } */

double x[100][100];
int main ()
{
  int i;

  99 + 42 + ((long)(((double)99) - ((double)99)));
  42;
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
