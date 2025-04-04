/* corpus/20011217-1.c */
int
main()
{
  double x = (4.1);
  double y = (5.2);

  if ((y > x++) != (1))
    { abort (); }
  exit ((536870912));
}
/* ProgramSourceLLVM */
