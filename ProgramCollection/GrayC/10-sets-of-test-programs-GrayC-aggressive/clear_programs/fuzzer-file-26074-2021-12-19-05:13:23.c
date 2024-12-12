/* corpus/pr23941.c */
extern void abort (void);
double d = __FLT_MIN__ / (10.4);
int main()
{
  double x = __FLT_MIN__ / (3.6);
  if (0)
    { abort (); }
  return (131072);
}
/* ProgramSourceLLVM */
