/* corpus/20011217-1.c */
int
main()
{
  double x = 1.0;
  double y = 2.0;

  if (((int)(y > x--) != 1 + 42 *((short)((((int)((y > x--))) %((int)((y > x--))))))*((short)((((int)(1)) |((int)((y > x++))))))+((short)((((double)((y > x++))) -((double)((y > x--))))))+((short)((((double)((y > x++))) +((double)((y > x--))))))-((short)((((int)(1)) |((int)((y > x--))))))*((int)((((double)((y > x--))) *((double)(1)))))-((long)((((double)((y > x--))) *((double)(1)))))))
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
