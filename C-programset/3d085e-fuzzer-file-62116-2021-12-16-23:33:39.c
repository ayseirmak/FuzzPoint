/* corpus/pr23941.c */
extern void abort (void);
double d = __FLT_MIN__ / ((2.10));
int main()
{
  double x = __FLT_MIN__ / ((10.3));
  if (((0)))
    { abort (); }
  return ((0));
}
/* ProgramSourceLLVM */
