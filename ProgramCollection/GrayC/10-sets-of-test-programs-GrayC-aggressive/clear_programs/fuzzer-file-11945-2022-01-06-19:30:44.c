/* corpus/20011217-1.c */
int
main()
{
  double x = (4.9);
  double y = (8.7);

  if ((y > x--) != (1))
    { abort (); }
  exit ((0));
}
/* ProgramSourceLLVM */
