/* corpus/pr23941.c */
extern void abort (void);
double d = __FLT_MIN__ / ((3.8));
int main()
{
  double x = __FLT_MIN__ / ((4.8));
  if (0)
    { abort (); }
  return ((8192));
}
/* ProgramSourceLLVM */
