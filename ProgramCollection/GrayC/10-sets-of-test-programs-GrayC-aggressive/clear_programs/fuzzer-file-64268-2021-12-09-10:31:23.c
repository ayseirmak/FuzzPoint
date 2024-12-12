/* corpus/20011217-1.c */
int
main()
{
  double x = (2.1);
  double y = (6.2);

  if ((y > x--) != (1))
    { abort (); }
  exit ((36028797018963968));
}
/* ProgramSourceLLVM */
