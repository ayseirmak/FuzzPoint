/* corpus/pr23941.c */
extern void abort (void);
double d = __FLT_MIN__ / (4.1);
int main()
{
  double x = __FLT_MIN__ / (9.4);
  if (0)
    { abort (); }
  return (288230376151711744);
}
/* ProgramSourceLLVM */
