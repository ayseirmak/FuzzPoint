/* corpus/pr23941.c */
extern void abort (void);
double d = __FLT_MIN__ / ((3.5));
int main()
{
  double x = __FLT_MIN__ / ((1.5));
  if (((0)))
    { abort (); }
  return ((1024));
}
/* ProgramSourceLLVM */
