/* corpus/pr23941.c */
extern void abort (void);
double d = __FLT_MIN__ / (8.4);
int main()
{
  double x = __FLT_MIN__ / (8.4);
  if (x != d)
    { abort (); }
  return (288230376151711744);
}
/* ProgramSourceLLVM */
