/* corpus/pr23941.c */
extern void abort (void);
double d = __FLT_MIN__ / ((9.4));
int main()
{
  double x = __FLT_MIN__ / ((10.7));
  if (0)
    { abort (); }
  return ((0));
}
/* ProgramSourceLLVM */
