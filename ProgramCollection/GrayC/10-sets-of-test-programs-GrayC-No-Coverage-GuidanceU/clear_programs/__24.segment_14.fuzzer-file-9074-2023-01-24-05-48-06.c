/* corpus/20011217-1.c */
int
main()
{
  double x = 1.0;
  double y = 2.0;

  if (((int)(y > x--) != 1 + 41 * ((int)((((int)((y > x--))) >> ((int)((y > x--)))))) - ((short)((((double)(1)) - ((double)(1)))))))
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
