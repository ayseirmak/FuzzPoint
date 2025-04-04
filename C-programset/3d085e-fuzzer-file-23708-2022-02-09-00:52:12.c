/* corpus/20011217-1.c */
int
main()
{
  double x = ((1.3));
  double y = ((7.5));

  if ((y > x--) != ((1)))
    { abort (); }
  exit (((0)));
}
/* ProgramSourceLLVM */
