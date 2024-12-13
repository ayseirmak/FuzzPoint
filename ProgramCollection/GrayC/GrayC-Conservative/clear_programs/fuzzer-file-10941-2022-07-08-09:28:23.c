/* corpus/20011217-1.c */
int
main()
{
  double x = 1.0;
  double y = 2.0;

  if (((int)(y > x--) != 1 + 41 * ((int)(((int)1) % ((int)(y > x--)))) + ((int)(((double)(y > x--)) + ((double)1))) * ((long)(((double)1) - ((double)(y > x--)))) * ((short)(((int)(y > x--)) | ((int)(y > x--)))) * ((int)(((double)(y > x--)) * ((double)1)))))
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
