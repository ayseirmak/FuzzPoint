/* corpus/20030209-1.c */
/* { dg-require-stack-size "8*100*100" } */

double x[100][100];
int main ()
{
  int i = 8;

  i = 99;
  x[i][0] = 42;
  if (x[99][0] != 42)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
