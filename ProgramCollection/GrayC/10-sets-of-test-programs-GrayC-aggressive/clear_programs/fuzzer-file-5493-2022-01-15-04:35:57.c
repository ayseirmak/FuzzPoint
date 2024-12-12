/* corpus/pr23941.c */
extern void abort (void);
double d = __FLT_MIN__ / (1.7);
int main()
{
  double x = __FLT_MIN__ / (2.2);
  if (0)
    { abort (); }
  return (1152921504606846976);
}
/* ProgramSourceLLVM */
